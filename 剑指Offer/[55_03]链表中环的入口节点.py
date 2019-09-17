# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def EntryNodeOfLoop(self, pHead):
        # write code here
        if pHead==None or pHead.next==None:
            return None
        fast = pHead
        slow = pHead
        while fast!=None and fast.next!=None:
            slow = slow.next
            fast = fast.next.next
            if slow == fast: # 第一次相遇
                slow = pHead # 重置slow
                while fast!=slow:
                    fast = fast.next
                    slow = slow.next
                return slow
        return None