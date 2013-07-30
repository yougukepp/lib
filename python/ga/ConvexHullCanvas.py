#!/usr/bin/env python3
# -- coding utf-8 --

from PyQt4.QtGui import QApplication
from PyQt4.QtGui import QWidget
from PyQt4.QtGui import QPainter
from PyQt4.QtGui import QColor
from PyQt4.QtGui import QPen
from PyQt4.QtCore import QPoint
from PyQt4.QtCore import pyqtSignal

from dataType.Point import Point
from dataType.Points import Points
from algorithm.Convexhull import Convexhull

gCanvasWidth = 500
gCanvasHeight = 500

def Screen2Ga(point):
    rstX = point.x()
    rstY = gCanvasHeight - point.y() - 1
    return Point(rstX, rstY)

def Ga2Screen(point):
    rstX = point.X()
    rstY = gCanvasHeight - point.Y() - 1
    return QPoint(rstX, rstY)

class ConvexhullCanvas(QWidget):

    msMove = pyqtSignal(Point, name='msMove')

    mInputPoints = Points()
    mConvexhull = Convexhull()

    def __init__(self, parent=None):
        QWidget.__init__(self, parent)
        self.setFixedSize(gCanvasWidth, gCanvasHeight)
        self.setMouseTracking(True)

    def paintEvent(self, event):
        painter = QPainter(self)

        # 清屏
        painter.fillRect(0, 0, self.width(), self.height(), QColor(0, 0, 0))

        # 画凸包
        self.DrawConvexhull(painter, self.mConvexhull)

        # 画点
        self.DrawPoints(painter, self.mInputPoints)

        painter.end()

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
            self.DrawPoint(painter, Ga2Screen(p))

    def DrawConvexhull(self, painter, convexhull):
        if not convexhull.IsValid():
            return

        size = convexhull.Size()
        for i in range(1, size):
            self.DrawLine(painter, Ga2Screen(convexhull[i-1]), Ga2Screen(convexhull[i]))
            self.DrawLabel(painter, Ga2Screen(convexhull[i-1]), str(i))

    def MakeConvexhull(self):
        self.mConvexhull = Convexhull(self.mInputPoints)
        self.repaint()

    def mouseMoveEvent(self, event):
        p = Screen2Ga(event.pos())
        self.msMove.emit(p)

    def mousePressEvent(self, event):
        p = Screen2Ga(event.pos())
        self.mInputPoints.Append(p)
        self.repaint()


if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)

    win = ConvexhullCanvas()
    win.show()

    sys.exit(app.exec_())
