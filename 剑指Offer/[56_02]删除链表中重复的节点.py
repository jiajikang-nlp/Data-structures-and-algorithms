# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def deleteDuplication(self, pHead):
        # write code here
        if pHead == None:
            return None
        head = ListNode(0) # 头结点,创建一个零时节点，并将和链表连接，用于结果返回
        head.next = pHead #  头结点指向首元结点：也就是和链表连接
        
        cur = pHead
        pre = head # 前驱节点,前驱节点指向头结点
        while cur and cur.next: # 当前节点和当前节点的下一个节点不为空
            if cur.val != cur.next.val:# 当前节点和当前节点的下一个节点值不相同
                cur = cur.next
                pre = pre.next
            else:
                val = cur.val # 记录当前的值，用作下次判断相同值处理
                while cur and cur.val == val: # 过滤掉连续相同的值
                    cur = cur.next
                pre.next = cur
        return head.next
                