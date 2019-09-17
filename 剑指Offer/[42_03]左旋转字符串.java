 
public class Solution {
    public String LeftRotateString(String str,int n) {
        if(str==null || str.length()<=n||str.length()<=2){
            return str;
        }
        int len = str.length(); // 获取字符串的长度
         n %= len;
         str +=str;
        return str.substring(n,n+len);
        
    }
}