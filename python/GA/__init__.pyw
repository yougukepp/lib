#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from PyQt4.QtGui import *
from PyQt4.QtCore import *

from gui.HyGaMainWindow import HyGaMainWindow
from dataType.HyGaVector import HyGaVector
from algorithm.HyGaTurn import HyGaIsCollineation, HyGaIsTurnLeft, HyGaIsTurnRight
from algorithm.HyGaConvexHull import HyGaConvexHull

if __name__ == "__main__":

    # 自测 每个 py单元测试
    import os
    moduleList = []
    initList = []
    for root, dirs, files in os.walk("."):
        #print("in:" + str(root))
        #print("dirs:" + str(dirs))
        #print("files:" + str(files))
        if "__pycache__" == os.path.basename(root):
            #print(root)
            continue
        for f in files:
            if "__init__.py" == f:
                initList.append(os.path.join(root, f))
                continue
            if "TODO" != f and "__init__.pyw" != f:
                moduleList.append(os.path.join(root, f))
                continue
    print(moduleList)
    for cmd in moduleList:
        pass
        #print("正在测试:" + cmd)
        #os.execv(cmd, [""])

    # 子包集成测试
    print(initList)
    for cmd in initList:
        pass
        #print("正在测试:" + cmd)

    # 整个包 演示Demo
    import sys
    app = QApplication(sys.argv)

    win = HyGaMainWindow()
    win.show()

    sys.exit(app.exec_())

