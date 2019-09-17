# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def FindFirstCommonNode(self, pHead1, pHead2):
        # write code here
        result = set()
        while pHead1:
            result.add(pHead1)
            pHead1 = pHead1.next
        while pHead2:
            if pHead2 in result:
                return pHead2
            pHead2 = pHead2.next
			
思路三：
				       使用python中的set()函数
					   1：先将pHead1中的添加到集合中
					   2：遍历pHead2的过程中：判断phead1中是否含有，如果有那就是我们要的结果，return即可