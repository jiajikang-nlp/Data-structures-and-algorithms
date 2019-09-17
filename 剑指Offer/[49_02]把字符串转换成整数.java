public class Solution {
    public int StrToInt(String str) {
        // 对结果的保存
        int result = 0;
        // 符号的标注：1 0 -1 默认为正
        int symbol = 1;
        // 判断输入的值是否为0
        boolean isValid = false;
        // 对传入的字符串进行转换成数组
        char[] array = str.toCharArray();
        if(str==null||str.length()<=0){
            return 0;
        }
        // 判断符号位
        if(array[0] == '-'){
            symbol = -1;
        }
        // 对正负号的处理需要过滤掉第一位为正负号，直接对符号循环前过滤
        for(int i=(array[0]=='+'||array[0]=='-')?1:0;i<array.length;i++){
            // 对输入的内容进行验证：是否在0-9范围内
            if(!('0'<=array[i] && array[i]<='9')){
                isValid = true;
                return 0;
            }
            // 对得到结果处理// 
            result = result*10 + array[i] - '0';
            if((symbol==1&& result>Integer.MAX_VALUE) || (symbol==-1&& result<Integer.MIN_VALUE)){
                isValid = true;
                return 0;
            }
        }
        return result *symbol;
    }
}