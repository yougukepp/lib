#!/usr/bin/env python3
# -- coding utf-8 -- 

class Person:
    def __init__(self, name = ""):
        self.name = name

    def SetName(self, name):
        self.name = name
        
    def GetName(self):
        return self.name
    
    def Greet(self):
        print("Hello, my name is:" + self.name)

if __name__ == "__main__":
    pp = Person("pp")
    print("pp.GetName():                ", pp.GetName())
    pp.SetName("PengPeng")
    print("pp.SetName(\"PengPeng\"):      ", pp.GetName())
    print("pp.Greet():                   ", end = ""); pp.Greet()


       
    
