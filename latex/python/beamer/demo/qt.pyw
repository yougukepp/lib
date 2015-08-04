#!/usr/bin/env python3
# -- coding utf-8 --

from PyQt4.QtGui import QApplication
from PyQt4.QtGui import QWidget
from PyQt4.QtGui import QPainter
from PyQt4.QtGui import QColor
from PyQt4.QtGui import QPen
from PyQt4.QtGui import QBrush

from PyQt4.QtCore import Qt
from PyQt4.QtCore import QTimer

class TransparentCanvas(QWidget):

    def __init__(self, parent=None):
        QWidget.__init__(self, parent)

        self.scale = 1

        self.setAttribute(Qt.WA_TranslucentBackground, True) 
        self.setWindowFlags(Qt.FramelessWindowHint)

        timer = QTimer(self)
        timer.timeout.connect(self.update)
        timer.start(10);

    def paintEvent(self, event):

        painter = QPainter(self)

        pen = QPen(QColor(0,255,0));
        pen.setWidth(1);
        painter.setPen(pen)

        # 清屏
        painter.drawEllipse(0, 0, self.scale * self.width(), self.scale * self.height())

        self.scale = self.scale - 0.001
        if 0 >= self.scale:
            self.scale = 1

if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)

    win = TransparentCanvas()
    win.show()

    sys.exit(app.exec_())

