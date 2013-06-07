include 	../../buildvars

OBJS = egl.o

all:$(OBJS)

$(OBJS): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf *.o

