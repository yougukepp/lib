include 	../../buildvars

OBJS = GisEgl.o GisProgram.o GisShader.o

all:$(OBJS)

$(OBJS): %.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf *.o

