public class Solution {
    public int FindGreatestSumOfSubArray(int[] array) {
        if(array==null || array.length==0){
            return 0;
        }
        if(array.length==1){
            return 1;
        }
        
        int MAX = array[0];
        int sum = array[0]; // 设置初始值
        for(int i=1;i<array.length;i++){
            if(sum<0){ // 去除负数
                sum = array[i];
            }else{
                sum += array[i];
            }
            if(sum>MAX){ // 判断大小
                MAX = sum;
            }
        }
        return MAX; // 返回最大值
        
    }
}

解题思路三：动态规划思想
		
		    1、状态方程 ： max( dp[i] ) = getMax( max( dp[i-1] ) + arr[i] ,arr[i])
			2、上面式子的意义是：
			    我们从头开始遍历数组，遍历到数组元素arr[i]时，连续的最大的和可能为 max(dp[i-1]) + arr[i]，也可能为arr[i]，
				做比较即可得出哪个更大，取最大值。时间复杂度为n。
				

public class Solution {
    public int FindGreatestSumOfSubArray(int[] array) {
        if(array.length==0)
            return 0;
        if(array.length==1)
            return 1;
        int sum = array[0]; // 临时最大值
        int MAX = array[0]; // 比较之后最大值
        
        for(int i=1;i<array.length;i++){
            sum = GetMax(sum+array[i],array[i]); // 状态方程
            if(sum>MAX){
                MAX = sum;
            }
        }
        return MAX;
        
    } 
    // 获取最大值
    public static int GetMax(int a,int b){
        return a > b ? a : b; // 返回最大值
    }
}