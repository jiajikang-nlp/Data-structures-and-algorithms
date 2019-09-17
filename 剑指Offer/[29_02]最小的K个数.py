# -*- coding:utf-8 -*-

class Solution:
    def GetLeastNumbers_Solution(self, tinput, k):
        # write code here
        result = []
        if len(tinput)==0 or k<=0 or k>len(tinput):
            return result
        tinput.sort() # 默认是升序排序
        for i in range(k):
            result.append(tinput[i])
        return result