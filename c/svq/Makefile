LD=gcc
LFLAGS=-Wall -O2 -pedantic -std=c99 -D_XOPEN_SOURCE -DSVQ_DEBUG

CC=gcc
CFLAGS=-c $(LFLAGS)

RM=rm -rf

all: clean
	$(LD) $(LFLAGS) server.c -o server
	$(LD) $(LFLAGS) client.c -o client 

clean:
	${RM} *.o
	${RM} *.exe
	${RM} server client

