include 	../../buildvars

OBJS = QgColor.o QgPoint.o QgPrimitive.o QgSpritePoints.o QgLines.o QgLineStrip.o QgTriangles.o

all:$(OBJS)

$(OBJS): %.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf *.o

