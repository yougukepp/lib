#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from PyQt4.QtGui import QApplication

from MainWindow import MainWindow

if __name__ == "__main__":

    #TODO: 模块自测代码

    # 整个包 演示Demo
    import sys
    app = QApplication(sys.argv)

    win = MainWindow()
    win.show()

    sys.exit(app.exec_())

