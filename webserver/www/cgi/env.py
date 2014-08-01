#!/usr/bin/env python
# -*- coding: utf-8 -*-

import os

print "Content-type:text/html; charset=utf-8\r\n\r\n"
print "<font size=+1>Environment</font><\b>";

for param in os.environ.keys():
      print "<p><b>%20s</b>:%s</p>" % (param, os.environ[param])
