# -*- coding:utf-8 -*-
class Solution:
    def Permutation(self, ss):
        # write code here
        if not ss:
            return [] # 如果不为空，就返回一个空列表
        res = [] # 创建一个空列表，进行存储返回结果
        self.helper(ss,res,'')
        return sorted(list(set(res))) # set去重，list(set(res))去重的列表，sorted()排序
    def helper(self,ss,res,path):
        if not ss:# 如果不为空
            res.append(path) # 实现添加
        else:# 如果为空就开始遍历
            for i in range(len(ss)): #遍历ss
                self.helper(ss[:i]+ss[i+1:],res,path+ss[i]) # 从0位置开始到i，再从i+1的位置到最后，第三个参数