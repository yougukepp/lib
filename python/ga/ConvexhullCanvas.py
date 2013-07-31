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
from BaseCanvas import BaseCanvas, Screen2Ga, Ga2Screen

class ConvexhullCanvas(BaseCanvas):
    mConvexhull = Convexhull()

    def __init__(self, parent=None):
        BaseCanvas.__init__(self, parent)

    def paintEvent(self, event):
        painter = QPainter(self)

        # 清屏
        painter.fillRect(0, 0, self.width(), self.height(), QColor(0, 0, 0))

        # 画凸包
        self.DrawConvexhull(painter, self.mConvexhull)

        # 画点
        self.DrawPoints(painter, self.GetInputPoints())

        painter.end()

    def DrawConvexhull(self, painter, convexhull):
        if not convexhull.IsValid():
            return

        size = convexhull.Size()
        for i in range(1, size):
            self.DrawLine(painter, Ga2Screen(convexhull[i-1]), Ga2Screen(convexhull[i]))
            self.DrawLabel(painter, Ga2Screen(convexhull[i-1]), str(i))
        self.DrawLine(painter, Ga2Screen(convexhull[size-1]), Ga2Screen(convexhull[0]))
        self.DrawLabel(painter, Ga2Screen(convexhull[size-1]), str(size))

    def MakeConvexhull(self):
        self.mConvexhull = Convexhull(self.mInputPoints)
        self.repaint()

if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)

    win = ConvexhullCanvas()
    win.show()

    sys.exit(app.exec_())
