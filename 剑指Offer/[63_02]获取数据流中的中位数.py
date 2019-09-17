# -*- coding:utf-8 -*-
from heapq import *
class Solution:
    def __init__ (self):
        self.maxheap = []
        self.minheap = []
    def Insert(self, num):
        if (len(self.maxheap)+len(self.minheap))&1: #总数为奇数插入最大堆
            if len(self.minheap)> 0:  
                if num > self.minheap[0]:#大于最小堆里的元素
                    heappush(self.minheap, num)#新数据插入最小堆
                    heappush(self.maxheap, -self.minheap[0])#最小堆中的最小插入最大堆
                    heappop(self.minheap)
                else:
                    heappush(self.maxheap, -num)
            else:
                heappush(self.maxheap, -num)
        else:                           #总数为偶数 插入最小堆
            if len(self.maxheap)> 0: #小于最大堆里的元素
                if num < -self.maxheap[0]:
                    heappush(self.maxheap, -num)#新数据插入最大堆
                    heappush(self.minheap, -self.maxheap[0])#最大堆中的最大元素插入最小堆
                    heappop(self.maxheap)
                else:
                    heappush(self.minheap, num)
            else:
                heappush(self.minheap, num)
        #print (self.minheap)
    def GetMedian(self,n=None):
        if (len(self.maxheap)+len(self.minheap))&1:
            mid = self.minheap[0]
        else:
            mid = (self.minheap[0]-self.maxheap[0])/2.0
        return mid
