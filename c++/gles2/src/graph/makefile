include 	../../buildvars

GIS_LINES_SRC			= GisLines.cpp
GIS_LINES_OBJ			= GisLines.o

GIS_POINT_SRC			= GisPoint.cpp
GIS_POINT_OBJ			= GisPoint.o

GIS_COLOR_SRC			= GisColor.cpp
GIS_COLOR_OBJ			= GisColor.o

GIS_PROGRAM_SRC 		= GisProgram.cpp
GIS_PROGRAM_OBJ 		= GisProgram.o

GIS_SHADER_SRC			= GisShader.cpp
GIS_SHADER_OBJ 			= GisShader.o

OBJS           			= $(GIS_LINES_OBJ) $(GIS_POINT_OBJ) $(GIS_PROGRAM_OBJ) $(GIS_SHADER_OBJ) $(GIS_COLOR_OBJ)

all:$(OBJS)

$(GIS_LINES_OBJ): $(GIS_LINES_SRC)
	$(CC) -c $(GIS_LINES_SRC) -o $(GIS_LINES_OBJ) $(CFLAGS)

$(GIS_POINT_OBJ): $(GIS_POINT_SRC)
	$(CC) -c $(GIS_POINT_SRC) -o $(GIS_POINT_OBJ) $(CFLAGS)

$(GIS_COLOR_OBJ): $(GIS_COLOR_SRC)
	$(CC) -c $(GIS_COLOR_SRC) -o $(GIS_COLOR_OBJ) $(CFLAGS)

$(GIS_PROGRAM_OBJ): $(GIS_PROGRAM_SRC)
	$(CC) -c $(GIS_PROGRAM_SRC) -o $(GIS_PROGRAM_OBJ) $(CFLAGS)

$(GIS_SHADER_OBJ): $(GIS_SHADER_SRC)
	$(CC) -c $(GIS_SHADER_SRC) -o $(GIS_SHADER_OBJ) $(CFLAGS)

clean:
	rm -rf *.o

