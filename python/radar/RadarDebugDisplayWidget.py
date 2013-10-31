#!/usr/bin/env python3
# -- coding utf-8 --

from PyQt4.QtGui import QApplication
from PyQt4.QtGui import QGridLayout
from PyQt4.QtGui import QHBoxLayout
from PyQt4.QtGui import QVBoxLayout
from PyQt4.QtGui import QPushButton
from PyQt4.QtGui import QLineEdit
from PyQt4.QtGui import QWidget
from PyQt4.QtGui import QLabel

from RadarEchoWidget import RadarEchoWidget

class RadarDebugDisplayWidget(QWidget):
    def __init__(self, parent=None):
        QWidget.__init__(self, parent)

        self.mLayoutIp = QHBoxLayout()
        self.mLayoutFile = QHBoxLayout()
        self.mLayoutPort = QHBoxLayout()
        self.mLayoutInfo = QVBoxLayout()

        self.mLayout = QHBoxLayout()
        self.mEchoWidget = RadarEchoWidget()
        self.mLineEditEchoFileName = QLineEdit("echo.echo")
        self.mPushButtonRead = QPushButton("读取")
        self.mLabelDisplayIp = QLabel("显控 IP:")
        self.mLineEditIp = QLineEdit("192.168.1.1")
        self.mLabelDisplayPort = QLabel("显控回波端口:")
        self.mLineEditPort = QLineEdit("5802")
        self.mPushButtonSend = QPushButton("发送")

        self.mLayoutFile.addWidget(self.mLineEditEchoFileName)
        self.mLayoutFile.addWidget(self.mPushButtonRead)
        self.mLayoutIp.addWidget(self.mLabelDisplayIp)
        self.mLayoutIp.addWidget(self.mLineEditIp)
        self.mLayoutPort.addWidget(self.mLabelDisplayPort)
        self.mLayoutPort.addWidget(self.mLineEditPort)

        self.mLayoutInfo.addLayout(self.mLayoutFile)
        self.mLayoutInfo.addLayout(self.mLayoutIp)
        self.mLayoutInfo.addLayout(self.mLayoutPort)
        self.mLayoutInfo.addWidget(self.mPushButtonSend)
        self.mLayoutInfo.addStretch()

        self.mLayout.addWidget(self.mEchoWidget)
        self.mLayout.addLayout(self.mLayoutInfo)
        self.setLayout(self.mLayout)

if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)

    win = RadarDebugDisplayWidget()
    win.show()

    sys.exit(app.exec_())


