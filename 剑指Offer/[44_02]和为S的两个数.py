# -*- coding:utf-8 -*-
class Solution:
    def FindNumbersWithSum(self, array, tsum):
        # write code here
        lis = [] # 用于返回的结果
        if len(array)==0 or array == None:
            return lis # 返回空列表
        length = len(array) # 获取数组的长度
        # 创建两个指针：开头和结尾
        start = 0
        end = length -1
        while start < end and end>0:
            if array[start] + array[end] == tsum:
                lis.append(array[start])
                lis.append(array[end])
                return lis
            if array[start] + array[end] > tsum:
                end -= 1
            if array[start] + array[end] < tsum:
                start += 1
        return lis