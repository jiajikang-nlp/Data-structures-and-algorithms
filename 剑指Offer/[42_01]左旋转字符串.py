# -*- coding:utf-8 -*-
class Solution:
    def LeftRotateString(self, s, n):
        # write code here
        if not s:
            return ''
        res1 = list(reversed(s[:n])) # 前n个反转
        res2 = list(reversed(s[n:])) # 后s-n个反转
        res = res1 + res2
        res = list(reversed(res)) # 整体从后往前打印
        return ''.join(res)
		
		
# -*- coding:utf-8 -*-
class Solution:
    def LeftRotateString(self, s, n):
        # write code here
        if not s:
            return '' 
        res = list(reversed(s)) # 整体旋转
        res1 = list(reversed(res[:n]))
        res2 = list(reversed(res[n:]))
        res = res1 + res2
        return ''.join(res)