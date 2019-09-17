public class Solution {
    public boolean hasPath(char[] matrix, int rows, int cols, char[] str)
    {
        if(matrix==null||rows<1 || cols<1 || str==null){
            return false;
        }
        if(str.length==0)
            return true;
        
        boolean[] visited = new boolean[matrix.length]; // 长度为原始数组矩阵长度
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(findpath(matrix,i,j,rows,cols,0,visited,str)){ // 第i行第j列
                    return true;
                }
            }
        }
            return false;
    
    }
    // 寻找路径
    public boolean findpath(char[] matrix,int row,int col,int rows,int cols,int k, boolean[] visited,char[] str){
        if(row<0 || row>=rows || col<0 || col>=cols || str[k]!=matrix[row*cols+col] || visited[row*cols+col]){
          
            return false;
        }
        if(k==str.length-1){
            return true;
        }
		
        visited[row*cols+col] = true;
        if(findpath(matrix,row+1,col,rows,cols,k+1,visited,str)||findpath(matrix,row,col+1,rows,cols,k+1,visited,str) || findpath(matrix,row-1,col,rows,cols,k+1,visited,str)||findpath(matrix,row,col-1,rows,cols,k+1,visited,str)){
            return true;
        }
		
        visited[row*cols+col] = false; // 走到这一步那就说明不是
        
		return false;
        
    }

}

---------------------------------------------------


public class Solution {
    public boolean hasPath(char[] matrix, int rows, int cols, char[] str)
    {
        if(matrix==null|| rows<1 ||cols<1 || str==null){
            return false;
        }
        if(matrix.length==0){
            return true;
        }
        int[] flag = new int[matrix.length]; 
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(helper(matrix,rows,cols,i,j,str,0,flag)){
                    return true;
                }
            }
        }
    return false;
    }
    public static boolean helper(char[] matrix,int rows,int cols,int i,int j,char[] str,int k,int[] flag){
          int index = i*cols + j;
        if(i < 0 || i >= rows || j < 0 || j >= cols || matrix[index] != str[k] || flag[index] == 1){
           //下标不符合，index对应的值不为和字符数组中的不一致，或者该index已经被访问，这些情况只要有符合的就返回false
            //只有上面的所有情况都不符合，也就是值相等，且没有访问过，下标不符合
            return false;
        }
        
        if(k ==str.length-1){
            return true;
        }
        flag[index] = 1;
        if(helper(matrix,rows,cols,i-1,j,str,k+1,flag)
          ||helper(matrix,rows,cols,i+1,j,str,k+1,flag)
          ||helper(matrix,rows,cols,i,j-1,str,k+1,flag)
          ||helper(matrix,rows,cols,i,j+1,str,k+1,flag)){
            return true;
        }
        flag[index] = 0;
        return false;
    }


}



