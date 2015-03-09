#!/usr/bin/env python3
# -- coding utf-8 --

from PyQt5.QtWidgets import QApplication
from PyQt5.QtWidgets import QWidget
from PyQt5.QtGui import QPainter
from PyQt5.QtGui import QColor
from PyQt5.QtGui import QPen
from PyQt5.QtGui import QBrush

from PyQt5.QtCore import Qt
from PyQt5.QtCore import QTimer
#from PyQt4.QtCore import pyqtSignal

class TransparentCanvas(QWidget):

    #msMove = pyqtSignal(Point, name='msMove')

    def __init__(self, parent=None):
        QWidget.__init__(self, parent)

        self.scale = 1

        self.setAttribute(Qt.WA_TranslucentBackground, True) 
        self.setWindowFlags(Qt.FramelessWindowHint)

        timer = QTimer(self)
        timer.timeout.connect(self.update)
        timer.start(10);

        #self.setMouseTracking(True)

    def paintEvent(self, event):

        painter = QPainter(self)

        pen = QPen(QColor(0,255,0));
        pen.setWidth(1);
        painter.setPen(pen)

        #brush = QBrush(QColor(0,255,0));
        #painter.setBrush(brush)

        # 清屏
        painter.drawEllipse(0, 0, self.scale * self.width(), self.scale * self.height())

        self.scale = self.scale - 0.001
        if 0 >= self.scale:
            self.scale = 1

        print("draw")

if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)

    win = TransparentCanvas()
    win.show()

    sys.exit(app.exec_())
