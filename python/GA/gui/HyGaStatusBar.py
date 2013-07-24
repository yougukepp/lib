#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from PyQt4.QtGui import *
from PyQt4.QtCore import *

class HyGaStatusBar(QStatusBar):
    def __init__(self, parent=None):
        QStatusBar.__init__(self, parent)

        self.mLabelPos = QLabel("当前位置:(nan,nan)")
        self.mLabelTestName = QLabel("当前测试:凸包")
        self.addWidget(self.mLabelPos)
        self.addWidget(self.mLabelTestName)

    def CurrentChanged(self, testItemName):
        labelText = "当前测试:" + testItemName
        self.mLabelTestName.setText(labelText)

    def Move(self, pos):
        labelText = "当前位置:(" + str(pos.X()) + "," + str(pos.Y()) + ")"
        self.mLabelPos.setText(labelText)


