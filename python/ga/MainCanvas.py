#!/usr/bin/env python3
# -- coding utf-8 --

from PyQt4.QtGui import QApplication
from PyQt4.QtGui import QWidget
from PyQt4.QtGui import QTabWidget
from PyQt4.QtGui import QVBoxLayout

from PyQt4.QtCore import pyqtSignal

from ConvexhullCanvas import ConvexhullCanvas
from LineIntersectionCanvas import LineIntersectionCanvas
from dataType.Point import Point

class MainCanvas(QWidget):

    mTestTable = ["凸包", "线段求交", "扩展"]

    msMove = pyqtSignal(Point, name='msMove')
    msCurrentChanged = pyqtSignal(['QString'], name = "msCurrentChanged")

    def __init__(self, parent=None):
        QWidget.__init__(self, parent)

        self.mTabWidget = QTabWidget()
        # 凸包页
        self.mConvexhullCanvas = ConvexhullCanvas()
        self.mTabWidget.addTab(self.mConvexhullCanvas, self.mTestTable[0])

        # 线段求交页面
        self.mLineIntersectionCanvas= LineIntersectionCanvas()
        self.mTabWidget.addTab(self.mLineIntersectionCanvas, self.mTestTable[1])

        # 扩展占位页
        self.mPageTodo = QWidget()
        self.mTabWidget.addTab(self.mPageTodo, self.mTestTable[2])

        # 总体布局
        self.mLayout = QVBoxLayout()
        self.mLayout.addWidget(self.mTabWidget)
        self.setLayout(self.mLayout)

        self.mConvexhullCanvas.msMove.connect(self.msMove)
        self.mTabWidget.currentChanged.connect(self.CurrentChanged)

    def CurrentChanged(self, index):
        self.msCurrentChanged.emit(self.mTestTable[index])

    def DrawConvexhull(self):
        self.mConvexhullCanvas.MakeConvexhull()

    def DrawLineIntersection(self):
        self.mLineIntersectionCanvas.Make()

if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)

    win = MainCanvas()
    win.show()

    sys.exit(app.exec_())
