#!/usr/bin/env python3
# -- coding utf-8 --

from PyQt4.QtGui import QApplication
from PyQt4.QtGui import QVBoxLayout
from PyQt4.QtGui import QWidget
from PyQt4.QtGui import QLabel

import sys,os
gRootDir = os.path.join(os.getcwd(), "..")
sys.path.append(gRootDir)
from Core.Widget.LabelWithLineEditWidget import LabelWithLineEditWidget

class SimCtrlWidget(QWidget):
    def __init__(self, parent=None):
        QWidget.__init__(self, parent)

        self.mLayout = QVBoxLayout()

        self.mDisplayerIp = LabelWithLineEditWidget()
        self.mEchoServerPort = LabelWithLineEditWidget()
        self.mDSPServerPort = LabelWithLineEditWidget()
        self.mRadioServerPort = LabelWithLineEditWidget()
        self.mServoServerPort = LabelWithLineEditWidget()
        self.mDSPClientPort = LabelWithLineEditWidget()
        self.mRadioClientPort = LabelWithLineEditWidget()
        self.mServoClientPort = LabelWithLineEditWidget()

        self.mLayout.addWidget(self.mDisplayerIp)
        self.mLayout.addWidget(self.mEchoServerPort)
        self.mLayout.addWidget(self.mDSPServerPort)
        self.mLayout.addWidget(self.mRadioServerPort)
        self.mLayout.addWidget(self.mServoServerPort)
        self.mLayout.addWidget(self.mDSPClientPort)
        self.mLayout.addWidget(self.mRadioClientPort)
        self.mLayout.addWidget(self.mServoClientPort)

        self.setLayout(self.mLayout)

if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)

    win = SimCtrlWidget()
    win.show()

    sys.exit(app.exec_())


