include 	../../buildvars

OBJS = GisLines.o GisPoint.o GisColor.o GisPolygon.o GisRect.o GisCircle.o GisArc.o GisChord.o GisPie.o GisOval.o GisPrimitives.o GisTriangles.o

all:$(OBJS)

$(OBJS): %.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf *.o

