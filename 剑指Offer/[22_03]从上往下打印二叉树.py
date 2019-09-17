# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    # 返回从上到下每个节点值列表，例：[1,2,3]
    def PrintFromTopToBottom(self, root):
        # write code here
        queue = []
        result = []# 列表-最终返回的结果
        if root==None:
            return result
        queue.append(root); # 添加根节点
        while queue:# 当队列不为空
            tem = queue.pop(0)
            result.append(tem.val)
            if tem.left != None:
                queue.append(tem.left)
            if tem.right != None:
                queue.append(tem.right)
        return result
            
            