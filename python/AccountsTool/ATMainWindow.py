#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from PyQt4.QtGui import *
from PyQt4.QtCore import *

from ATSqlite import ATSqlite

class ATMainWindow(QMainWindow):
  def __init__(self, parent=None):
    super(ATMainWindow, self).__init__(parent)

    tableView = QTableView()
    model = ATSqlite()
    tableView.setModel(model)
    self.setCentralWidget(tableView)

    """
    centralLabel = QLabel("中心部件")
    centralLabel.setAlignment(Qt.AlignCenter)
    self.setCentralWidget(centralLabel)
    """

    statusBar = QStatusBar(self)
    statusBarLabel1 = QLabel("标签1")
    statusBarLabel2 = QLabel("标签2")
    statusBarLabel3 = QLabel("标签3")
    statusBar.addWidget(statusBarLabel1)
    statusBar.addWidget(statusBarLabel2)
    statusBar.addWidget(statusBarLabel3)
    self.setStatusBar(statusBar)

if __name__ == '__main__':
  import sys

  app = QApplication(sys.argv)
  win = ATMainWindow()
  win.showMaximized () 
  sys.exit(app.exec_())

