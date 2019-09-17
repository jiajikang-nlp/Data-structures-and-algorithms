# -*- coding:utf-8 -*-
class Solution:
    def movingCount(self, threshold, rows, cols):
        # write code here
        matrix = [[True for i in range(cols)] for j in range(rows)]
        result = self.findgrid(threshold, rows, cols, matrix, 0, 0)
        return result
    
    def judge(self, threshold, i, j): # 判断数字是否符合条件
        if sum(map(int,str(i)+str(j))) <= threshold:
            return True
        else:
            return False
        
    def findgrid(self, threshold, rows, cols, matrix, i, j): # 获取格子数
        count = 0
        if i < rows and i>=0 and j<cols and j>=0 and self.judge(threshold, i, j) and matrix[i][j]:
            matrix[i][j] = False
            count = 1+ self.findgrid(threshold, rows, cols, matrix, i-1, j) \
                    + self.findgrid(threshold, rows, cols, matrix, i+1, j) \
                    + self.findgrid(threshold, rows, cols, matrix, i, j-1) \
                    + self.findgrid(threshold, rows, cols, matrix, i, j+1)
        return count