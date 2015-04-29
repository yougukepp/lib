TARGET_MACHINE=20

SO=/home/pp/UPLINK_GPON/trunk/src/modules/bsp/bsp_uplink/user/libonu_bsp.so
PREFIX=/opt/toolchains/crosstools-mips-gcc-4.6-linux-3.4-uclibc-0.9.32-binutils-2.21/usr/bin/mips-unknown-linux-uclibc-

LFLAGS = -Wall -O2 -pedantic -std=c99
LD = $(PREFIX)gcc

CC=$(PREFIX)gcc
CFLAGS=-c $(LFLAGS) -I/home/pp/UPLINK_GPON/trunk/src/modules/bsp/bsp_uplink/user/

RM = rm -rf
STRIP = $(PREFIX)strip

all:gpio_test

gpio_test:clean gpio_test.c
	$(CC) $(CFLAGS) gpio_test.c -o gpio_test.o
	$(LD) $(LFLAGS) $(SO) gpio_test.o -o gpio_test
	$(STRIP) gpio_test
	mv gpio_test /home/pp/lrz/
	make clean
	
clean:
	$(RM) gpio_test *.so *.o

.PHONY : clean 


