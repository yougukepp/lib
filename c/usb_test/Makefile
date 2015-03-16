
all:
	#/opt/toolchains/crosstools-mips-gcc-4.6-linux-3.4-uclibc-0.9.32-binutils-2.21/usr/bin/mips-unknown-linux-uclibc-gcc -std=c99 usb_test.c -o usb_test
	#/opt/toolchains/crosstools-mips-gcc-4.6-linux-3.4-uclibc-0.9.32-binutils-2.21/usr/bin/mips-unknown-linux-uclibc-strip usb_test
	#mv usb_test /home/pp/68380/
	gcc -std=c99 usb_test.c -o usb_test
	./usb_test 1048576000
	

clean:
	rm -rf usb_test
	rm -rf pp.r
