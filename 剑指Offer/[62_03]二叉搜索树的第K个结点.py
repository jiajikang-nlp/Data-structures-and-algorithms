# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    # 返回对应节点TreeNode
    def __init__(self):
        self.count = 0
        self.ans = None
    def KthNode(self, pRoot, k):
        # write code here
        if pRoot == None or k<0:
            return None
        self.helper(pRoot,k)
        return self.ans
    def helper(self,root,k):
        if self.count>k:
            return
        if root.left:
            self.helper(root.left,k)
        self.count+=1
        if self.count == k:
            self.ans = root
            return
        if root.right:
            self.helper(root.right,k)