public class Solution {
    public String ReverseSentence(String str) {
        if(str.trim().length()==0)
            return str;
        String[] temp = str.split(" "); //对字符串按照所传参数进行分割
        String res = "";
        for(int i=temp.length-1;i>=0;i--){
            res += temp[i]; // 反转
            if(i!=0){
                res += " ";
            }
        }
        return res;
        
    }
}


public class Solution {
    public String ReverseSentence(String str) {
        if(str==null || str.length()<=0){ // 判断起始条件
            return str;
        }
        char[] chs = str.toCharArray(); // 将字符串转换成字符数组
        int len = chs.length; // 获取字符串长度
        int i=0;
        String temp = "";// 创建一个空字符串变量
        String result = "";
        while(i<len){
            if(chs[i]==' '){ // 获取空格
                result = " " + temp + result; // 加在result的前面，才能逆序
                temp = "";
            }else{
                temp = temp + chs[i]; // 加在后面，保证原始顺序
            }
            i++;
        }
        if(temp.length()!=0){ // 如果最后一个是单词
            result = temp+result; 
        }
        return result;
        
    }
}