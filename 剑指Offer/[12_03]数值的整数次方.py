# -*- coding:utf-8 -*-
class Solution:
    def Power(self, base, exponent):
        # write code here
        # 当exponent为负数
        if exponent<0:
            return 1/self.getPower(base,-exponent)
        else:
            return self.getPower(base,exponent)
    def getPower(self,base,exp):
        if exp == 0:
            return 1
        elif exp == 1:
            return base
        res = self.Power(base,exp>>1)
        res *= res
        if exp & 1 == 1:
            res *= base
        return res