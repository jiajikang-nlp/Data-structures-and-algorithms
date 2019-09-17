# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
        # 获取树的深度
    def IsBalanced_Solution(self, pRoot):
        # write code here
        self.flag = True
        self.getDepth(pRoot)
        return self.flag
    def getDepth(self,pRoot):
        if not pRoot or self.flag==False:
            return 0
        left = self.getDepth(pRoot.left)
        right = self.getDepth(pRoot.right)
        if abs(left-right)>1:
            self.flag = False
        return left+1 if left>right else right+1
        
        
