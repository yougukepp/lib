#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from PyQt5.QtGui import *
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *

class MainWindow(QMainWindow):
  def __init__(self, parent=None):
    super(MainWindow, self).__init__(parent) 
    
    """
    menu
    """
    newAct = QAction("&New", self)
    newAct.setShortcuts(QKeySequence.New)
    newAct.setStatusTip("Create a new file")
    newAct.triggered.connect(self.newFile) 

    openAct = QAction("&Open...", self)
    openAct.setShortcuts(QKeySequence.Open)
    openAct.setStatusTip("Open an existing file")
    openAct.triggered.connect(self.open)
    
    fileMenu = self.menuBar().addMenu("&File")
    fileMenu.addAction(newAct)
    fileMenu.addAction(openAct)


    """
    toolbar
    """ 
    fileToolBar = self.addToolBar("File")
    fileToolBar.addAction(newAct)
    fileToolBar.addAction(openAct)

    fileToolBar.setAllowedAreas(Qt.TopToolBarArea | Qt.BottomToolBarArea)
    self.addToolBar(Qt.TopToolBarArea, fileToolBar)


    """
    QDockWidget
    """
    leftContentsWindow = QDockWidget("LeftDockWidgetArea", self)
    leftContentsWindow.setAllowedAreas(Qt.LeftDockWidgetArea)
    self.addDockWidget(Qt.LeftDockWidgetArea, leftContentsWindow) 
    leftWidget = QLabel(leftContentsWindow)
    leftWidget.setText("leftContentsLabel")
    leftWidget.setAlignment(Qt.AlignCenter)
    leftContentsWindow.setWidget(leftWidget) 

    topContentsWindow = QDockWidget("TopDockWidgetArea", self)
    topContentsWindow.setAllowedAreas(Qt.TopDockWidgetArea)
    self.addDockWidget(Qt.TopDockWidgetArea, topContentsWindow) 
    topWidget = QLabel(topContentsWindow)
    topWidget.setText("topContentsLabel")
    topWidget.setAlignment(Qt.AlignCenter)
    topContentsWindow.setWidget(topWidget)
    
    rightContentsWindow = QDockWidget("RightDockWidgetArea", self)
    rightContentsWindow.setAllowedAreas(Qt.RightDockWidgetArea)
    self.addDockWidget(Qt.RightDockWidgetArea, rightContentsWindow) 
    rightWidget = QLabel(rightContentsWindow)
    rightWidget.setText("rightContentsLabel")
    rightWidget.setAlignment(Qt.AlignCenter)
    rightContentsWindow.setWidget(rightWidget) 

    buttomContentsWindow = QDockWidget("BottomDockWidgetArea", self)
    buttomContentsWindow.setAllowedAreas(Qt.BottomDockWidgetArea)
    self.addDockWidget(Qt.BottomDockWidgetArea, buttomContentsWindow) 
    buttomWidget = QLabel(buttomContentsWindow)
    buttomWidget.setText("buttomContentsLabel")
    buttomWidget.setAlignment(Qt.AlignCenter)
    buttomContentsWindow.setWidget(buttomWidget) 
    
    """
    central Widget
    """
    centralLabel = QLabel("Central Label")
    centralLabel.setAlignment(Qt.AlignCenter)
    self.setCentralWidget(centralLabel) 

    """
    status bar
    """
    statusBar = QStatusBar(self)
    statusBarLabel1 = QLabel("status Bar Label 1")
    statusBarLabel2 = QLabel("status Bar Label 2")
    statusBarLabel3 = QLabel("status Bar Label 3")
    statusBar.addWidget(statusBarLabel1)
    statusBar.addWidget(statusBarLabel2)
    statusBar.addWidget(statusBarLabel3)
    self.setStatusBar(statusBar)

  def newFile(self):
    pass

  def open(self):
    pass

if __name__ == '__main__':
  import sys 
  
  app = QApplication(sys.argv) 
  win = MainWindow()
  win.showMaximized()
  sys.exit(app.exec_())
