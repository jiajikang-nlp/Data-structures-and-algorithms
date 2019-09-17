# -*- coding:utf-8 -*-
class Solution:
    def VerifySquenceOfBST(self,sequence):
        # write code here
        if len(sequence)==0:
            return False
        index = 0
        for i in range(len(sequence)):
            if sequence[i]>sequence[-1]:  #直到符合条件适合：直到右子树的第一个节点>根节点
                index = i# 获取临界点
                break
        for j in range(i,len(sequence)):
            if sequence[j]<sequence[-1]:# 右子树都是大于根节点的
                return False
				
        left = True
        right = True
        if len(sequence[:index])>0:
            left = self.VerifySquenceOfBST(sequence[:index])
        if len(sequence[index:-1])>0:
            right = self.VerifySquenceOfBST(sequence[index:-1])
        return left and right