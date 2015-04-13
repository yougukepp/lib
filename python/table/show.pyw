#!/usr/bin/env python3
# -- coding utf-8 --

import sys

from PyQt5 import QtGui 
from PyQt5.QtWidgets import QApplication
from PyQt5.QtWidgets import QMainWindow

class MainWindow(QMainWindow):
    def __init__( self ):
        QMainWindow.__init__( self )
        self.setWindowTitle( "PyQt" )
        self.resize( 300, 200 )

if __name__ == "__main__":
    app = QApplication( sys.argv )
    mywindow = MainWindow()
    mywindow.show()
    app.exec_()

