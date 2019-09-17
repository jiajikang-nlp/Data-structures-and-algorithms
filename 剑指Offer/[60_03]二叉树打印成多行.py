# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    # 返回二维列表[[1,2],[4,5]]
    def Print(self, pRoot):
        # write code here
        ret = [] # 结果返回对象
        if not pRoot:
            return ret
        curLayer = [] # 当前行
        curLayer.append(pRoot); # 将根节点添加到curList中
        while curLayer:
            curList = [] # 存储当前行元素
            queue = [] # 队列
            for node in curLayer:# 遍历当前行
                curList.append(node.val)# 当前行元素添加到curList中
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            ret.append(curList) # 当前行添加到ret中
            curLayer = queue # 下一层给作为当前层
        return ret;
            