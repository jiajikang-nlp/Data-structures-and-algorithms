
public class Solution {
    public boolean isNumeric(char[] str) {
        String string = String.valueOf(str);
        return string.matches("[+-]?[0-9]*(\\.[0-9]*)?([eE][+-]?[0-9]+)?");
        
    }
}


public class Solution {
    public boolean isNumeric(char[] str) {
        //String string = String.valueOf(str);
        //return string.matches("[+-]?[0-9]*(\\.[0-9]*)?([eE][+-]?[0-9]+)?");
        if(str.length==0){
            return false;
        }
         boolean decimal = false,sign = false,hasE = false;
        // boolean decimal = false;// 判断小数点
        // boolean sign = false; // 符号
        // boolean hasE = false; // 判断e/E
        // 逐个字符进行校验
        for(int i=0;i<str.length;i++){
            if(str[i]=='e'||str[i]=='E'){
                // 出现e/E，那么其后面必须有数字
                if(i==str.length-1){
                    return false;
                }
                // e/E只能出现一次
                if(hasE){
                    return false;
                }
                hasE =true;
            }else if(str[i]=='+'||str[i]=='-'){
                // 若是第一次出现，且不再第一位，则必须根则e/E后面
                if(!sign && i>0 && str[i-1]!='e' && str[i-1]!='E'){
                    return false;
                }
                // 若是第二次出现，则必须根则e/E后面
                if(sign && str[i-1]!='e' && str[i-1]!='E'){
                    return false;  
                }
                sign = true;
                
            }else if(str[i]=='.'){
                if(hasE||decimal){
                    return false;
                }
                decimal = true;
            }else if(str[i]<'0' || str[i]>'9'){
                // 最后在判断非法字符
                return false;
            }
        }
        // 所以校验都已通过
        return true;
    }
}