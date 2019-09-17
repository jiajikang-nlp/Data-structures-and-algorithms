# -*- coding:utf-8 -*-
class Solution:
    def Sum_Solution(self, n):
        # write code here
        # return sum(list(range(1,n+1)))
        ans = n
        temp = n >0 and self.Sum_Solution(n-1)
        ans = ans + temp
        return ans