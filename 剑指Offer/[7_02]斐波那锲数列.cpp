class Solution {
public:
    int Fibonacci(int n) {
        if(n==0 || n>39){
            return 0;
        }
        if(n==1){
            return 1;
        }
        int f,f1=0,f2 =1;
        for(int i=2;i<=n;i++){
            f = f1+f2;
            f1 = f2; // 将f2的值赋给f1
            f2 = f;
        }
         return f;
    }
	
};

或者
class Solution {
public:
    int Fibonacci(int n) {
        int Fibonacci_arry[39];
        Fibonacci_arry[0] = 0;
        Fibonacci_arry[1] = 1;
        for(int i=2;i<=n;i++){
            Fibonacci_arry[i]  = Fibonacci_arry[i-1] + Fibonacci_arry[i-2];
        }
        return Fibonacci_arry[n];

    }
};