class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int strSize = str.size(); // 字符串个数
        // 处理输入错误
        if(strSize<=0){
            return -1;
        }
        // 处理特殊输入
        if(strSize==1){
            return 0;
        }
        // 使用vector做一个哈希表，记录每个字符出现的次数，全部初始化为0
        vector<int> hashTable(256,0);
        // 范围for循环对输入的字符串进行第一次遍历，统计每种字符出现的次数
        for(auto s:str){ // 这里还得学习一下，作者我也不知道
            hashTable[s]++;
        }
        // 对输入的字符串进行第二次遍历
        for(int i=0;i<strSize;i++){
            if(hashTable[str[i]]==1){
                return i;
            }
        }
        return -1;
    }
};



class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.size()==0){
            return -1;
        }
        int table[58] = {0}; 
        for(int i=0;i<str.size();i++){
            table[str[i]-65]++;
        }
        for(int j=0;j<str.size();j++){
            if(table[str[j]-65]==1){
                return j;
            }
        }
        return -1;
        
    }
};