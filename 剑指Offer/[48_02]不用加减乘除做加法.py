# -*- coding:utf-8 -*-
class Solution:
    def Add(self, num1, num2):
        # write code here
        while num2 != 0:
            temp = num1^num2; # 不进位
            num2 = (num1&num2)<<1 # 进位部分
            num1 = temp & 0xFFFFFFFF
        return num1 if num1>> 31==0 else num1-4294967296