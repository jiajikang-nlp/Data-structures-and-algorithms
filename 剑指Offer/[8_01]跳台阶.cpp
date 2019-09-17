class Solution {
public:
    int jumpFloor(int number) {
        if(number <0){
            return 0;
        }else if(number<=2){
            return number;
        }else{
            int step1 = 1;
            int step2 = 2;
            int result = 0;
            for(int i=3;i<=number;i++){
                result = step1+step2;
                step1 = step2;
                step2 = result;
            }
            return result;
        }
        
    }
};