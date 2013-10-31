#!/usr/bin/env python3
# -- coding utf-8 --

from PyQt4.QtGui import QApplication
from PyQt4.QtGui import QTabWidget
from PyQt4.QtGui import QLabel

from RadarDebugWidget import RadarDebugWidget

class RadarToolWidget(QTabWidget):
    def __init__(self, parent=None):
        QTabWidget.__init__(self, parent)

        self.mDebugWidget = RadarDebugWidget()
        self.mSimWidget = QLabel("仿真器 控件")
        self.mEchoEditWidget = QLabel("回波编辑 控件")

        self.addTab(self.mDebugWidget, "调试助手")
        self.addTab(self.mSimWidget, "仿真")
        self.addTab(self.mEchoEditWidget, "回波编辑")

if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)

    win = RadarToolWidget()
    win.show()

    sys.exit(app.exec_())


