import java.util.ArrayList;
public class Solution {
    public ArrayList<Integer> printMatrix(int [][] matrix){
        ArrayList<Integer> list = new ArrayList<>(); // 创建ArrayList集合对象
          /*开始先判断下matrix是否为空，要是为空那就没有继续下去的意思奥*/
         int rows = matrix.length; // 行长度
         int colums = matrix[0].length; // 列长度
        if(matrix==null|| rows==0 || colums==0){
            return null;
        }
        int start = 0; // 设置每圈左上角位置(x,x) ; 要是不为空，那就进入到循环指针 
        //1、设置循环的条件
        /*行数或者列数必须大于当前左上角坐标之积*/
        while(rows> 2*start && colums > 2*start){ 
            // 调用打印函数
            printMatrixInCircle(matrix,rows,colums,start,list);
            start++;
        }
            return list;
  }
    
        public static void printMatrixInCircle(int[][] matrix,int rows,int colums,int start,ArrayList<Integer> list){
            //int rows = matrix.length; // 行的长度
            //int columns = matrix[0].length; //列的长度
            int endX = colums-1-start; // 终止行号：endX=行长度<-->一列的长度[colums-1-start]
            int endY = rows-1-start; //终止列号:endY=列长度<-->一行的长度
            
            /*第一步：从左往右*/
            // start:每圈的左上角的起始点
            for(int i=start;i<=endX;i++){ 
                int num = matrix[start][i];
                list.add(num); // 添加当前行的每一个元素
            }
            /*第二步：从上往下*/
            // 要在列号大于起始点的条件下：
            if(start<endY){
                for(int i=start+1;i<=endY;i++){
                    int num = matrix[i][endX];
                    list.add(num);// 添加当前列的元素
                }
            }
            /*第三步：从右往左(判断是否会重复打印)*/
            if(start<endX && start<endY){
                for(int i=endX-1;i>=start;i--){
                    int num = matrix[endY][i];
                    list.add(num); // 添加当前行的元素
                }
            }
            
            /*第四步：从下往上(判断是否会重复打印)*/
            if(start<endX && start<endY-1){
                for(int i=endY-1;i>=start+1;i--){
                    int num = matrix[i][start];
                    list.add(num);// 添加当前行的元素
                }
            }
              
        }
}