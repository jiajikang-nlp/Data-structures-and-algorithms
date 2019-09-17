class Solution {
public:
    double Power(double base, int exponent) {
        /*exponent为正数时候*/
        if(exponent==0){
            return 1;
        }
        if(exponent==1){
            return base;
        }
        if(exponent>1){
            double result = Power(base,exponent>>1); // expentent>>1相当于exponent/2
            result *= result;
            if((exponent & 1)==1){ // 判断奇偶，如果是奇数还得乘一个base
                result *= base; 
            }
            return result;
        }
        /*如果exponent为负数*/
        if(exponent<0){
            exponent = -exponent;
            double result = Power(base,exponent);
            return 1/result;
        }
        return -1;
    
    }
};