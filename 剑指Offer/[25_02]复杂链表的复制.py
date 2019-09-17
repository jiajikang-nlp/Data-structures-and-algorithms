# -*- coding:utf-8 -*-
# class RandomListNode:
#     def __init__(self, x):
#         self.label = x
#         self.next = None
#         self.random = None
class Solution:
    # 返回 RandomListNode
    def Clone(self, pHead):
        # write code here
        if not pHead:
            return pHead
        cloNode = pHead
        while cloNode:
            node = RandomListNode(cloNode.label)
            node.next = cloNode.next
            cloNode.next = node
            cloNode = node.next # 下一次操作
        cloNode = pHead
        while cloNode:
            node = cloNode.next# 指向复制的结点
            if cloNode.random: # 如果原节点有特殊指针
                node.random = cloNode.random.next # #则复制的节点的特殊指针指向原节点的特殊指针指向的下一个值
            cloNode = node.next
        cloNode = pHead
        pHead = pHead.next # 如果没有这一步的话：最后得到的是pHead原链表的开头
        while cloNode.next:
            node = cloNode.next
            cloNode.next = node.next
            cloNode = node # 下一个节点的操作
        return pHead
		
		
https://www.cnblogs.com/tianqizhi/p/9769529.html