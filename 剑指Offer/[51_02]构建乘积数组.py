# -*- coding:utf-8 -*-
class Solution:
    def multiply(self, A):
        # write code here
        if not A:
            return []
        B = [1]*len(A)
        for i in range(0,len(A)):
            for j in range(0,len(B)):
                if i!=j:
                    B[i] *= A[j]
        return B


# -*- coding:utf-8 -*-
class Solution:
    def multiply(self, A):
        # write code here
        if not A:
            return []
        num = len(A) # 
        B = [None]*num # 初始化
        #B[i]的意义是A数组不包括i位置的所有乘积，分为i左边的元素乘积和i右边的所有元素乘积。
        #初始化B[0]=1，是因为0左边没有元素，所以乘积为1。
        B[0] = 1
        for i in range(1,num):
            B[i] = B[i-1]*A[i-1]
        temp = 1
        for i in range(num-2,-1,-1):#从后往前遍历不算最后一个（num-1）因为第一个for循环中已经计算了
            temp *= A[i+1]
            B[i] *= temp
        return B
		