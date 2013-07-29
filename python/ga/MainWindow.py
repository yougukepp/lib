#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from PyQt4.QtGui import *
from PyQt4.QtCore import *

from StatusBar import StatusBar
from CtrlWidget import CtrlWidget
from Canvas import Canvas

class MainWindow(QMainWindow):
    def __init__(self, parent=None):
        QMainWindow.__init__(self, parent)
        self.setWindowTitle("计算几何 测试")

        """
        菜单栏
        """
        newAct = QAction("&新建", self)
        newAct.setShortcuts(QKeySequence.New)
        newAct.setStatusTip("新建一个工程")
        newAct.triggered.connect(self.newProject)

        openAct = QAction("&打开", self)
        openAct.setShortcuts(QKeySequence.Open)
        openAct.setStatusTip("打开存在的工程")
        openAct.triggered.connect(self.openProject)

        fileMenu = self.menuBar().addMenu("&工程")
        fileMenu.addAction(newAct)
        fileMenu.addAction(openAct)

        """
        工具栏
        """
        fileToolBar = self.addToolBar("工程")
        fileToolBar.addAction(newAct)
        fileToolBar.addAction(openAct)

        fileToolBar.setAllowedAreas(Qt.TopToolBarArea | Qt.BottomToolBarArea)
        self.addToolBar(Qt.TopToolBarArea, fileToolBar)

        # 中心画布
        self.mCanvas = Canvas()
        self.setCentralWidget(self.mCanvas)

        # 状态栏
        self.mStatusBar = StatusBar()
        self.setStatusBar(self.mStatusBar)

        # 控制(dock)框
        self.mCtrlWidget = CtrlWidget()
        ctrlDock = QDockWidget("控制")
        self.addDockWidget(Qt.RightDockWidgetArea, ctrlDock)
        ctrlDock.setWidget(self.mCtrlWidget)
        ctrlDock.setFeatures(QDockWidget.NoDockWidgetFeatures)

        # 绑定信号和槽
        self.mCanvas.msCurrentChanged.connect(self.mStatusBar.CurrentChanged)
        self.mCanvas.msMove.connect(self.mStatusBar.Move)
        self.mCtrlWidget.mButtonRun.clicked.connect(self.mCanvas.DrawConvexHull)

    def newProject(self):
        pass

    def openProject(self):
        pass


if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)

    win = MainWindow()
    win.show()

    sys.exit(app.exec_())

