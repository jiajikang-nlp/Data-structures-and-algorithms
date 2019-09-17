# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def FindKthToTail(self, head, k):
        # write code here
        if head==None or k<=0:
            return None;
        # 设置两个指针，p2指针先走(k-1)步，然后再一起走，当p2为最后一个时，p1就为倒数第k个数
        p1 = head
        p2 = head
        # 让p2先走，走k-1步，如果k大于链表长度返回空，否则继续走，
        while k>1:
            if p2.next!=None:
                p2=p2.next
                k-=1
            else:
                return None
        # 两个指针一起走，一直走到p2为最后一个元素，p1即为所求。
        while p2.next!=None:
            p1=p1.next
            p2=p2.next
        return p1