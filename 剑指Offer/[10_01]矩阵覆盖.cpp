class Solution {
public:
    int rectCover(int number) {
        if(number==0){
            return 0;
        }else if(number==1){
            return 1;
        }else if(number==2){
            return 2;
        }else{
            return rectCover(number-1) + rectCover(number-2);
        }

    }
};


class Solution {
public:
    int rectCover(int number) {
        if(number==0){
            return 0;
        }else if(number==1){
            return 1;
        }else if(number==2){
            return 2;
        }else{
            int result=0;
            int step1 = 1;
            int step2 = 2;
            for(int i=3;i<=number;i++){
                result = step1+step2;
                step1 = step2;
                step2 = result;
            }
            //return rectCover(number-1) + rectCover(number-2);
            return result;
        }

    }
};