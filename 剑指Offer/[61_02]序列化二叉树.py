# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def Serialize(self, root):
        # write code here
        if not root:
            return '#'
        return str(root.val) + ',' + self.Serialize(root.left) + ',' + self.Serialize(root.right)
    
    def Deserialize(self, s):
        # write code here
        lis = s.split(',') # 以','号分隔开字符串数组
        return self.DeserializeTree(lis)
    
    def DeserializeTree(self,lis):
        if len(lis)<=0:
            return None
        val = lis.pop(0)
        root = None
        if val != '#':
            root = TreeNode(int(val))
            root.left = self.DeserializeTree(lis)
            root.right = self.DeserializeTree(lis)
        return root