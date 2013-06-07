include 	../../buildvars

OBJS = glu3.o fslutil.o egl.o shader.o utils.o

all:$(OBJS)

$(OBJS): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf *.o

