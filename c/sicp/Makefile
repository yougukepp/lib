include ../buildvars

OBJS = factorial.o fibonacci.o

all:lib

lib:$(OBJS)
	cp *.o ../lib

$(OBJS): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	${RM} *.o

