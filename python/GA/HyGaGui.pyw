#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from PyQt4.QtGui import *
from PyQt4.QtCore import *

from HyGaLib import *
from HyGaPoint import *
from HyGaPoints import *
from HyGaConvexHull import HyGaConvexHull
from HyGaVector import *

def Screen2Ga(point):
    (rstX, rstY) = HyGaLibScreen2Ga(point.x(), point.y())
    return HyGaPoint(rstX, rstY)

class HyGaCanvas(QWidget): 

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
        self.mInputPoints.draw(painter)

        painter.end()

    def DrawConvexHull(self): 
        self.mConvexHull = HyGaConvexHull(self.mInputPoints)
        self.repaint()

    def mouseMoveEvent(self, event):
        p = Screen2Ga(event.pos())
        self.msMove.emit(p)

    def mousePressEvent(self, event):
        p = Screen2Ga(event.pos())
        self.mInputPoints.append(p)
        self.repaint()

class HyGaStatusBar(QStatusBar):
    def __init__(self, parent=None): 
        QStatusBar.__init__(self, parent)

        self.mLabelPos = QLabel("当前位置:(nan,nan)")
        self.mLabelTestName = QLabel("当前测试:凸包")
        self.addWidget(self.mLabelPos)
        self.addWidget(self.mLabelTestName)

    def CurrentChanged(self, testItemName):
        labelText = "当前测试:" + testItemName
        self.mLabelTestName.setText(labelText)

    def Move(self, pos):
        labelText = "当前位置:(" + str(pos.X()) + "," + str(pos.Y()) + ")"
        self.mLabelPos.setText(labelText)

class HyGaCtrlWidget(QWidget): 

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

class HyGaMainWindow(QMainWindow):
  def __init__(self, parent=None):
    QMainWindow.__init__(self, parent)
    self.setWindowTitle("计算几何 测试")

    # 中心画布
    self.mCanvas = HyGaCanvas()
    self.setCentralWidget(self.mCanvas)
    
    # 状态栏
    self.mStatusBar = HyGaStatusBar()
    self.setStatusBar(self.mStatusBar)

    # 控制(dock)框 
    self.mCtrlWidget = HyGaCtrlWidget()
    ctrlDock = QDockWidget("控制")
    self.addDockWidget(Qt.RightDockWidgetArea, ctrlDock) 
    ctrlDock.setWidget(self.mCtrlWidget)
    ctrlDock.setFeatures(QDockWidget.NoDockWidgetFeatures)

    # 绑定信号和槽
    self.mCtrlWidget.msCurrentChanged.connect(self.mStatusBar.CurrentChanged)
    self.mCanvas.msMove.connect(self.mStatusBar.Move)
    self.mCtrlWidget.mButtonRun.clicked.connect(self.mCanvas.DrawConvexHull)

if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)

    win = HyGaMainWindow()
    win.show()

    sys.exit(app.exec_())

