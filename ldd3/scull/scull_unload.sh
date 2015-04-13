#!/bin/sh

module="scull"
device="scull"

# 加载模块
sudo /sbin/rmmod ./$module.ko $* || exit 1

# 删除原有节点
sudo rm -f /dev/${device}

