# -*- coding:utf-8 -*-
class Solution:
    # matrix类型为二维列表，需要返回列表
        # write code here
    def printMatrix(self, matrix):
        left = top = 0
        row = len(matrix)# 表示矩阵的逻辑结构中的行数
        col = len(matrix[0])
        
        xn = len(matrix)-1
        yn = len(matrix[0])-1
        #right = row-1 #  
        #bottom = col-1#  
        
        list = []
        while left<=xn and top<=yn:
            for y in range(top, yn+1):
                list.append(matrix[left][y])
            for x in range(left+1, xn+1):
                list.append(matrix[x][yn])
            if left < xn:
                for y in range(yn-1, top-1, -1):
                    list.append(matrix[xn][y])
            if top < yn:
                for x in range(xn-1, left, -1):
                    list.append(matrix[x][top])
            left += 1
            top += 1
            xn -= 1
            yn -= 1
        return list