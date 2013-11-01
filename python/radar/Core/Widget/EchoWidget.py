#!/usr/bin/env python3
# -- coding utf-8 --

from PyQt4.QtGui import QApplication
from PyQt4.QtGui import QPainter
from PyQt4.QtGui import QBrush
from PyQt4.QtGui import QColor
from PyQt4.QtGui import QWidget 

import sys,os
gRootDir = os.path.join(os.getcwd(), "..", "..")
sys.path.append(gRootDir)
from Core.Data.EchoSet import EchoSet

class EchoWidget(QWidget):
    mFrameIndex = 0                    # 用于记录当前放映的帧编号

    def __init__(self, parent=None):
        QWidget.__init__(self, parent)
        self.setFixedSize(600, 600)
        self.mEchoSet = EchoSet()

    def paintEvent(self, event): 
        brush = QBrush(QColor(0, 0, 0));
        painter = QPainter(self)

        # TODO: 删除清屏
        painter.setBrush(brush)
        painter.drawRect(0, 0, self.width(), self.height())

        # 回波绘制
        self.mEchoSet.Draw(painter)

    def PlayAFrame(self, echoFileName):
        echoFile = open(echoFileName, "r")
        print("EchoWidget,准备编写回波放映")

        """
        for line in echoFile:
            print(line)
        """

        echoFile.close()

if __name__ == "__main__":
    app = QApplication(sys.argv)

    win = EchoWidget()
    win.show()

    sys.exit(app.exec_())

