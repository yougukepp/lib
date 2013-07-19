#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from PyQt4.QtGui import *
from PyQt4.QtCore import *

from HyGaPoint import *
from HyGaConvexHull import HyGaConvexHull

gCanvasWidth = 800
gCanvasHeight = 800

class HyGaCanvas(QWidget): 

    msMove = pyqtSignal(QPoint, name='msMove') 

    mConvexHullInput = []
    mConvexHullOutput = []
    mConvexHullOK = False;

    def __init__(self, parent=None): 
        QWidget.__init__(self, parent)
        self.setFixedSize(gCanvasWidth, gCanvasHeight)
        self.setMouseTracking(True)
        
    def paintEvent(self, event):
        painter = QPainter(self) 

        # 清屏
        painter.fillRect(0, 0, self.width(), self.height(), QColor(0, 0, 0))

        # 画点
        for p in self.mConvexHullInput: 
            # s = "p" + str(i)
            # painter.drawText(pPhy, s)
            p.draw(painter)

        # 画凸包
        if True == self.mConvexHullOK:
            size = len(self.mConvexHullOutput)

            if size < 3:
                print("凸包点数小于3")
                exit()

            pen = QPen(QColor(255, 0, 0))
            pen.setWidth(1)
            painter.setPen(pen)
            for i in range(1, size): 
                painter.drawLine(self.mConvexHullOutput[i-1].ScreenPos(),
                        self.mConvexHullOutput[i].ScreenPos())
                print(i - 1, i)
            painter.drawLine(self.mConvexHullOutput[size-1].ScreenPos(),
                    self.mConvexHullOutput[0].ScreenPos())
            print(size-1, 0)

        painter.end()

    def DrawConvexHull(self): 
        HyGaConvexHull(self.mConvexHullInput, self.mConvexHullOutput)
        self.mConvexHullOK = True;
        self.repaint()

    def mouseMoveEvent(self, event):
        self.msMove.emit(event.pos())

    def mousePressEvent(self, event):
        x = event.pos().x()
        y = event.pos().y()
        p = HyGaPoint(x, y)
        self.mConvexHullInput.append(p)
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
        labelText = "当前位置:(" + str(pos.x()) + "," + str(pos.y()) + ")"
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

