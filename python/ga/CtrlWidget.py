#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from PyQt5.QtWidgets import QApplication
from PyQt5.QtWidgets import QWidget
from PyQt5.QtWidgets import QPushButton
from PyQt5.QtWidgets import QLabel
from PyQt5.QtWidgets import QVBoxLayout

from PyQt5.QtCore import pyqtSignal

class CtrlWidget(QWidget):

    mTestTable = ["凸包", "其他"]

    msRun = pyqtSignal(name = "msRun")
    msCurrentChanged = pyqtSignal(['QString'], name = "msCurrentChanged")

    def __init__(self, parent=None):
        QWidget.__init__(self, parent)

        self.mButtonRun = QPushButton("开始运行")
        self.mLabel = QLabel("占位符")

        # 总体布局
        self.mLayout = QVBoxLayout()
        self.mLayout.addWidget(self.mLabel)
        self.mLayout.addWidget(self.mButtonRun)
        self.setLayout(self.mLayout)

        self.mButtonRun.clicked.connect(self.msRun)


if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)

    win = CtrlWidget()
    win.show()

    sys.exit(app.exec_())
