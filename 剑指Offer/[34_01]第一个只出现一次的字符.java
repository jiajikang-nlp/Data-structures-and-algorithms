
import java.util.HashSet;
public class Solution {
    public int FirstNotRepeatingChar(String str) {
        if(str==null || str.length()<1){
            return -1;
        }
        char[] ch = str.toCharArray(); // 将字符串转换成字符数组
        // HashSet存储字符串且保证其唯一性
        HashSet<Character> set = new HashSet<>(); // 新建一个HashSet集合，用于存储已经重复出现的字符；
        for(int i=0;i<str.length()-1;i++){ // 遍历str字符串
            for(int j=i+1;j<ch.length;j++){
                if(set.contains(ch[i])){ // 如果包含，直接跳到下个位置
                    break;
                }
                if(ch[i]==ch[j]){ // 前后遇到相同的，添加到set集合中
                    set.add(ch[i]);
                    break; // 继续下一个
                }
                if(j==ch.length-1){ // 最后一个元素，还未发现重复的
                    return i;// 返回首次出现的位置
                }
            }
            
        }
        return -1;
    }
}



public class Solution {
    public int FirstNotRepeatingChar(String str) {
        if(str==null || str.length()==0){
            return -1;
        }
        int[] words = new int[58];
        for(int i=0;i<str.length();i++){
            words[((int)str.charAt(i))-65] += 1;
        }
        for(int i=0;i<str.length();i++){
            if(words[((int)str.charAt(i))-65]==1){
                return i;
            }
        }
        return -1;
    }
}