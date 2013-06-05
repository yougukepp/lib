include 	../../buildvars

GLU_SRC		= glu3.c
GLU_OBJ		= glu3.o

FSLUTIL_SRC	= fslutil.c
FSLUTIL_OBJ	= fslutil.o

EGL_SRC	        = egl.c
EGL_OBJ         = egl.o

SHADER_SRC      = shader.c
SHADER_OBJ      = shader.o

UTILS_SRC      = utils.c
UTILS_OBJ      = utils.o

OBJS_FSL       = $(GLU_OBJ) $(FSLUTIL_OBJ)
OBJS           = $(EGL_OBJ) $(SHADER_OBJ) $(UTILS_OBJ) $(OBJS_FSL)


all:$(OBJS)

$(EGL_OBJ): $(EGL_SRC)
	echo $(CFLAGS)
	$(CC) -c $(EGL_SRC) -o $(EGL_OBJ) $(CFLAGS)

$(SHADER_OBJ): $(SHADER_SRC)
	$(CC) -c $(SHADER_SRC) -o $(SHADER_OBJ) $(CFLAGS)

$(UTILS_OBJ): $(UTILS_SRC)
	$(CC) -c $(UTILS_SRC) -o $(UTILS_OBJ) $(CFLAGS)

$(GLU_OBJ): $(GLU_SRC)
	$(CC) -c $(GLU_SRC) -o $(GLU_OBJ) $(CFLAGS)

$(FSLUTIL_OBJ): $(FSLUTIL_SRC)
	$(CC) -c $(FSLUTIL_SRC) -o $(FSLUTIL_OBJ) $(CFLAGS)

clean:
	rm -rf *.o

