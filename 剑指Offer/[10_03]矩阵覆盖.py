# -*- coding:utf-8 -*-
class Solution:
    def rectCover(self, number):
        # write code here
        if number==0:
            return 0
        elif number==1:
            return 1
        elif number==2:
            return 2
        else:
            step1 =1
            step2 =2
            result = 0
            for i in range(3,number+1):
                result=step1+step2
                step1 = step2
                step2 = result
            return result
            #return self.rectCover(number-1) + self.rectCover(number-2)