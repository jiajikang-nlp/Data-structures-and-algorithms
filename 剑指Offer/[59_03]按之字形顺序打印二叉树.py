# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# 如果当前打印的是奇数层，则先保存左子节点，后保存右字节点到一个栈中
#  如果当前打印的是偶数层，则先保存右字节点再保存左子节点到另一个栈中
class Solution:
    def Print(self, pRoot):
        # write code here
        ret = []
        if not pRoot:
            return ret
        curLayer = [pRoot] # 当前层，且吧根节点存入
        cnt = 0
        while curLayer: # 遍历当前层
            nextLayer = [] # 用于存储下一层的节点
            tmp = []
            # 遍历当前层
            for node in curLayer:
                tmp.append(node.val) # 当且层节点的值添加到tmp中
                if node.left:# 如果左子树不为空
                    nextLayer.append(node.left)
                if node.right: # 如果右子树不为空
                    nextLayer.append(node.right)
            if cnt==0:
                ret.append(tmp)
            else:
                ret.append(tmp[::-1]) # 逆序添加
            curLayer = nextLayer # 下一层节点赋值给当前层
            cnt = (cnt+1) % 2 # 层数增加求余判断奇偶
        return ret