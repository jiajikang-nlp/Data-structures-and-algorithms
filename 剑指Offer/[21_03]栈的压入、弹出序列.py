# -*- coding:utf-8 -*-
class Solution:
    def IsPopOrder(self, pushV, popV):
        # write code here
        stack = [] # 创建一个列表-辅助栈
        j = 0
        if len(pushV)!=len(popV) or (len(popV)==0 or len(pushV)==0):
            return false
        for i in pushV:
            stack.append(i)
            while stack and stack[-1]==popV[j]: # 遇到相同元素，弹出
                stack.pop()
                j+=1
        return len(stack)==0