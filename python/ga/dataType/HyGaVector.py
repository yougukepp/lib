#!/usr/bin/env python3
# -*- coding: utf-8 -*-

class HyGaVector():
    x = 0
    y = 0

    def __init__(self, p0, p1):
        self.x = p1.X() - p0.X()
        self.y = p1.Y() - p0.Y()

    def print(self):
        print("(" + str(self.X()) + "," + str(self.Y()) + ")", end = "")

    def X(self):
        return self.x;

    def Y(self):
        return self.y;
