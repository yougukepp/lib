include ../buildvars

all:lib

lib:factorial.o fibonacci.o
	cp *.o ../lib

factorial.o:factorial.c
	$(CC) factorial.c -o factorial.o

fibonacci.o:fibonacci.c
	$(CC) fibonacci.c -o fibonacci.o

clean:
	${RM} *.o
