# -*- coding:utf-8 -*-
class Solution:
    def maxInWindows(self, num, size):
        # write code here
        
        maxqueue = [] # 存放可能是最大值的下标
        maxlist = [] # 存放窗口中最大值2，3,4:4
        n = len(num) # 数组的长度
        if n==0 or size==0 or size>n:
            return maxlist
        for i in range(n): # 遍历数组
            if len(maxqueue)>0 and i-size>=maxqueue[0]:# 判断队首下标对应的元素是否已经滑出窗口
                maxqueue.pop(0)
            while len(maxqueue)>0 and num[i]>num[maxqueue[-1]]:
                maxqueue.pop()
            maxqueue.append(i)
            if i>=size-1:
                maxlist.append(num[maxqueue[0]])
        return maxlist
            
        