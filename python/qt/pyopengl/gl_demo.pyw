#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
os:winxp sp3 32
pyqt:PyQt4-4.11.4-gpl-Py3.4-Qt4.8.7-x32
opengl:pip install PyOpenGL(PyOpenGL3.1.0)
"""

import sys
from PyQt4 import QtGui
from PyQt4 import QtCore
from PyQt4 import QtOpenGL

try:
    from OpenGL import GL
except ImportError: 
    app = QtGui.QApplication(sys.argv)
    QtGui.QMessageBox.critical(None, "OpenGL演示程序",
            "需要安装PyOpenGL(使用pip installed PyOpenGL).\n")
    sys.exit(1) 
    
class GLWindow(QtGui.QWidget):
    def __init__(self):
        super(GLWindow, self).__init__()

        # 创建控件
        self.mGlWidget = GLWidget()
        self.mXSlider = self.createSlider()
        self.mYSlider = self.createSlider()
        self.mZSlider = self.createSlider()
        self.mXSlider.setValue(0)
        self.mYSlider.setValue(0)
        self.mZSlider.setValue(0)

        # 标题
        self.setWindowTitle("PyQt&OpenGL 演示")

        mainLayout = QtGui.QHBoxLayout()
        mainLayout.addWidget(self.mGlWidget)
        mainLayout.addWidget(self.mXSlider)
        mainLayout.addWidget(self.mYSlider)
        mainLayout.addWidget(self.mZSlider)
        self.setLayout(mainLayout)

        # 连接事件
        self.mXSlider.valueChanged.connect(self.mGlWidget.SetXRotation)
        self.mYSlider.valueChanged.connect(self.mGlWidget.SetYRotation)
        self.mZSlider.valueChanged.connect(self.mGlWidget.SetZRotation)

    def createSlider(self):
        slider = QtGui.QSlider(QtCore.Qt.Vertical)
        slider.setRange(0, 360)
        """
        slider.setSingleStep(16)
        slider.setPageStep(15 * 16)
        slider.setTickInterval(15 * 16)
        slider.setTickPosition(QtGui.QSlider.TicksRight)
        """

        return slider


class GLWidget(QtOpenGL.QGLWidget):
    def __init__(self, parent=None):
        super(GLWidget, self).__init__(parent)

        # 三维物体 及其初始角度
        self.mObj = 0
        self.mXRot = 0
        self.mYRot = 0
        self.mZRot = 0

    def initializeGL(self):
        #self.qglClearColor(QtCore.Qt.black)
        self.qglClearColor(QtCore.Qt.red)
        self.mObj = self.MakeObj()
        GL.glShadeModel(GL.GL_FLAT)
        GL.glEnable(GL.GL_DEPTH_TEST)
        GL.glEnable(GL.GL_CULL_FACE)
        print("initializeGL")

    def paintGL(self):
        print("paintGL")
        """
        GL.glClear(GL.GL_COLOR_BUFFER_BIT | GL.GL_DEPTH_BUFFER_BIT)
        GL.glLoadIdentity()
        GL.glTranslated(0.0, 0.0, -10.0)
        GL.glRotated(self.xRot / 16.0, 1.0, 0.0, 0.0)
        GL.glRotated(self.yRot / 16.0, 0.0, 1.0, 0.0)
        GL.glRotated(self.zRot / 16.0, 0.0, 0.0, 1.0)
        GL.glCallList(self.object)
        """

    def MakeObj(self):
        print("MakeObj")

    def SetXRotation(self, angle):
        print("SetXRotation")
        print(angle)

    def SetYRotation(self, angle):
        print("SetXRotation")
        print(angle)

    def SetZRotation(self, angle):
        print("SetXRotation")
        print(angle)

if __name__ == '__main__':
    app = QtGui.QApplication(sys.argv)
    win= GLWindow()
    win.showMaximized()
    sys.exit(app.exec_())

"""
    def setXRotation(self, angle):
        angle = self.normalizeAngle(angle)
        if angle != self.xRot:
            self.xRot = angle
            self.xRotationChanged.emit(angle)
            self.updateGL()

    def setYRotation(self, angle):
        angle = self.normalizeAngle(angle)
        if angle != self.yRot:
            self.yRot = angle
            self.yRotationChanged.emit(angle)
            self.updateGL()

    def setZRotation(self, angle):
        angle = self.normalizeAngle(angle)
        if angle != self.zRot:
            self.zRot = angle
            self.zRotationChanged.emit(angle)
            self.updateGL()

    def paintGL(self):
        GL.glClear(GL.GL_COLOR_BUFFER_BIT | GL.GL_DEPTH_BUFFER_BIT)
        GL.glLoadIdentity()
        GL.glTranslated(0.0, 0.0, -10.0)
        GL.glRotated(self.xRot / 16.0, 1.0, 0.0, 0.0)
        GL.glRotated(self.yRot / 16.0, 0.0, 1.0, 0.0)
        GL.glRotated(self.zRot / 16.0, 0.0, 0.0, 1.0)
        GL.glCallList(self.object)

    def resizeGL(self, width, height):
        side = min(width, height)
        if side < 0:
            return

        GL.glViewport((width - side) // 2, (height - side) // 2, side, side)

        GL.glMatrixMode(GL.GL_PROJECTION)
        GL.glLoadIdentity()
        GL.glOrtho(-0.5, +0.5, +0.5, -0.5, 4.0, 15.0)
        GL.glMatrixMode(GL.GL_MODELVIEW)

    def makeObject(self):
        genList = GL.glGenLists(1)
        GL.glNewList(genList, GL.GL_COMPILE)

        GL.glBegin(GL.GL_QUADS)

        x1 = +0.06
        y1 = -0.14
        x2 = +0.14
        y2 = -0.06
        x3 = +0.08
        y3 = +0.00
        x4 = +0.30
        y4 = +0.22

        self.quad(x1, y1, x2, y2, y2, x2, y1, x1)
        self.quad(x3, y3, x4, y4, y4, x4, y3, x3)

        self.extrude(x1, y1, x2, y2)
        self.extrude(x2, y2, y2, x2)
        self.extrude(y2, x2, y1, x1)
        self.extrude(y1, x1, x1, y1)
        self.extrude(x3, y3, x4, y4)
        self.extrude(x4, y4, y4, x4)
        self.extrude(y4, x4, y3, x3)

        NumSectors = 200

        for i in range(NumSectors):
            angle1 = (i * 2 * math.pi) / NumSectors
            x5 = 0.30 * math.sin(angle1)
            y5 = 0.30 * math.cos(angle1)
            x6 = 0.20 * math.sin(angle1)
            y6 = 0.20 * math.cos(angle1)

            angle2 = ((i + 1) * 2 * math.pi) / NumSectors
            x7 = 0.20 * math.sin(angle2)
            y7 = 0.20 * math.cos(angle2)
            x8 = 0.30 * math.sin(angle2)
            y8 = 0.30 * math.cos(angle2)

            self.quad(x5, y5, x6, y6, x7, y7, x8, y8)

            self.extrude(x6, y6, x7, y7)
            self.extrude(x8, y8, x5, y5)

        GL.glEnd()
        GL.glEndList()

        return genList

    def quad(self, x1, y1, x2, y2, x3, y3, x4, y4):
        self.qglColor(self.trolltechGreen)

        GL.glVertex3d(x1, y1, -0.05)
        GL.glVertex3d(x2, y2, -0.05)
        GL.glVertex3d(x3, y3, -0.05)
        GL.glVertex3d(x4, y4, -0.05)

        GL.glVertex3d(x4, y4, +0.05)
        GL.glVertex3d(x3, y3, +0.05)
        GL.glVertex3d(x2, y2, +0.05)
        GL.glVertex3d(x1, y1, +0.05)

    def extrude(self, x1, y1, x2, y2):
        self.qglColor(self.trolltechGreen.dark(250 + int(100 * x1)))

        GL.glVertex3d(x1, y1, +0.05)
        GL.glVertex3d(x2, y2, +0.05)
        GL.glVertex3d(x2, y2, -0.05)
        GL.glVertex3d(x1, y1, -0.05)

    def normalizeAngle(self, angle):
        while angle < 0:
            angle += 360 * 16
        while angle > 360 * 16:
            angle -= 360 * 16
        return angle


"""
