#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from PyQt4.QtGui import *
from PyQt4.QtCore import *

from gui.HyGaStatusBar import HyGaStatusBar
from gui.HyGaCtrlWidget import HyGaCtrlWidget
from gui.HyGaCanvas import HyGaCanvas

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

