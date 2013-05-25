#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from random import *

def sampling(needNums, sampleNums):
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

if __name__ == '__main__':
  import sys
  for i in range(0, 5):
    samples = sampling(3, 10)
    print("第" + str(i) + "次在0至10中采3个样值结果为:")
    print(samples)

