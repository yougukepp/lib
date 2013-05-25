#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from PyQt4.QtGui import *
from PyQt4.QtCore import *
from math import atan2, sin, cos, pi

def convexHull(pS):
    assert 3 < len(pS), "凸包算法点数需要大于3" 
    points = pS[:]
    rst = []

    findPOrig(points)
    sortByAngle(points)
    rst = convexFilter(points)

    return rst


def convexFilter(pS):
    points = pS[:]
    rst = []

    rst.append(points[0])            # pOrig
    rst.append(points[1])            # p1

    i = 0
    iMax = len(points)
    for i in range(2, iMax):
        p = points[i]
        pC = p
        pB = rst.pop()
        pA = rst.pop()
        rst.append(pA)
        triPoints = (pA, pB, pC)
        if isTurnLeft(triPoints):
            rst.append(pB)
        else:
            pass

        rst.append(pC)

    return rst


def findPOrig(points):
    yMin = points[0].y();
    pOrig = points[0]
    p0s = []
    """
    寻找y最小点，若有多个点，选择x最小点
    """
    for p in points:
        if p.y() < yMin:
            yMin = p.y()
    for p in points:
        if yMin == p.y():
            p0s.append(p)
    pOrig = p0s[0]
    for p in p0s:
        if p.x() < pOrig.x():
            pOrig = p
    points.remove(pOrig)
    points.insert(0, pOrig)

def isTurnLeft(triPoints):
    rst = False
    assert 3 == len(triPoints), "判断转向必须3点"

    p0 = triPoints[0]
    p1 = triPoints[1]
    p2 = triPoints[2]

    x = p2.x() - p0.x()
    y = p2.y() - p0.y()
    p02 = QPoint(x, y)

    x = p1.x() - p0.x()
    y = p1.y() - p0.y()
    p01 = QPoint(x, y)

    d = p01.x() * p02.y() - p02.x() * p01.y()

    if d > 0:
        rst = True
    else:
        rst = False

    return rst

def sortByAngle(points):
    p0 = points[0]
    points.remove(p0)

    pointWithAngle = []
    for p in points:
        x = p.x() - p0.x()
        y = p.y() - p0.y()
        angle = atan2(y, x)
        pointWithAngle.append((angle, x + p0.x(), y + p0.y()))

    pointWithAngle.sort()

    iMax = len(points)
    for i in range(0, iMax):
        p = QPoint(pointWithAngle[i][1], pointWithAngle[i][2])
        points[i] = p

    points.insert(0, p0)

class PCentralLabel(QWidget):
  sMove = pyqtSignal(QPoint, name='sMove')
  mPoints = []
  mConvexHull = []
  mTestTurnFlag = False
  mTestSortByAngleFlag = False
  mTestConvexHullFlag = False
  
  def __init__(self, parent=None):
    QWidget.__init__(self, parent)
    self.setMouseTracking(True)

  def testTurn(self):
      self.mTestTurnFlag = True
      self.repaint()

  def testSortedByAngle(self):
      sortByAngle(self.mPoints)
      self.mTestSortByAngleFlag = True
      self.repaint()

  def testConvexHull(self):
      self.mConvexHull = convexHull(self.mPoints)
      self.mTestConvexHullFlag = True
      self.repaint()

  def paintEvent(self, event):
      painter = QPainter(self)

      painter.fillRect(0, 0, self.width(), self.height(), QColor(0, 0, 0))
      self.paintPoints(painter)

      if True == self.mTestTurnFlag:
          self.paintTestTurn(painter, self.mPoints)

      if True == self.mTestSortByAngleFlag:
          self.paintTestSortByAngle(painter)

      if True == self.mTestConvexHullFlag:
          self.paintTestConvexHull(painter)

      painter.end()

  def paintPoints(self, painter):
      i = 0
      for pLogic in self.mPoints:
          pPhy = self.logic2Phy(pLogic)

          pen = QPen(QColor(0, 255, 0))
          pen.setWidth(1)
          painter.setPen(pen)
          s = "p" + str(i)
          painter.drawText(pPhy, s)

          pen = QPen(QColor(255, 0, 0))
          pen.setWidth(5)
          painter.setPen(pen)
          painter.drawPoint(pPhy)

          i += 1
          
  def paintTestTurn(self, painter, points):
      assert 3 == len(self.mPoints), "判断转向必须3点" 

      p0 = points[0]
      p1 = points[1]
      p2 = points[2]

      pen = QPen(QColor(255, 255, 255))
      pen.setWidth(1)
      painter.setPen(pen)

      self.drawArrowLine(painter, p0, p1)
      self.drawArrowLine(painter, p0, p2)
      self.drawArrowLine(painter, p1, p2)

      if isTurnLeft((p0, p1, p2)):
          painter.drawText(100, 100, "左转")
      else:
          painter.drawText(100, 100, "右转")

      self.mTestTurnFlag = True

  def paintTestSortByAngle(self, painter):
      assert len(self.mPoints) > 1 , "2个点以下点数，无法排序"

      p0 = self.mPoints[0]
      iMax = len(self.mPoints)
      pen = QPen(QColor(255, 255, 255))
      pen.setWidth(1)
      painter.setPen(pen)
      for i in range(1, iMax):
          self.drawArrowLine(painter, p0, self.mPoints[i])

  def paintTestConvexHull(self, painter):
      assert len(self.mConvexHull) > 2,  "凸包需要至少3个点"

      pLast = self.mConvexHull[0]
      pCurrent = QPoint()
      iMax = len(self.mConvexHull) 
      for i in range(1, iMax):
          pCurrent = self.mConvexHull[i] 
          pen = QPen(QColor(255, 255, 255))
          pen.setWidth(1)
          painter.setPen(pen)
          painter.drawLine(self.logic2Phy(pLast), self.logic2Phy(pCurrent))
          pLast = pCurrent;
      " 绘制闭合线 "
      painter.drawLine(self.logic2Phy(self.mConvexHull[0]), self.logic2Phy(self.mConvexHull[iMax-1]))

  def drawArrowLine(self, painter, pStart , pEnd):
      tanAngle = (pEnd.y() - pStart.y()) / (pEnd.x() - pStart.x())
      step = 0.08 * (pEnd.x() - pStart.x())
      pArrow = QPoint()
      pArrow.setX(pEnd.x() + step)
      pArrow.setY(pEnd.y() + step * tanAngle)

      pTemp = self.rotate(pEnd, pArrow, 9 * pi / 8)
      painter.drawLine(self.logic2Phy(pStart), self.logic2Phy(pEnd))
      painter.drawLine(self.logic2Phy(pEnd), self.logic2Phy(pTemp))
      pTemp = self.rotate(pEnd, pArrow, -9 * pi / 8)
      painter.drawLine(self.logic2Phy(pEnd), self.logic2Phy(pTemp))

  def mouseMoveEvent(self, event):
      p = self.phy2Logic(event.pos())
      self.sMove.emit(p)

  def mouseReleaseEvent(self, event):
      if Qt.LeftButton == event.button():
          p = self.phy2Logic(event.pos())
          self.mPoints.append(p)
          self.repaint()
      else:
          pass

  def phy2Logic(self, pPhy):
      x = pPhy.x()
      y = pPhy.y()
      y = self.height() - y
      p = QPoint(x, y)
      return p

  def logic2Phy(self, pLogic):
      return self.phy2Logic(pLogic)

  def rotate(self, pOrig, pRotated, angle):
      cosAngle = cos(angle)
      sinAngle = sin(angle)
      normalX = pRotated.x() - pOrig.x()
      normalY = pRotated.y() - pOrig.y()

      xRotated = cosAngle * normalX - sinAngle * normalY
      yRotated = sinAngle * normalX + cosAngle * normalY

      x = xRotated + pOrig.x()
      y = yRotated + pOrig.y()

      return QPoint(x, y)

class MainWindow(QMainWindow):
  def __init__(self, parent=None):
    QMainWindow.__init__(self, parent)
    self.setWindowTitle("计算几何 测试")

    self.mLabelPos = QLabel("当前位置:")
    self.mButtonTurnAngle = QPushButton("测试转向")
    self.mButtonConvexHull = QPushButton("测试凸包")
    self.mButtonSortedByAngle = QPushButton("排序")
    statusBar = QStatusBar()
    statusBar.addWidget(self.mLabelPos)
    statusBar.addWidget(self.mButtonTurnAngle)
    statusBar.addWidget(self.mButtonSortedByAngle)
    statusBar.addWidget(self.mButtonConvexHull)
    self.setStatusBar(statusBar)

    centralLabel = PCentralLabel()
    self.setCentralWidget(centralLabel)

    centralLabel.sMove.connect(self.move)
    self.mButtonTurnAngle.clicked.connect(centralLabel.testTurn)
    self.mButtonSortedByAngle.clicked.connect(centralLabel.testSortedByAngle)
    self.mButtonConvexHull.clicked.connect(centralLabel.testConvexHull)

    #self.mButtonTurnAngle.setEnabled(False)
    #self.mButtonSortedByAngle.setEnabled(False)

    #self.resize(1000, 800)
    self.showMaximized()

  def move(self, pos):
      sPos = "%d,%d" % (pos.x(), pos.y())
      self.mLabelPos.setText("当前位置:" + sPos)

if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)

    win = MainWindow()
    win.show()

    sys.exit(app.exec_())

