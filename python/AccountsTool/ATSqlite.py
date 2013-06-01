#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from PyQt4.QtGui import *
from PyQt4.QtCore import *

from datetime import datetime

class ATSqlite(QAbstractTableModel):
    def __init__(self, parent=None):
        super(ATSqlite, self).__init__(parent)
        timer = QTimer(self);
        timer.setInterval(1);
        timer.timeout.connect(self.timerHit)
        timer.start();

    def rowCount(self, index):
        return 2

    def columnCount(self, index):
        return 3

    def data(self, index, role):
        if role == Qt.DisplayRole:
            return (str(datetime.now()))
        return None

    def headerData(self, section, orientation, role):
        if role == Qt.DisplayRole:
            if orientation == Qt.Horizontal:
                if 0 == section:
                    return "first";
                elif 1 == section:
                    return "second"
                elif 2 == section:
                    return "third"
                else:
                    pass
        return None

    def timerHit(self):
        topLeft = self.createIndex(0, 0);
        self.dataChanged.emit(topLeft, topLeft)
        return None

if __name__ == '__main__':
  import sys
  print(datetime.now())

  app = QApplication(sys.argv)
  atSqlite = ATSqlite()
  sys.exit(app.exec_())


