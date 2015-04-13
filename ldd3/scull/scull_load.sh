#!/bin/sh

module="scull"
device="scull"
mode="666"

# 加载模块
sudo /sbin/insmod ./$module.ko $* || exit 1

# 删除原有节点
sudo rm -f /dev/${device}

major=$(awk "\$2==\"$module\" {print \$1}" /proc/devices)

sudo mknod /dev/${device} c $major 0

# 设置权限
group="staff"
grep -q '^staff:' /etc/group || group="wheel"

sudo chgrp $group /dev/${device}
sudo chmod $mode /dev/${device}

