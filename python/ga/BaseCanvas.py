#!/usr/bin/env python3
# -- coding utf-8 --

from PyQt4.QtGui import QApplication
from PyQt4.QtGui import QWidget
from PyQt4.QtGui import QPainter
from PyQt4.QtGui import QColor
from PyQt4.QtGui import QPen
from PyQt4.QtCore import pyqtSignal

from dataType.Point import Point
from dataType.Points import Points

from config.config import gCanvasWidth, gCanvasHeight

class BaseCanvas(QWidget):

    msMove = pyqtSignal(Point, name='msMove')

    mInputPoints = Points()

    def __init__(self, parent=None):
        QWidget.__init__(self, parent)
        self.setFixedSize(gCanvasWidth, gCanvasHeight)
        self.setMouseTracking(True)

    def GetInputPoints(self):
        return self.mInputPoints

    def DrawPoint(self, painter, point):
        pen = QPen(QColor(0, 255, 0))
        pen.setWidth(1)
        painter.setPen(pen)
        painter.drawPoint(point)

    def DrawLine(self, painter, pStart, pEnd):
        pen = QPen(QColor(255, 0, 0))
        pen.setWidth(1)
        painter.setPen(pen)
        painter.drawLine(pStart, pEnd)

    def DrawLabel(self, painter, point, label):
        pen = QPen(QColor(255, 255, 255))
        pen.setWidth(1)
        painter.setPen(pen)
        painter.drawText(point, label)

    def DrawPoints(self, painter, points):
        for p in points:
            self.DrawPoint(painter, p.GetScreenPoint())

    def mouseMoveEvent(self, event):
        p = Point(event.pos().x(), event.pos().y())
        self.msMove.emit(p)

    def mousePressEvent(self, event):
        p = Point(event.pos().x(), event.pos().y())
        self.mInputPoints.Append(p)
        self.repaint()

if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)

    win = BaseCanvas()
    win.show()

    sys.exit(app.exec_())
