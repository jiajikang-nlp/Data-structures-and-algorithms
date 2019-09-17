public class Solution {
    public int movingCount(int threshold, int rows, int cols)
    {
        if(threshold<0){
            return 0;
        }
        boolean[] visited = new boolean[rows*cols];
        int count = movingCountCore(threshold,rows,cols,0,0,visited);
        return count;
    }
	// 获取能够达到格子个数
    private int movingCountCore(int threshold,int rows,int cols,int row,int col,boolean[] visited){
        int count = 0;
        if(check(threshold,rows,cols,row,col,visited)){
            visited[row*cols+col] = true;
            count = 1+movingCountCore(threshold,rows,cols,row+1,col,visited)
                + movingCountCore(threshold,rows,cols,row-1,col,visited)
                + movingCountCore(threshold,rows,cols,row,col+1,visited)
                + movingCountCore(threshold,rows,cols,row+1,col-1,visited);
        }
        return count;
        
    }
    
    // 判断数字是否满足条件
    private boolean check(int threshold,int rows,int cols,int row,int col,boolean[] visited){
        if(row>=0 && row<rows && col>=0 && col<cols && visited[row*cols +col]==false && getDigitSum(col)+getDigitSum(row)<=threshold){
            return true;
        }
        return false;
    }
    // 获取数字之和
    private int getDigitSum(int col){
        int sum = 0;
        while(col!=0){
            sum+= col%10;
            col=col/10;
        }
        return sum;
    }
}