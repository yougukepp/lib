#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
os:winxp sp3 32
pyqt:PyQt4-4.11.4-gpl-Py3.4-Qt4.8.7-x32
opengl:pip install PyOpenGL(PyOpenGL3.1.0)
"""

import sys
import math
import array
from PyQt4 import QtGui
from PyQt4 import QtCore
from PyQt4 import QtOpenGL

from PyQt4.uic import loadUiType, loadUi
UIClass = loadUiType("gl_demo.ui")

try:
    from OpenGL import GL
except ImportError: 
    app = QtGui.QApplication(sys.argv)
    QtGui.QMessageBox.critical(None, "OpenGL演示程序",
            "需要安装PyOpenGL(使用pip installed PyOpenGL).\n")
    sys.exit(1) 

vertices = array.array('f',
        [ 0.0,  0.0,  0.0,  1.0,
          0.9,  0.0,  0.0,  1.0,
          0.0,  0.9,  0.0,  1.0,
          0.0,  0.0,  0.9,  1.0])

colors = array.array('f',
        [ 1.0,  1.0,  1.0,  1.0,
          1.0,  0.0,  0.0,  1.0,
          0.0,  1.0,  0.0,  1.0,
          0.0,  0.0,  1.0,  1.0] )

cIndices1 = array.array('B', [0, 1])
cIndices2 = array.array('B', [0, 2,])
cIndices3 = array.array('B', [0, 3,])
    
class GLWindow(QtGui.QWidget):
    def __init__(self):
        super(GLWindow, self).__init__() 
        
        self.mUi = UIClass[0]()
        self.mUi.setupUi(self)

        # 角度
        self.mXLabel = self.mUi.xLabel
        self.mXSlider = self.mUi.xSlider 
        self.mXSlider.setRange(0, 360)

        self.mYLabel = self.mUi.yLabel
        self.mYSlider = self.mUi.ySlider
        self.mYSlider.setRange(0, 360)

        self.mZLabel = self.mUi.zLabel
        self.mZSlider = self.mUi.zSlider
        self.mZSlider.setRange(0, 360)

        # 距离
        self.mDisLabel = self.mUi.disLabel
        self.mDisSlider = self.mUi.disSlider
        self.mDisSlider.setRange(0, 10)

        # 加载OpenGL控件
        self.mGlWidget = GLWidget()
        self.mGLGroupBox = self.mUi.glGroupBox
        vbox = QtGui.QVBoxLayout()
        vbox.addWidget(self.mGlWidget)
        self.mGLGroupBox.setLayout(vbox)

        # 标题
        self.setWindowTitle("PyQt&OpenGL 演示")

        # 连接事件
        self.mXSlider.valueChanged.connect(self.SetXRotation)
        self.mYSlider.valueChanged.connect(self.SetYRotation)
        self.mZSlider.valueChanged.connect(self.SetZRotation)
        self.mDisSlider.valueChanged.connect(self.SetDistance) 

    def angle2radian(self, angle):
        radian = angle * math.pi / 180
        return radian

    def SetXRotation(self, angle):
        xRadian = self.angle2radian(angle)
        self.mXLabel.setText("X%.2f" % xRadian)
        self.mGlWidget.SetNewGLValue(xRadian, 0, 0, 0 )

    def SetYRotation(self, angle):
        yRadian = self.angle2radian(angle)
        self.mYLabel.setText("Y%.2f" % yRadian)
        self.mGlWidget.SetNewGLValue(0, yRadian, 0, 0 )

    def SetZRotation(self, angle):
        zRadian = self.angle2radian(angle)
        self.mZLabel.setText("Z%.2f" % zRadian)
        self.mGlWidget.SetNewGLValue(0, 0, zRadian, 0 )

    def SetDistance(self, dis):
        self.mGlWidget.SetNewGLValue(0, 0, 0, 0)
        pass

class GLWidget(QtOpenGL.QGLWidget):
    def __init__(self, parent=None):
        super(GLWidget, self).__init__(parent)

        # 三维物体 及其初始角度
        self.mObj = 0
        self.mXRot = 0
        self.mYRot = 0
        self.mZRot = 0
        self.mDis = 0

    def initializeGL(self):
        self.PrintGLInfo()
        self.qglClearColor(QtCore.Qt.black)
        self.mObj = self.MakeObj()
        print("initializeGL") 

    def paintGL(self):
        GL.glClear(GL.GL_COLOR_BUFFER_BIT | GL.GL_DEPTH_BUFFER_BIT ) 
        GL.glViewport(0, 0, self.width(), self.height())

        # 远离眼睛 保证可以看见
        GL.glTranslated(self.mDis, 0.0, 0.0)
        GL.glRotated(self.mXRot, 1.0, 0.0, 0.0)
        GL.glRotated(self.mYRot , 0.0, 1.0, 0.0)
        GL.glRotated(self.mZRot , 0.0, 0.0, 1.0)

        GL.glEnableClientState( GL.GL_COLOR_ARRAY )
        GL.glEnableClientState( GL.GL_VERTEX_ARRAY )
        GL.glColorPointer(4, GL.GL_FLOAT, 0, colors.tostring( ))
        GL.glVertexPointer(4, GL.GL_FLOAT, 0, vertices.tostring( ))
        GL.glDrawElements(GL.GL_LINES, 2, GL.GL_UNSIGNED_BYTE, cIndices1.tostring())
        GL.glDrawElements(GL.GL_LINES, 2, GL.GL_UNSIGNED_BYTE, cIndices2.tostring())
        GL.glDrawElements(GL.GL_LINES, 2, GL.GL_UNSIGNED_BYTE, cIndices3.tostring())

        GL.glDisableClientState( GL.GL_COLOR_ARRAY )
        GL.glDisableClientState( GL.GL_VERTEX_ARRAY ) 

    def SetNewGLValue(self, x, y, z, dis):
        self.mXRot = x
        self.mYRot = y
        self.mZRot = z
        self.mDis = dis
        self.updateGL()

    def MakeObj(self):
        """
        TODO: 做3D物体
        """
        print("MakeObj")

    def PrintGLInfo(self):
        print("生产商       ", end=":")
        print(GL.glGetString(GL.GL_VENDOR))

        print("渲染器       ", end=":")
        print(GL.glGetString(GL.GL_RENDERER))

        print("OpenGL版本   ", end=":")
        print(GL.glGetString(GL.GL_VERSION))

        print("着色语言版本 ", end=":")
        print(GL.glGetString(GL.GL_SHADING_LANGUAGE_VERSION))

if __name__ == '__main__': 
    app = QtGui.QApplication(sys.argv)
    win= GLWindow()
    win.showMaximized()
    sys.exit(app.exec_())

