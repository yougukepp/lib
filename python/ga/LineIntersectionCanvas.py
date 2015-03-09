#!/usr/bin/env python3
# -- coding utf-8 --

from PyQt5.QtWidgets import QApplication
from PyQt5.QtGui import QPainter
from PyQt5.QtGui import QColor
from dataType.Line import Line
from dataType.Lines import Lines
from BaseCanvas import BaseCanvas

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
            self.DrawLine(painter, points[index].GetScreenPoint(), points[index+1].GetScreenPoint())
            self.DrawLabel(painter, points[index].GetScreenPoint(), str(i))

    def DrawUnpairsPoint(self, painter, points):
        if 0 == points.Size() % 2:
            return

        self.DrawPoint(painter, points[-1].GetScreenPoint())

    def Make(self):
        points = self.GetInputPoints()
        if 0 != points.Size() % 2:
            print("两点确定线段，但输入有孤立的点")
            return

        lines = Lines()
        IntersectionDict = {}
        # 构造 线段集
        i = 0
        iMax = points.Size()
        while i < iMax:
            line = Line(points[i], points[i+1])
            lines.Append(line)
            i += 2

        LineIntersection(lines, IntersectionDict)
        self.repaint()

    def Clear(self):
        BaseCanvas.Clear(self)
        self.mIntersectionPoints = {}

if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)

    win = LineIntersectionCanvas()
    win.show()

    sys.exit(app.exec_())
