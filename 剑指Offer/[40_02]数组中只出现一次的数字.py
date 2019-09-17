# -*- coding:utf-8 -*-
class Solution:
    # 返回[a,b] 其中ab是出现一次的两个数字
    def FindNumsAppearOnce(self, array):
        # write code here
        if len(array)<2:
            return []
        resultExclusiveOR = 0
        length = len(array)
        for i in array:
            resultExclusiveOR ^= i
        firstBitIs1 = self.FindFisrtBitIs1(resultExclusiveOR)
        num1,num2 =0,0
        for i in array:
            if self.BitIs1(i,firstBitIs1):
                num1 ^= i
            else:
                num2 ^= i
        return num1,num2
    def FindFisrtBitIs1(self,num):
        indexBit = 0
        while num & 1 ==0 and indexBit<=32:
            indexBit += 1
            num = num>>1
        return indexBit
    def BitIs1(self,num,indexBit):
        num = num >> indexBit
        return num & 1