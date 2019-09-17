import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
public class Solution {
    public String PrintMinNumber(int [] numbers) {
        if(numbers==null||numbers.length==0){
            return "";
        }
        int len = numbers.length; // 获取数组长度
        String[] str = new String[len]; // 创建字符串对象
        StringBuffer sb = new StringBuffer();
        for(int i=0;i<len;i++){
            str[i] = String.valueOf(numbers[i]); // 转换为字符串
        }
        //这里根据自己定义的排序规则,新的排序规则,如若取最大值
        Arrays.sort(str,new Comparator<String>(){
            public int compare(String str1,String str2){
                String c1 = str1 + str2;
                String c2 = str2 + str1;
                return c1.compareTo(c2);
                
            }
        });
        for(int i=0;i<len;i++){
            sb.append(str[i]);
        }
        return sb.toString();// 字符串
    }
}


解题思路二：
			    找到一个排序规则，数组根据这个规则排序之后能排成一个最小的数字。
				给出一个规则，判断给出的两个数字m和n，判断这两个数那个应该排在前面，而不是仅仅比较这两个数字的值那个更大。
                隐形的大数问题：m和n都在int能表达的范围内，但把它们拼接起来的数字mn和nm用int表示就有可能溢出了————可以把数字转换成字符串来解决大数问题。
                把数字m和n拼接起来，得到mn和nm，它们的位数肯定是相同的，因此比较它们的大小只需要按照字符串大小的比较规则就可以了。
 
				具体的排序规则如下：
					若ab > ba 则 a 大于 b，
					若ab < ba 则 a 小于 b，
					若ab = ba 则 a 等于 b；
			    根据上述规则，我们需要
				    1、先将数字转换成字符串
					2、再进行比较，因为需要串起来进行比较。
					3、比较完之后，按顺序输出即可。