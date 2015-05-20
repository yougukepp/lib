# 如果 KERNELRELEASE 定义
# 我们是在内核中编译 使用内核Makefile语法
ifneq ($(KERNELRELEASE),)
	obj-m := hello.o 
# 在普通命令行编译
else
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd) 

default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

clean: 
	rm -rvf hello.ko hello.mod.o hello.o hello.mod.c modules.order Module.symvers .hello.ko.cmd .hello.o.cmd .hello.mod.o.cmd .tmp_versions/
endif 
