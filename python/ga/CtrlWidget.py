#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from PyQt4.QtGui import *
from PyQt4.QtCore import *

class CtrlWidget(QWidget):

    mTestTable = ["凸包", "其他"]

    #msRun = Qt.pyqtSingal(void, name = "msRun")
    msRun = pyqtSignal(['QString'], name = "msRun")
    msCurrentChanged = pyqtSignal(['QString'], name = "msCurrentChanged")

    def __init__(self, parent=None):
        QWidget.__init__(self, parent)
        #self.setFixedWidth(200)

        self.mTabWidget = QTabWidget()
        self.mButtonRun = QPushButton("开始运行")

        # 凸包控制页
        self.mPageConvexHull = QWidget()
        self.mPageConvexHullLayout = QVBoxLayout()
        self.mPageConvexHullLabel = QLabel("凸包控制")
        self.mPageConvexHullLayout.addWidget(self.mPageConvexHullLabel)
        self.mPageConvexHull.setLayout(self.mPageConvexHullLayout)
        self.mTabWidget.addTab(self.mPageConvexHull, self.mTestTable[0])

        # 扩展页
        self.mPageTodo = QWidget()
        self.mPageTodoLayout = QVBoxLayout()
        self.mPageTodoLabel = QLabel("其他算法控制")
        self.mPageTodoLayout.addWidget(self.mPageTodoLabel)
        self.mPageTodo.setLayout(self.mPageTodoLayout)
        self.mTabWidget.addTab(self.mPageTodo, self.mTestTable[1])

        # 总体布局
        self.mLayout = QVBoxLayout()
        self.mLayout.addWidget(self.mTabWidget)
        self.mLayout.addWidget(self.mButtonRun)
        self.setLayout(self.mLayout)

        self.mTabWidget.currentChanged.connect(self.CurrentChanged)

    def CurrentChanged(self, index):
        self.msCurrentChanged.emit(self.mTestTable[index])

if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)

    win = CtrlWidget()
    win.show()

    sys.exit(app.exec_())
