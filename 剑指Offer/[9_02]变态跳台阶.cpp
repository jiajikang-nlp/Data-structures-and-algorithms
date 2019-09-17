class Solution {
public:
    int jumpFloorII(int number) { 
        //if(!number){
        //    return 0;
        //}
        //return (number==1)?1:2*jumpFloorII(number-1); // 这个一个递归函数
        if(number<0)
            return 0;
        if(number==1)
            return 1;
        int result=1;
        for(int i=2;i<=number;i++){
            result = 2*result;
        }
        return result;
    }
};