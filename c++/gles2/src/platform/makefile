include 	../../buildvars

OBJS = QgEgl.o QgProgram.o QgShader.o

all:$(OBJS)

$(OBJS): %.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf *.o

