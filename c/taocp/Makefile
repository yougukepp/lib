include ../buildvars
OBJS = gcd.o sampling.o

all:lib

lib:$(OBJS)
	cp *.o ../lib

$(OBJS): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	${RM} *.o
	${RM} *.so

