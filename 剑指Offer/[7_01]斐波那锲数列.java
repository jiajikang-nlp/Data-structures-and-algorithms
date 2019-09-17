public class Solution {
    public int Fibonacci(int n) {
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        if(n>39){
            return 0;
        }
        /*使用动态初始化，创建一个int型一维数组对象*/ 
        int arr[] = new int[n+1];
        arr[0] = 0;
        arr[1] = 1;
        
        for(int i=2;i<=n;i++){
            
            arr[i] = arr[i-1] +arr[i-2];
        }
        return arr[n];

    }
}