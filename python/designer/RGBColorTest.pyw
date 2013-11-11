#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from PyQt4.QtGui import QApplication
from PyQt4.QtGui import QWidget
from PyQt4.QtGui import QDialog
from PyQt4.QtGui import QSpinBox
from PyQt4.QtGui import QBrush
from PyQt4.QtGui import QPainter
from PyQt4.QtGui import QColor
from PyQt4.QtGui import QGraphicsView

from PyQt4.uic import loadUiType

UIClass = loadUiType("RGBColorTest.ui")

class RGBTester(QDialog):
    def __init__(self, parent=None):
        QDialog.__init__(self, parent)
        self.mUi = UIClass[0]()
        self.mUi.setupUi(self)

        self.mSpinBoxRed = self.findChild(QSpinBox, "spinBoxRed")
        self.mSpinBoxGreen = self.findChild(QSpinBox, "spinBoxGreen")
        self.mSpinBoxBlue = self.findChild(QSpinBox, "spinBoxBlue")


    def paintEvent(self, event):
        r = self.mSpinBoxRed.value()
        g = self.mSpinBoxGreen.value()
        b = self.mSpinBoxBlue.value()

        c = QColor(r, g, b)
        painter = QPainter(self)
        brush = QBrush(c)
        painter.setBrush(brush)
        painter.drawRect(120, 20, 160, 160)

if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)

    win = RGBTester()
    win.show()

    sys.exit(app.exec_())

