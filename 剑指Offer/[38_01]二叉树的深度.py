# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def TreeDepth(self, pRoot):
        # write code here
        if pRoot == None:
            return 0
        left1 = self.TreeDepth(pRoot.left)
        right1 = self.TreeDepth(pRoot.right)
        res = left1 = (left1 if(left1>right1) else right1)
        return res+1
    