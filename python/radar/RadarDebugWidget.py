#!/usr/bin/env python3
# -- coding utf-8 --

from PyQt4.QtGui import QApplication
from PyQt4.QtGui import QTabWidget
from PyQt4.QtGui import QLabel

from RadarDebugDisplayWidget import RadarDebugDisplayWidget

class RadarDebugWidget(QTabWidget):
    def __init__(self, parent=None):
        QTabWidget.__init__(self, parent)

        self.mDisplayWidget = RadarDebugDisplayWidget();
        self.mRadioWidget = QLabel("频综 控件");
        self.mServoWidget = QLabel("伺服 控件");

        self.addTab(self.mDisplayWidget, "显控")
        self.addTab(self.mRadioWidget, "频综")
        self.addTab(self.mServoWidget, "伺服")

if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)

    win = RadarDebugWidget()
    win.show()

    sys.exit(app.exec_())


