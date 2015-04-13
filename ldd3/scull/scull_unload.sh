#!/bin/sh

module="scull"
device="scull"

# 加载模块
/sbin/rmmod ./$module.ko $* || exit 1

# 删除原有节点
rm -f /dev/${device}

