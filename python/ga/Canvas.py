#!/usr/bin/env python3
# -- coding utf-8 --

from PyQt4.QtGui import *
from PyQt4.QtCore import *

from lib.HyGaLib import gCanvasWidth, gCanvasHeight, HyGaLibScreen2Ga
from dataType.HyGaPoint import HyGaPoint
from dataType.HyGaPoints import HyGaPoints
from algorithm.HyGaConvexHull import HyGaConvexHull

def Screen2Ga(point):
    (rstX, rstY) = HyGaLibScreen2Ga(point.x(), point.y())
    return HyGaPoint(rstX, rstY)

class Canvas(QWidget):

    msMove = pyqtSignal(HyGaPoint, name='msMove')

    mInputPoints = HyGaPoints()
    mConvexHull = HyGaConvexHull()

    def __init__(self, parent=None):
        QWidget.__init__(self, parent)
        self.setFixedSize(gCanvasWidth, gCanvasHeight)
        self.setMouseTracking(True)

    def paintEvent(self, event):
        painter = QPainter(self)

        # 清屏
        painter.fillRect(0, 0, self.width(), self.height(), QColor(0, 0, 0))

        # 画凸包
        self.mConvexHull.draw(painter)

        # 画点
        self.mInputPoints.Draw(painter)

        painter.end()

    def DrawConvexHull(self):
        self.mConvexHull = HyGaConvexHull(self.mInputPoints)
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

    win = Canvas()
    win.show()

    sys.exit(app.exec_())
