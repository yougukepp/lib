/* mattows.c
 * msbethke 2006
 * A quick'n'dirty HTTP server that can deliver HTML, GIF, JPEG,
 * PNG and CSS, and executes CGI files ending in ".cgi"
 *
 * NEW: goes daemon on `-d' argument; default port is 28001
 * 
 * TODO: support POST method (only GET and HEAD so far); proper commandline
 * parsing
 *
 * $Id: mattows.c,v 1.8 2006/07/04 21:55:46 mb Exp mb $
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <stdarg.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <dirent.h>

#define _STRINGIFY(x) #x

#define LOGFILENAME "mattows.log"
#define PORT 28001
#define PORTSTR _STRINGIFY(PORT)

/* write an HTTP message (or any string) to a file descriptor */
#define HTTPMSG(fh,msg) fputs((msg),(fh))

/* Determine elements in an array */
#define NELEMS(x) (sizeof(x)/sizeof(*x))

/* some HTML stuff for dir listings */
#define DIR_DOCTYPE "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\n"
#define DIR_HEAD1 "<html>\n<head><title>"
#define DIR_HEAD2 "</title></head>\n<body>\n<ul style=\"list-style-type:none\">\n"
#define DIR_FOOT  "</ul>\n</body>\n</html>"
#define DIR_ENT1  "<li><a href=\""
#define DIR_ENT2  "\">"
#define DIR_ENT3  "</a></li>\n"
#define DIR_DIRMARK "[DIR]&nbsp;"

typedef enum {false=0,true} bool;
enum {ENVSIZE=20};
typedef struct MYENV {
	int nenv;
	char *ptrs[ENVSIZE];
} myenv;

typedef struct EXT2MIME {
	const char *type;
	const char* const ext[];
} ext2mime;
typedef enum {M_INVALID=0, M_GET=1, M_HEAD=2} reqtype;

static const ext2mime ext_html = {"text/html",{"html","htm",NULL}};
static const ext2mime ext_gif  = {"image/gif",{"gif",NULL}};
static const ext2mime ext_png  = {"image/png",{"png",NULL}};
static const ext2mime ext_jpeg = {"image/jpeg",{"jpg","jpeg","jfif",NULL}};
static const ext2mime ext_css  = {"text/css",{"css",NULL}};
static const ext2mime* const extensions[] = {
	&ext_html, &ext_gif, &ext_png, &ext_jpeg, &ext_css, NULL
};
static const char* const cgiext[] = {"cgi","py","sh"};
static const char MIME_GENERIC[] = "application/ocet-stream";

static char *method_strings[3];
static char *progname, *addrstr, *portstr = PORTSTR;
static in_addr_t addr;
static short port = PORT;
static myenv cgienv = {
	3,{
		"SERVER_SOFTWARE=mattows",
		"GATEWAY_INTERFACE=CGI/1.2",
		"SERVER_PROTOCOL=HTTP/1.0"
	}
};
static bool daemonize = false;

/* HTTP codes */
const char HTTPV[] = "HTTP/1.0 ";
const char M200[] = "200 OK\r\n";
const char E400[] = "400 Bad request\r\n";
const char E404[] = "404 Not found\r\n";
const char E403[] = "403 Forbidden\r\n";
const char E501[] = "501 Not implemented\r\n";

#ifdef REALLYTINY /* avoid use of printf */

/* program usage */
static void usage(void)
{
	fputs("Usage: ",stderr);
	fputs(progname,stderr);
	fputs("[-d] <ip> [port]\n",stderr);
	exit(EXIT_FAILURE);
}

static void mywarn(char *s, ...) { }
static void myerror(int code, char *s, ...)
{
	fputs("ABEND\n",stderr);
	exit(code);
}
#else
/* program usage */
static void usage(void)
{
	fprintf(stderr,"Usage: %s [-d] [ip] <port>\n",progname);
	exit(EXIT_FAILURE);
}

/* print message in arglist */
static void vmywarn(char *s, va_list ap)
{
	fprintf(stderr,"%s [%d]: ",progname,(int)getpid());
	vfprintf(stderr,s,ap);
}

/* print message in varargs */
static void mywarn(char *s, ...)
{
	va_list ap;
	va_start(ap,s);
	vmywarn(s,ap);
	va_end(ap);
}

/* print message in varargs and exit with error code */
static void myerror(int code, char *s, ...)
{
	va_list ap;
	va_start(ap,s);
	vmywarn(s,ap);
	va_end(ap);
	exit(code);
}
#endif /* REALLYTINY */

/* get hostname for an IP4 address in network byte order */
static char *getmyhostname(in_addr_t addr)
{
	enum {AUXBUFSIZE=1024};
	struct in_addr ad;
	struct hostent he, *hp;
	int err;
	char *auxbuf;
	
	ad.s_addr = addr;
	/* auxbuf is unused anyway, so ignore ERANGE */
	if(!(auxbuf=alloca(AUXBUFSIZE)) ||
			/* this will probably break on Solaris */
			gethostbyaddr_r((void*)&ad,sizeof(ad),AF_INET,
				&he,auxbuf,AUXBUFSIZE,&hp,&err) ||
			!hp)
		return "(no-hostname)";
	return he.h_name;
}

/* evaluate arguments to global vars
 * TODO: this is getting big. might as well do it properly...
 */
static void eval_args(int c, char *v[])
{
	int n=1;

	while(1) {
		if(c <= n)
			usage();
		if('-' != v[n][0])
			break;
		switch(v[n][1]) {
			case 'h' :
				usage();
			case 'd' :
				daemonize = true;
				break;
			default :
				myerror(EXIT_FAILURE,"unknown option %s\n",v[n]);
		}
		++n;
	}
	
	addr = inet_addr(v[n]);
	if(INADDR_NONE == addr) {
		/* address parsing failed, assume it's a port */
		addr = INADDR_ANY;
		addrstr = getmyhostname(htonl(0x7f000001));
	} else {
		++n;
		addrstr = getmyhostname(addr);
	}
	if(c <= n)
		return;
	port = atoi(portstr = v[n]);
	mywarn("ADDR: %s; PORT: %hd\n",addrstr,port);
	if(!port)
		usage();
}

static void send_ok_mime(FILE *to, const char *mimetype)
{
	HTTPMSG(to,M200);
	HTTPMSG(to,"Content-Type: ");
	HTTPMSG(to,mimetype);
	HTTPMSG(to,"\r\n\r\n");
}

static int entrymode(char *path)
{
	struct stat st;

	if(0 != stat(path,&st))
		return 0;
	return st.st_mode;
}

/* send <dir> in primitive HTML to <to> */
static int send_dir(char *dir, FILE *to)
{
	int ret = EXIT_FAILURE;
	DIR *dh = opendir(dir);
	struct dirent *de;
	if(NULL == dh) {
		/* diretory failed to open */
		HTTPMSG(to,E404);
		return ret;
	}
	send_ok_mime(to,ext_html.type);
	HTTPMSG(to,DIR_DOCTYPE DIR_HEAD1);
	HTTPMSG(to,dir);
	HTTPMSG(to,DIR_HEAD2);
	errno = 0;
	while(NULL != (de = readdir(dh))) {
		int type;
		char *name = de->d_name;
		if(('.' == name[0]) && ('\0' == name[1]))
			continue;
		type = entrymode(name);
		if(!(S_ISDIR(type) || S_ISREG(type)))
			continue;	/* ignore stuff that isn't regular file or dir */
		HTTPMSG(to,DIR_ENT1);
		HTTPMSG(to,name);
		if(S_ISDIR(type))
			HTTPMSG(to,"/");
		HTTPMSG(to,DIR_ENT2);
		if(S_ISDIR(type))
				HTTPMSG(to,DIR_DIRMARK);
		HTTPMSG(to,name);
		HTTPMSG(to,DIR_ENT3);
	}
	HTTPMSG(to,DIR_FOOT);
	if(errno)
		mywarn("Could not send dir: %s\n",strerror(errno));
	else
		ret = EXIT_SUCCESS;
	return ret;
}

/* Read from file named <from>, write to FH <to> adding MIME header */
static int send_file(char *from, FILE *to, const char *mimetype)
{
	char buf[4096];
	int writing=1, file, rdsize,ret = EXIT_FAILURE;
	
	file = open(from,O_RDONLY);
	/* check if file opened, 403 if not */
	if(-1 != file) {
		mywarn("Sending %s\n",from);
		HTTPMSG(to,M200);
		HTTPMSG(to,"Content-Type: ");
		HTTPMSG(to,mimetype);
		HTTPMSG(to,"\r\n\r\n");
		while(writing) {
			switch(rdsize = read(file,buf,sizeof(buf))) {
				case -1:
					mywarn("read error on %s: %s\n",from,strerror(errno));
					ret = EXIT_FAILURE;
					/* fallthru */
				case 0:
					writing = 0;
					break;
				default :
					fwrite(buf,1,rdsize,to);
			}
		}
		close(file);
	} else {
		mywarn("error opening \"%s\": %s\n",from,strerror(errno));
		HTTPMSG(to,E403);
	}
	return ret;
}

/* enter a new string for a KEY=VALUE environment entry into
 * the env array
 */
static void addenv(myenv *env, char *key, char *val)
{
	char *s;
	int keylen = strlen(key);
	int vallen = strlen(val);
	if((s = malloc(keylen + 1 + vallen + 1))) {
		strcpy(s,key);
		s[keylen] = '=';
		strcpy(s+keylen+1,val);
		env->ptrs[env->nenv++] = s;
	}
}

/* build an env array for CGIs */
static char **buildenv(myenv *env,
		reqtype method,
		char *scriptname,
		char *query,
		char *peer)
{
	addenv(env,"REQUEST_METHOD",method_strings[method]);
	// addenv(env,"PATH_INFO","");
	// addenv(env,"PATH_TRANSLATED","");
	addenv(env,"SCRIPT_NAME",scriptname);
	// addenv(env,"REMOTE_HOST","");
	addenv(env,"REMOTE_ADDR",peer);
	if(query)
		addenv(env,"QUERY_STRING",query);
	return env->ptrs;
}

static reqtype check_reqtype(char *req)
{
	if(!strncmp("GET",req,3)) return M_GET;
	if(!strncmp("HEAD",req,4)) return M_HEAD;
	return M_INVALID;
}

static void handle_cgi(char *prog, char *query, reqtype method,
		FILE *out, struct  sockaddr_in *peer)
{
	char *args[2] = {0};
	int pid;
	int pipefds[2];
	FILE *pipefh;
	mywarn("Executing %s\n",prog);
	args[0] = prog;
	HTTPMSG(out,M200);
	fflush(out);
	buildenv(&cgienv,method,prog,query,inet_ntoa(peer->sin_addr));
	switch(method) {
		case M_HEAD :
			if(0 != pipe(pipefds)) {
				myerror(EXIT_FAILURE,"pipe(): %s",strerror(errno));
				break;
			}
			switch(pid = fork()) {
				char buf[4096];

				case -1 :
					myerror(EXIT_FAILURE,
							"error forking CGI process: %s\n",strerror(errno));
					break;
				case 0 :
					dup2(pipefds[1],1);
					execve(prog,args,cgienv.ptrs);
					break; /* yeah right... */
				default :
					pipefh = fdopen(pipefds[0],"r");
					while(fgets(buf,sizeof(buf),pipefh)) {
						fputs(buf,out);
						if('\r' == buf[0] && '\n' == buf[1])
							break;
					}
					fclose(pipefh);
			}
			break;

		case M_GET:
		default:
			dup2(fileno(out),1);
			execve(prog,args,cgienv.ptrs);
			break;
	}
}

static const char *find_mime_type(char *buf)
{
	const ext2mime *e2m;
	int i,j;
	for(i=0; (e2m=extensions[i]); ++i)
		for(j=0; e2m->ext[j]; ++j)
			if(!strcasecmp(buf,e2m->ext[j]))
				return e2m->type;
	return MIME_GENERIC;
}

/* read HTTP request and respond */
static int handle_connection(int fd, struct sockaddr_in *peer)
{
	char buf[4096];
	char *uri, *doc, *t, *query=NULL;
	struct stat st;
	int ret = EXIT_FAILURE;
	reqtype method;
	FILE *fh = fdopen(fd,"r+");

	if(!fh) return ret;		/* very bad, don't bother with messages */
	

	/* check for valid request: fgets() ok && 5<=req<=sizeof(buf) */
	if(fgets(buf,sizeof(buf),fh) && strlen(buf) >= 5 &&
			!(strlen(buf) >= sizeof(buf)-2 && '\0' != buf[sizeof(buf)-1])) {

		/* ignore rest of request for now */
		do {
			char dummy[4096];
			while(fgets(dummy,sizeof(dummy),fh)) {
				if('\r' == dummy[0] && '\n' == dummy[1])
					break;
			}
		} while(0);

		/* write HTTP version for reply */
		fputs(HTTPV,fh);
	
		switch(method = check_reqtype(buf)) {
			case M_GET :
				uri = buf + 4;
				break;
			case M_HEAD:
				uri = buf + 5;
				break;
			default :
				HTTPMSG(fh,E501);
				goto leave;
		}
		doc = uri;
		/* skip leading '/' */
		*doc == '/' && ++doc;
		/* zero-terminate document name, get optional query string */
		for(t=doc; *t && !isspace(*t); ++t) {
			if('?' == *t) {
				query = t+1;
				break;
			}
		}
		*t = '\0';
		/* if a query part is present, it still needs to be terminated */
		if(query) {
			for(++t; *t && !isspace(*t); ++t) /* just loop */ ;
			*t = '\0';
		}
		/* top dir must be "." */
		if(!strlen(doc))
			doc = ".";
		/* check if requested file/script exists, 404 if not */
		if(0 == stat(doc,&st)) {
			char const *mimetype = MIME_GENERIC;
			/* check for directory */
			if(S_ISDIR(st.st_mode)) {
				ret = send_dir(doc,fh);
				goto leave;
			}
			/* find file extension and infer MIME type */
			char *ext = strrchr(doc,'.');
			if(ext) {
				int i;
				/* check for CGI script */
				++ext;
				for(i=0; i<NELEMS(cgiext); ++i) {
					if(!strcasecmp(cgiext[i],ext)) {
						handle_cgi(doc,query,method,fh,peer);
						return EXIT_SUCCESS;		/* we only get back here for HEAD! */
					}
				}
				/* delivery only */
				mimetype = find_mime_type(ext);
			}
			/* can only use GET on plain files */
			if(M_GET == method) ret = send_file(doc,fh,mimetype);
			else HTTPMSG(fh,E400);
		} else {
			mywarn("File not found: '%s'\n",doc);
			HTTPMSG(fh,E404);
		}
	} else {
		fputs(HTTPV,fh);
		HTTPMSG(fh,E400);
	}
leave:
	fclose(fh);
	return ret;
}

/* clean up dead children */
static void child_reaper(int sig)
{
	int status, pid;

	while(0 < (pid = waitpid(-1,&status,WNOHANG)))
		mywarn("Child process %d exited with status %d\n",pid,status);
}

/* do some work */
int main(int argc, char *argv[])
{
	int sock,as,sockopt=1;
	struct sockaddr_in bindaddr, peer;
	struct sigaction sa = {
		.sa_handler = &child_reaper,
		.sa_flags = SA_NOCLDSTOP
	};

	/* basename($0) */
	progname = argv[0] + strlen(argv[0]);
	while((progname > argv[0]) && (progname[-1] != '/'))
		--progname;
	eval_args(argc,argv);
	port = htons(port);

	/* set up method-to-string translation table */
	method_strings[M_INVALID]	= "INVALID";
	method_strings[M_GET]		= "GET";
	method_strings[M_HEAD]		= "HEAD";
	
	sock = socket(AF_INET,SOCK_STREAM,0);
	if(-1 == sock)
		myerror(EXIT_FAILURE,"socket: %s\n",strerror(errno));	
	setsockopt(sock,getprotobyname("tcp")->p_proto,
			SO_REUSEADDR,&sockopt,sizeof(sockopt));
	bindaddr.sin_family = PF_INET;
	bindaddr.sin_port = port;
	bindaddr.sin_addr.s_addr = addr;
	if(-1 == bind(sock,(struct sockaddr*)&bindaddr,sizeof(bindaddr)))
		myerror(EXIT_FAILURE,"bind: %s\n",strerror(errno));
	
	if(daemonize) {
		pid_t daemon = fork();
		if(-1 == daemon)
			myerror(EXIT_FAILURE,"cannot daemonize: %s\n",strerror(errno));
		/* forked successfully, exit parent */
		if(daemon)
			exit(EXIT_SUCCESS);
		/* child continues */
		umask(0);
		stderr = freopen(LOGFILENAME,"a+",stderr);
		setlinebuf(stderr);
		if(0 == stderr)
			myerror(EXIT_FAILURE,"cannot open log \"%s\": %s\n",
					LOGFILENAME,strerror(errno));
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		setsid(); /* should always succeed in child */
	}
	
	listen(sock,10);

	sigaction(SIGCHLD,&sa,NULL);

	/* fill constant elements in CGI's env array already */
	addenv(&cgienv,"SERVER_NAME",addrstr);
	addenv(&cgienv,"SERVER_PORT",portstr);
	
	while(1) {
		int pid;
		socklen_t peerlen=sizeof(peer);
		
		mywarn("Waiting for connections on port %d\n",ntohs(port));
		as = accept(sock,(struct sockaddr*)&peer,&peerlen);
		if(-1 == as) {
			if(EINTR != errno)
				mywarn("accept: %s\n",strerror(errno));
			continue;
		}
		switch(pid = fork()) {
			case -1 :
				mywarn("error forking connection handler: %s\n",strerror(errno));
				break;
			case 0 :
				close(sock);
				mywarn("Accepted connection from %s:%d\n",
						inet_ntoa(peer.sin_addr),ntohs(peer.sin_port));
				exit(handle_connection(as,&peer));
			default :
				close(as);
		}
	}
	close(sock);
	return EXIT_SUCCESS;
}

/* vi: set ts=3 sw=3 noet cindent: */
