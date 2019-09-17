class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> list; // 创建list集合
        int start = 0; // 左上角(x,x)
        int row = matrix.size(); // 行(假设一个4*5的一个矩阵，此时row=5，也就是表示矩阵的逻辑结构中的行数)
        int col = matrix[0].size(); // 列(一列的长度，此时col=4，也就是表示矩阵逻辑结构中的列数)
        if(row==0||col==0){
            return list;
        }
        
        int left =0; // 左边
        int right = col-1; // 最右边的第right列
        int top = 0;//上边
        int bottom = row-1;// 最下边的第bottom行
        
          // n*n矩阵，最后一圈左上角为(x,x),通过规律 n>2*x，就是循环条件
        while(left<=right && top <= bottom){
            /*第一步：从左往右*/
            for(int i=left;i<=right;i++){
                list.push_back(matrix[top][i]); // 添加行
            }
            /*第二步：从上往下*/
            for(int i=top+1;i<=bottom;i++){
                list.push_back(matrix[i][right]); // 添加列
            }
            /*第三步：从右往左*/
            if(top!=bottom){
                for(int i=right-1;i>=left;i--){
                list.push_back(matrix[bottom][i]); // 添加行
            }
            }
            /*第四步：从下往上*/
            if(left!=right){
                for(int i=bottom-1;i>top;i--){
                    list.push_back(matrix[i][left]);
                }
            }
            left++;
            top++;
            right--;
            bottom--;
        }
        return list;
 
      
    }
};