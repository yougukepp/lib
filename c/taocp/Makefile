include ../buildvars

all:lib

lib:gcd.o sampling.o
	cp *.o ../lib

gcd.o:gcd.c
	$(CC) gcd.c -o gcd.o


sampling.o:sampling.c
	$(CC) sampling.c -o sampling.o

clean:
	${RM} *.o
	${RM} *.so
