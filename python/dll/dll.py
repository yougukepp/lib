#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import ctypes

#lib_handle = ctypes.CDLL('./pp.so')
lib_handle = ctypes.CDLL('./pp.dll')
t= lib_handle.test

t.argtypes = [ctypes.c_void_p, ctypes.c_int]
t.restypes = ctypes.c_int

sBuf = "0123456789"

rst = t(sBuf, len(sBuf))

print()
print(rst)
