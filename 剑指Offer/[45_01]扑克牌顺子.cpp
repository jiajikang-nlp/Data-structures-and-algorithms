class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        int len = numbers.size(); // 获取数组的长度
        // 判断特殊条件
        if(len!=5 || numbers.empty()){ // 都未能到底必要条件
            return false;
        }
        int max = -1;
        int min = 14;
        int numZero = 0;
        short repeat = 0; // 查重
        for(int i=0;i<len;i++){
            if(numbers[i]<0 || numbers[i]>13){ //面值不规范
                return false; // 
            }
            if(numbers[i]==0){
                numZero++;
                continue; 
            }
            if(repeat>>numbers[i]&1){// 出现面值重复
                return false; // 
            }
            repeat |= 1<<numbers[i];
            if(numbers[i]>max){
                max = numbers[i];
            }
            if(numbers[i]<min){
                min = numbers[i];
            }
            if(max-min>=5){
                return false;
            }
        }
            return numZero<=4?true:false;
        
    }
};

// 先排序
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        int len = numbers.size(); // 获取数组长度
        // 判断特殊情况
        if(len!=5){
            return false;
        }
        // 先排序
        sort(numbers.begin(),numbers.end());
        int num0fZero = 0; // 只统计前4个数中0出现的个数
        int number0fInterval = 0;
        for(int i=0;i<len-1;i++){
            if(numbers[i]<0||numbers[i]>14){ // 面值规范化
                return false;
            }
            if(numbers[i]==0){ // 过去所有值为0的数组， 从第一个非零值开始研究
                num0fZero++;
                continue;
            }
            if(numbers[i]==numbers[i+1]){
                return false;
            }
            number0fInterval += numbers[i+1] -numbers[i]-1; // 所需癞子
        }
        return numbers[4]!=0 && num0fZero>=number0fInterval?true : false;
    }
};
