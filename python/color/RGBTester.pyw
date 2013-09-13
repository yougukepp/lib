#!/usr/bin/env python3
# -- coding utf-8 --

from PyQt4.QtGui import QApplication
from PyQt4.QtGui import QWidget
from PyQt4.QtGui import QLabel
from PyQt4.QtGui import QLineEdit 
from PyQt4.QtGui import QVBoxLayout
from PyQt4.QtGui import QPainter
from PyQt4.QtGui import QColor
from PyQt4.QtGui import QBrush
"""
from PyQt4.QtGui import QPen
from PyQt4.QtCore import Qt
"""
from PyQt4.QtCore import QTimer

class RGBTesterWidget(QWidget):
    #msMove = pyqtSignal(Point, name='msMove')

    def __init__(self, parent=None):
        QWidget.__init__(self, parent)

        self.mLayout = QVBoxLayout()
        self.mLabelRGB = QLabel("RGB:")
        self.mLabelR = QLabel("R")
        self.mLabelG = QLabel("G")
        self.mLabelB = QLabel("B")
        self.mLineEditR = QLineEdit("R")
        self.mLineEditG = QLineEdit("G")
        self.mLineEditB = QLineEdit("B")
        self.mLineEditR.setMaximumWidth(30)
        self.mLineEditG.setMaximumWidth(30)
        self.mLineEditB.setMaximumWidth(30)

        self.mLayout.addWidget(self.mLabelRGB)
        self.mLayout.addWidget(self.mLabelR)
        self.mLayout.addWidget(self.mLineEditR)
        self.mLayout.addWidget(self.mLabelG)
        self.mLayout.addWidget(self.mLineEditG)
        self.mLayout.addWidget(self.mLabelB)
        self.mLayout.addWidget(self.mLineEditB)
        self.setLayout(self.mLayout)

        timer = QTimer(self)
        timer.timeout.connect(self.update)
        timer.start(1);

    def paintEvent(self, event): 
        r = self.mLineEditR.text()
        g = self.mLineEditG.text()
        b = self.mLineEditB.text()

        brush = None
        if r.isdigit() and g.isdigit() and b.isdigit():
            brush = QBrush(QColor(int(r), int(g), int(b)));
        else:
            brush = QBrush(QColor(0, 0, 0));

        painter = QPainter(self)
        painter.setBrush(brush)
        painter.drawRect(50, 20, 120, 120)


if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)

    win = RGBTesterWidget()
    win.show()

    sys.exit(app.exec_())

