include 	../../buildvars

OBJS = QgColor.o QgPrimitive.o QgPoint.o QgSpritePoint.o # QgLine.o QgTriangle.o

all:$(OBJS)

$(OBJS): %.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf *.o

