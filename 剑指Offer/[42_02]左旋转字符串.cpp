class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(n==0 || str.size()==0){
            return str;
        }
        if(n>=str.size()){ // 如果输入的数字>打印字符串的个数
            n %= str.size(); // 求余
        }
        string s1 = str.substr(0,n); // 获得字符串str中从第0位开始的长度为n的字符串
        string s2 = str.substr(n); // 获取剩余的
        string res = s2 + s1;
        return res;
        
    }
};


