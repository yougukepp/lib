include 	../../buildvars

OBJS = GisLines.o GisPoint.o GisColor.o GisProgram.o GisShader.o

all:$(OBJS)

$(OBJS): %.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf *.o

