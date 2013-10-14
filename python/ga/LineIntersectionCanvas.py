#!/usr/bin/env python3
# -- coding utf-8 --

from PyQt4.QtGui import QApplication
from PyQt4.QtGui import QPainter
from PyQt4.QtGui import QColor
from dataType.Lines import Lines
from BaseCanvas import BaseCanvas, Ga2Screen

from algorithm.LineIntersection import LineIntersection

class LineIntersectionCanvas(BaseCanvas):
    mIntersectionPoints = {}

    def __init__(self, parent=None):
        BaseCanvas.__init__(self, parent)

    def paintEvent(self, event):
        painter = QPainter(self)

        # 清屏
        painter.fillRect(0, 0, self.width(), self.height(), QColor(0, 0, 0))

        # 画线
        self.DrawLines(painter, self.GetInputPoints())

        # 画点
        self.DrawUnpairsPoint(painter, self.GetInputPoints())

        painter.end()

    def DrawLines(self, painter, points):
        size = int(points.Size() / 2)
        if size < 1:
            return

        for i in range(0, size):
            index = 2 * i
            self.DrawLine(painter, Ga2Screen(points[index]), Ga2Screen(points[index+1]))
            self.DrawLabel(painter, Ga2Screen(points[index]), str(i))

    def DrawUnpairsPoint(self, painter, points):
        if 0 == points.Size() % 2:
            return

        self.DrawPoint(painter, Ga2Screen(points[-1]))

    def Make(self):
        points = self.GetInputPoints()
        if 0 != points.Size() % 2:
            print("两点确定线段，但输入有孤立的点")
            return

        lines = Lines(points)
        IntersectionDict = {}
        LineIntersection(lines, IntersectionDict)
        self.repaint()

if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)

    win = LineIntersectionCanvas()
    win.show()

    sys.exit(app.exec_())
