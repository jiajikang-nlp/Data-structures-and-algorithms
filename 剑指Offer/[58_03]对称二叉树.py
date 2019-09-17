# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def isSymmetrical(self, pRoot):
        # write code here
        if pRoot==None:
            return True
        return self.isSymmetrical2(pRoot.left,pRoot.right)
    def isSymmetrical2(self,left,right):
        if left==None and right==None:
            return True
        if left==None or right==None:
            return False
        if left.val == right.val:
            return self.isSymmetrical2(left.left,right.right) and self.isSymmetrical2(left.right,right.left)
        return False