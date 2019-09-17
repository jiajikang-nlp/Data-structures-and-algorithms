from functools import cmp_to_key
class Solution:
    def cmp(self,a,b):
        if a+b>b+a:
            return 1
        if a+b<b+a:
            return -1
        else:
            return 0
    def PrintMinNumber(self,numbers):
        if not numbers:
            return ""
        number = list(map(str,numbers))
        number.sort(key=cmp_to_key(self.cmp))
        return "".join(number).lstrip('0') or '0'    




# -*- coding:utf-8 -*-
class Solution:
    def PrintMinNumber(self, numbers):
        # write code here
        if len(numbers)==0:
            return ''
        compare = lambda a,b:cmp(str(a)+str(b),str(b)+str(a))
        min_string = sorted(numbers,cmp=compare)
        return ''.join(str(s) for s in min_string)
		
