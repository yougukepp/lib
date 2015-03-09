#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from PyQt5.QtWidgets import QApplication
from PyQt5.QtWidgets import QStatusBar
from PyQt5.QtWidgets import QLabel

class StatusBar(QStatusBar):
    def __init__(self, parent=None):
        QStatusBar.__init__(self, parent)

        self.mLabelPos = QLabel("当前位置:(nan,nan)")
        self.mLabelTestName = QLabel("当前测试:凸包")
        self.addWidget(self.mLabelPos)
        self.addWidget(self.mLabelTestName)

    def CurrentChanged(self, testItemName):
        labelText = "当前测试:" + testItemName
        self.mLabelTestName.setText(labelText)

    def Move(self, pos):
        labelText = "当前位置:" + pos.Get2PosStr()
        self.mLabelPos.setText(labelText)

if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)

    win = StatusBar()
    win.show()

    sys.exit(app.exec_())
