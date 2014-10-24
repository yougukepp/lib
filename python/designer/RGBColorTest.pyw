#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from PyQt5.QtWidgets import QApplication
from PyQt5.QtWidgets import QDialog
from PyQt5.QtGui import QColor
from PyQt5.QtGui import QPainter
from PyQt5.QtGui import QBrush

from PyQt5.uic import loadUiType,loadUi

UIClass = loadUiType("RGBColorTest.ui")

class RGBTester(QDialog):
    def __init__(self, parent=None):
        QDialog.__init__(self, parent)
        self.mUi = UIClass[0]()
        self.mUi.setupUi(self)

        self.mSpinBoxRed = self.mUi.spinBoxRed
        self.mSpinBoxGreen = self.mUi.spinBoxGreen
        self.mSpinBoxBlue = self.mUi.spinBoxBlue

    def paintEvent(self, event):
        r = self.mUi.spinBoxRed.value()
        g = self.mUi.spinBoxGreen.value()
        b = self.mUi.spinBoxBlue.value()

        c = QColor(r, g, b)
        painter = QPainter(self)
        brush = QBrush(c)
        painter.setBrush(brush)

        w = 100
        h = 100
        x = 0
        y = (self.height() - h) / 2

        painter.drawRect(x, y, w, h)

if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)

    win = RGBTester()
    win.show()

    sys.exit(app.exec_())
