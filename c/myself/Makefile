include ../buildvars
OBJS = print.o getRangeRand.o randomPi.o

all:lib

lib:$(OBJS)
	cp *.o ../lib

$(OBJS): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	${RM} *.o

