#!/usr/bin/env python3
# -- coding utf-8 --

from PyQt4.QtGui import QApplication
from PyQt4.QtGui import QTabWidget
from PyQt4.QtGui import QLabel

import sys,os
gRootDir = os.path.join(os.getcwd(), "..")
sys.path.append(gRootDir)
from Assistant.Displayer import Displayer

class Assistant(QTabWidget):
    def __init__(self, parent=None):
        QTabWidget.__init__(self, parent)

        self.mDisplayer = Displayer();
        self.mRadioWidget = QLabel("频综 控件");
        self.mServoWidget = QLabel("伺服 控件");

        self.addTab(self.mDisplayer, "显控")
        self.addTab(self.mRadioWidget, "频综")
        self.addTab(self.mServoWidget, "伺服")

if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)

    win = Assistant()
    win.show()

    sys.exit(app.exec_())


