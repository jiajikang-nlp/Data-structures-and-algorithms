# -*- coding:utf-8 -*-
class Solution:
    def LastRemaining_Solution(self, n, m):
        # write code here
        if not n and not m:
            return -1
        res = range(n)
        i = 0
        while len(res)>1:
            i = (m+i-1) % len(res)
            res.pop(i) # 删除第m-1个元素
        return res[0]
		
		
		
# -*- coding:utf-8 -*-
class Solution:
    def LastRemaining_Solution(self, n, m):
        # write code here
        if not n or not m:
            return -1
        arr = []
        for i in range(n):
            arr.append(i) # 添加到列表中
        index = 0
        while len(arr)>1:
            index += m-1
            if index >len(arr):
                index = index %len(arr)
            elif index == len(arr):
                index = 0
            del arr[index]
        return arr[0]