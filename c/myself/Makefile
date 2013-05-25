include ../buildvars

all:lib

lib:print.o getRangeRand.o
	cp *.o ../lib

print.o:print.c
	$(CC) print.c -o print.o


getRangeRand.o:getRangeRand.c
	$(CC) getRangeRand.c -o getRangeRand.o

clean:
	${RM} *.o
	${RM} *.so
