#!/usr/bin/env python3
# -- coding utf-8 --

from PyQt5.QtGui import *
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *

if __name__ == '__main__':
  import sys
  app = QApplication(sys.argv) 
  
  label = QLabel("<p><font color=red><b><i>PyQT4 样式表</i></b></font></p>")
  label.resize(300, 300)

  label.show()

  sys.exit(app.exec_())


