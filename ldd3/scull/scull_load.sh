#!/bin/sh

module="scull"
device="scull"
mode="666"

# 加载模块
/sbin/insmod ./$module.ko $* || exit 1

# 删除原有节点
rm -f /dev/${device}

major=$(awk "\$2==\"$module\" {print \$1}" /proc/devices)

mknod /dev/${device} c $major 0

# 设置权限
group="staff"
grep -q '^staff:' /etc/group || group="wheel"

chgrp $group /dev/${device}
chmod $mode /dev/${device}

