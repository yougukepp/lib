include 	../../buildvars

OBJS = GisPolygon.o GisRect.o GisCircle.o GisArc.o GisChord.o GisPie.o GisOval.o

all:$(OBJS)

$(OBJS): %.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf *.o

