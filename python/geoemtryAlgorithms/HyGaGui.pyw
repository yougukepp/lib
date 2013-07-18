#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from PyQt4.QtGui import *
from PyQt4.QtCore import *

class HyGaCentralLabel(QWidget):
    def __init__(self, parent=None): 
        QWidget.__init__(self, parent)
        self.setFixedSize(800, 800)
        
    def paintEvent(self, event):
        painter = QPainter(self) 
        painter.fillRect(0, 0, self.width(), self.height(), QColor(0, 0, 0))
        painter.end()

class HyGaStatusBar(QStatusBar):
    def __init__(self, parent=None): 
        QStatusBar.__init__(self, parent)

        self.mLabelPos = QLabel("当前位置:nan,nan")
        self.mLabelTestName = QLabel("当前测试:凸包算法")
        self.addWidget(self.mLabelPos)
        self.addWidget(self.mLabelTestName)

class HyGaCtrlWidget(QWidget): 

    #msRun = Qt.pyqtSingal(void, name = "msRun") 

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
        self.mTabWidget.addTab(self.mPageConvexHull, "凸包")

        # 扩展页
        self.mPageTodo = QWidget()
        self.mPageTodoLayout = QVBoxLayout()
        self.mPageTodoLabel = QLabel("其他算法控制")
        self.mPageTodoLayout.addWidget(self.mPageTodoLabel)
        self.mPageTodo.setLayout(self.mPageTodoLayout)
        self.mTabWidget.addTab(self.mPageTodo, "占位")

        # 总体布局
        self.mLayout = QVBoxLayout()
        self.mLayout.addWidget(self.mTabWidget)
        self.mLayout.addWidget(self.mButtonRun)
        self.setLayout(self.mLayout)

class HyGaMainWindow(QMainWindow):
  def __init__(self, parent=None):
    QMainWindow.__init__(self, parent)
    self.setWindowTitle("计算几何 测试")

    # 中心画布
    centralLabel = HyGaCentralLabel()
    self.setCentralWidget(centralLabel) 
    
    # 状态栏
    statusBar = HyGaStatusBar()
    self.setStatusBar(statusBar)

    # 控制(dock)框 
    self.mCtrlWidget = HyGaCtrlWidget()
    ctrlDock = QDockWidget()
    self.addDockWidget(Qt.RightDockWidgetArea, ctrlDock) 
    ctrlDock.setWidget(self.mCtrlWidget)

    #self.mCtrlWidget.clicked.connect(centralLabel.testTurn)

if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)

    win = HyGaMainWindow()
    win.show()

    sys.exit(app.exec_())

