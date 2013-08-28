#!/usr/bin/env python3
# -- coding utf-8 --

from random import *

from PyQt4.QtGui import QApplication
from PyQt4.QtGui import QWidget
from PyQt4.QtGui import QPainter
from PyQt4.QtGui import QColor
from PyQt4.QtGui import QPen
from PyQt4.QtGui import QBrush
from PyQt4.QtGui import QBitmap
from PyQt4.QtGui import QPixmap

from PyQt4.QtCore import Qt
from PyQt4.QtCore import QTimer
from PyQt4.QtCore import QPoint
#from PyQt4.QtCore import pyqtSignal

def sampling(needNums, sampleNums):
  assert 1 == needNums
  assert needNums <= sampleNums, "抽样数必须小于样本数"
  rst = []
  dealedNums = 0
  readySampleNums = 0
  while True:
    aUniform = random()
    if (sampleNums - dealedNums ) * aUniform >= needNums - readySampleNums:
      pass
    else:
      rst.append(dealedNums)
      readySampleNums += 1
      if readySampleNums == needNums:
        break
    dealedNums += 1

  return rst

class HoleCanvas(QWidget):

    #msMove = pyqtSignal(Point, name='msMove')

    def __init__(self, parent=None):
        QWidget.__init__(self, parent)

        self.circleCenter = QPoint()
        self.circleR = 0
        self.doubleBuffer = QPixmap()

        self.setAttribute(Qt.WA_TranslucentBackground, True) 
        self.setWindowFlags(Qt.FramelessWindowHint)

        timerDraw = QTimer(self)
        timerUpdate = QTimer(self)
        timerDraw.timeout.connect(self.drawCircle)
        timerUpdate.timeout.connect(self.update)
        timerDraw.start(1);
        timerUpdate.start(300);

        #self.setMouseTracking(True)

    def paintEvent(self, event): 
        
        p = QPainter(self) 
        mask = self.doubleBuffer.createMaskFromColor(QColor(255,0,0), Qt.MaskInColor)
        self.doubleBuffer.setMask(mask); 

        p.drawPixmap(0, 0, self.width(), self.height(), self.doubleBuffer);

    def drawCircle(self):
        self.doubleBuffer = QPixmap(self.width(), self.height())
        
        p = QPainter(self.doubleBuffer)
        pen = QPen(QColor(255,0,0))
        pen.setWidth(1)
        p.setPen(pen)
        brush = QBrush(QColor(255,0,0))
        p.setBrush(brush)

        p.fillRect(0, 0, self.width(), self.height(), QColor(0,255,0))

        x = self.width() / 2
        y = self.height() / 2

        (x, y) = self.movePos(x, y)


        p.drawEllipse(self.circleCenter.x() - self.circleR,
                self.circleCenter.y() - self.circleR,
                2 * self.circleR,
                2 * self.circleR);
        print("draw:" + str(x) + "," + str(y))

        self.circleCenter = QPoint(x, y)
        self.circleR = min(self.width(), self.height()) / 4;

    def movePos(self, x, y):
        r = min(self.width(), self.height()) / 2
        changeRange = r - self.circleR

        x = x + sampling(1, changeRange * 2 + 1)[0] - changeRange
        y = y + sampling(1, changeRange * 2 + 1)[0] - changeRange
        return (x, y) 
    
if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)

    win = HoleCanvas()
    win.show()

    sys.exit(app.exec_())

