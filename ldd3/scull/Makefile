# 如果 KERNELRELEASE 定义
# 我们是在内核中编译 使用内核Makefile语法
ifneq ($(KERNELRELEASE),)
	obj-m := scull.o 
# 在普通命令行编译
else
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd) 

default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

clean: 
	rm -rvf scull.ko scull.mod.o scull.o scull.mod.c modules.order Module.symvers .scull.ko.cmd .scull.o.cmd .scull.mod.o.cmd .tmp_versions/ *.txt
endif 
