include 	../../buildvars

OBJS = QgColor.o QgPoint.o QgPrimitive.o\
       QgSpritePoints.o\
       QgBaseLine.o QgLines.o QgLineStrip.o QgLineLoop.o\
       QgTriangles.o QgTriangleStrip.o QgTriangleFan.o

all:$(OBJS)

$(OBJS): %.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf *.o

