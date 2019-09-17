class Solution
{
public:
  //Insert one char from stringstream
    string s = ""; // 创建一个字符串类型变量
    char hash[256] = {0};// 创建一个char型字符，大小也就是每个字符是8个字节，所以这最大就是256
    void Insert(char ch)
    {
        s += ch; // 将输如的字符添加到字符串中，
        hash[ch]++;//  统计对应字符的个数
         
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        int len = s.size(); // 字符串长度
        for(int i=0;i<len;i++){
            if(hash[s[i]]==1){// 如果char型中存在字符=1
                return s[i];
            }
        }
        return '#';
    
    }

};