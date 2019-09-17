# -*- coding:utf-8 -*-
class Solution:
    def __init__(self):
        self.stack1 = []
        self.stack2 = []
        #入栈函数
    def push(self, node):
        # write code here
        # 添加元素进入到stack1中
        self.stack1.append(node)
        #出栈函数
    def pop(self):
        # return xx
        if not self.stack2: # 如果stack2不为空
            while self.stack1: # 循环stack1
                # 将stack1的出栈数据，添加到stack2中
                self.stack2.append(self.stack1.pop())
        return self.stack2.pop() # 返回stack2的出栈数据,pop(-1),-1:也就是删除最后一个列表值
                