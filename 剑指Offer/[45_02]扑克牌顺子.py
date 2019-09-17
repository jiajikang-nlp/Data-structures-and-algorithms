# -*- coding:utf-8 -*-
class Solution:
    def IsContinuous(self, numbers):
        # write code here
        if not numbers:
            return False
        numbers.sort() # 排序
        zeros = numbers.count(0) # 统计0的个数
        gaps = 0 # 统计空缺的个数
        small = zeros # 0的个数
        big = small + 1 # 0的个数+1
        while big < len(numbers): 
            if numbers[small] == numbers[big]: # 相邻如果相等
                return False
            gaps += numbers[big]-numbers[small] - 1
            small = big # 一直保持相邻
            big += 1
        return gaps<=zeros # 空缺的总数<=0的个数，连续
        