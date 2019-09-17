# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    # 返回构造的TreeNode根节点
    def reConstructBinaryTree(self, pre, tin):
        # write code here
        # pre：前序，tin：中序
        if len(pre) == 0:
            return None
        elif len(pre) == 1:
            return TreeNode(pre[0]) # 返回根节点：1
        else:
            root = TreeNode(pre[0]) # 获取根节点root=1
            # index(1):如果tin中包含1，则返回开始的索引值
            pos = tin.index(pre[0]) # 获取中序序列中的根节点root=1
            # 递归-分别构建左、右子树
            root.left = self.reConstructBinaryTree(pre[1:pos+1],tin[:pos])
            root.right= self.reConstructBinaryTree(pre[pos+1:],tin[pos+1:])
            return root