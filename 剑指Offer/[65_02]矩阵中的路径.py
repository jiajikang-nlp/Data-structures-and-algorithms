class Solution:
    def hasPath(self, matrix, rows, cols, path):
        assistMatrix = [True]*rows*cols # 判断这条路走过没有
        for i in range(rows):
            for j in range(cols):
                if(self.hasPathAtAStartPoint(matrix,rows,cols, i, j, path, assistMatrix)):
                    return True
        return False

    def hasPathAtAStartPoint(self, matrix, rows, cols, i, j, path, assistMatrix):
        if not path:
            return True
        index = i*cols+j
        if i<0 or i>=rows or j<0 or j>=cols or matrix[index]!=path[0] or assistMatrix[index]==False:
            return False
        assistMatrix[index] = False
        if(self.hasPathAtAStartPoint(matrix,rows,cols,i+1,j,path[1:],assistMatrix) or
               self.hasPathAtAStartPoint(matrix,rows,cols,i-1,j,path[1:],assistMatrix) or
               self.hasPathAtAStartPoint(matrix,rows,cols,i,j-1,path[1:],assistMatrix) or
               self.hasPathAtAStartPoint(matrix,rows,cols,i,j+1,path[1:],assistMatrix)):
            return True
        assistMatrix[index] = True
        return False