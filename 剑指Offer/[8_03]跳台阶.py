# -*- coding:utf-8 -*-
class Solution:
    def jumpFloor(self, number):
        # write code here
        if number==1 or number==2:
            return number
        a=1;b=2;c=3
        for i in range(3,number+1):
            c=a+b;a=b;b=c
        return c