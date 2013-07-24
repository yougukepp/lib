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
    initList = []
    for root, dirs, files in os.walk("."):
        #print("in:" + str(root))
        #print("dirs:" + str(dirs))
        #print("files:" + str(files))
        if "__pycache__" == os.path.basename(root):
            #print(root)
            continue
        for f in files:
            if "__init__.py" != f and "TODO" != f:
                initList.append(os.path.join(root, f))
    print(initList)
    for cmd in initList:
        pass
        #print("正在测试:" + cmd)
        #os.execv(cmd, [""])

    # 演示Demo
    import sys
    app = QApplication(sys.argv)

    win = HyGaMainWindow()
    win.show()

    sys.exit(app.exec_())

