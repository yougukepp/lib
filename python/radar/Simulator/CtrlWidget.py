#!/usr/bin/env python3
# -- coding utf-8 --

from PyQt4.QtGui import QApplication
from PyQt4.QtGui import QVBoxLayout
from PyQt4.QtGui import QWidget
from PyQt4.QtGui import QLabel

import re
import sys,os
gRootDir = os.path.join(os.getcwd(), "..")
sys.path.append(gRootDir)
from Core.Widget.LabelWithLineEditWidget import LabelWithLineEditWidget

gCfgName = "para.cfg"
#gParrern = r"^(.*)\b=\b*(.*)$"
gParrern = r"^([\S]*)[\s]*=[\s]*(.*)$"

class CtrlWidget(QWidget):
    def __init__(self, parent=None):
        QWidget.__init__(self, parent)

        self.mLayout = QVBoxLayout()
        widgets = self.GetALabelWithLineEditWidgets()

        for widget in widgets: 
            self.mLayout.addWidget(widget)
        self.mLayout.addStretch()

        self.setLayout(self.mLayout)

    def GetALabelWithLineEditWidgets(self):
        cfgFile = open(gCfgName, "r")
        widgets = []

        for line in cfgFile:
            #print(line) 

            p = re.compile(gParrern)
            m = p.match(line)

            #print(m.group(1))
            #print(m.group(2))

            labelStr = m.group(1) + "："
            lineEditStr = m.group(2)
            widget = LabelWithLineEditWidget(self, labelStr, lineEditStr)
            widget.setEnabled(False)
            widgets.append(widget)
            
        cfgFile.close()

        return widgets 

if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)

    win = CtrlWidget()
    win.show()

    sys.exit(app.exec_())


