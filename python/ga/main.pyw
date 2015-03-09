#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from PyQt5.QtWidgets import QApplication

from MainWindow import MainWindow

if __name__ == "__main__":

    #TODO: 模块自测代码

    # 整个包 演示Demo
    import sys
    #print(sys.path)
    app = QApplication(sys.argv)

    win = MainWindow()
    win.show()

    sys.exit(app.exec_())

