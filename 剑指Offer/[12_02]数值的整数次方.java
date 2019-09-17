public class Solution {
    public double Power(double base, int exponent) {
        /*当exponent不为负数时*/
        if(exponent==0){
            return 1;
        }
        if(exponent==1){
            return base;
        }
        if(exponent>1){ 
            double result = Power(base,exponent>>1);//递归 exponent>>1就是expontent/2，但是右移效率更高
            result *=result; //结果相乘
        if((exponent & 1)==1){ //exponent&1就是判断奇偶，=1为奇数还要乘一个base，比%效率更高
            result *=base; // 这里看指数为偶数时的公式。
        }
        return result;
        }
        if(exponent<0){
            exponent = -exponent; // 负负得正
            double result =Power(base,exponent); // 递归调用
            return 1/result; // 取倒数
        }
        return -1;
    
        
        
  }
}