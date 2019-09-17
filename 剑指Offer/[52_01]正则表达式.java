public class Solution {
    public boolean match(char[] str, char[] pattern){
        return helpmatch(str, 0, pattern, 0);
    }
	private boolean helpmatch(char[] str,int i, char[] pattern,int j){
        if(j == pattern.length) {//遍历到最后
        	return i == str.length;
        }
        boolean isMatch =(i != str.length) && (str[i] == pattern[j] || pattern[j] == '.');// 记录匹配的情况，是true还是否
        if(j<pattern.length-1 && pattern[j+1]=='*') {
            // i和j匹配，并且i+1也和j匹配，因为j+1是*，所以j可能有多个
            // i和j可能匹配也可能不匹配，*前面一个j出现0次，从*后面的一个（j+2）重新匹配
        	return (isMatch && (helpmatch(str, i+1, pattern, j)) || helpmatch(str, i, pattern, j+2));
        }else {
        	return isMatch && helpmatch(str, i+1, pattern, j+1); // j+1不是*
        }
    }
}