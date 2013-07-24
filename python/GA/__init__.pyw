#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from PyQt4.QtGui import *
from PyQt4.QtCore import *

from gui.HyGaMainWindow import HyGaMainWindow
#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from dataType.HyGaVector import HyGaVector
from algorithm.HyGaTurn import HyGaIsCollineation, HyGaIsTurnLeft, HyGaIsTurnRight
from algorithm.HyGaConvexHull import HyGaConvexHull

if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)

    win = HyGaMainWindow()
    win.show()

    print(sys.path)
    print(__name__)
    dir(HyGaMainWindow)

    sys.exit(app.exec_())

