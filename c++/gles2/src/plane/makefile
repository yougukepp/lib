include 	../../buildvars

OBJS = QgPolygon.o


all:$(OBJS)

$(OBJS): %.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf *.o

