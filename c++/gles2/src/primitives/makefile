include 	../../buildvars

OBJS = GisLines.o GisPoint.o GisColor.o GisPrimitives.o GisTriangles.o

all:$(OBJS)

$(OBJS): %.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf *.o

