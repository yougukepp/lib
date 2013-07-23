#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from PyQt4.QtGui import *
from PyQt4.QtCore import *

from HyGaMainWindow import HyGaMainWindow

if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)

    win = HyGaMainWindow()
    win.show()

    sys.exit(app.exec_())

