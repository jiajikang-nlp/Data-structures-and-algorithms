class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        vector<int> result;
        if(array.size()==0){
            return 0;
        }
        if(array.size()==1){
            return 1;
        }
        int MAX = array[0]; // 初始值
        int sum = array[0]; // 初始值
        // 开始从第array[1]个遍历
        for(int i=1;i<array.size();i++){
            if(sum<0){
                sum = array[i];
            }else{
                sum += array[i];
            }
            if(sum>MAX){
                MAX = sum;
            }
            
        }
       return MAX;
    
    }
};