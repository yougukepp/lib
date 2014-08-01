CC=gcc
CFLAGS=-Wall -Os
#CFLAGS=-Wall -ggdb

%.o : %.c
	$(CC) -o $@ $(CFLAGS) -c $< 

.PHONY: all strip diet clean

all: mattows
	mv mattows ../www/

mattows: mattows.o
	$(CC) $(LDFLAGS) -o$@ $<

diet: CC=diet gcc
diet: all
	strip mattows

tiny tinystrip tinydiet: CFLAGS=-Wall -Os -DREALLYTINY
tiny: all
tinystrip: tiny
	strip mattows
tinydiet: diet

clean:
	rm -f ../www/mattows
	rm -f mattows *.o
	rm -f *.log

# $Id: Makefile,v 1.2 2006/06/28 23:22:06 mb Exp mb $
