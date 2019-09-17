# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    # 返回二维列表，内部每个列表表示找到的路径
    def FindPath(self, root, expectNumber):
        # write code here
        result = [] # 创建一个返回列表，内容还是一个列表，也就是一个嵌套列表
        if not root:
            return result
        #如果只有根节点或者找到叶子节点，我们就把其值返回
        if not root.left and not root.right and root.val == expectNumber:
            return [[root.val]]# 列表形式返回
        else:
            #如果不是叶子节点，我们分别对根节点的左子树、右子树进行递归，注意修改变量:
            left = self.FindPath(root.left,expectNumber-root.val)
            right = self.FindPath(root.right,expectNumber-root.val)
            for item in left+right:
                result.append([root.val]+item)
            return result