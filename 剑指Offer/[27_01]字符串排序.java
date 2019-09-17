import java.util.ArrayList;
import java.util.*;
public class Solution {
    // 思路：
    /*
    每次都把一个数固定在前面，让后面的数递归的进行全排列，这样每个数都固定过以后就能找到所有的排列。
    注意：我们把每个数固定在前面并让后面的进行全排列完毕以后，要恢复原来的状态，也就需要交换回来。
    */
    public ArrayList<String> Permutation(String str) {
        ArrayList<String> ans = new ArrayList<>();// 创建一个数组
       if(str!=null||str.length()>0){ // 判断输入的字符串是否为空
           help(0,str.toCharArray(),ans); // 调用排列函数，其中str.toCharArray()是将字符串转换成字符数组
           Collections.sort(ans);// Collections是一个工具类，sort是其中的静态方法，是用来对List类型进行排序
       }
        return ans; // 返回字符串数组
    }
    
    // 排序
    public static void help(int i, char[] cha, ArrayList<String> ans){
        if(i==cha.length-1){
            String val = String.valueOf(cha); // 获取cha数组中的值给val
                if(!ans.contains(val)){ // 当ans中不包含时，实现添加
                    ans.add(val);
                }
        }else{
            /*从第i个字符开始遍历cha*/
            for(int j=i;j<cha.length;j++){
                swap(i,j,cha); // 交换
                help(i+1,cha,ans);//让后面的数进行全排序
                swap(i,j,cha);// 恢复原来的状态
                
            }
        }
    }
    // 选定一个数固定住
    public static void swap(int i,int j,char[] cha){ /*字符串交换函数*/
        char temp = cha[i];
        cha[i] = cha[j];
        cha[j] = temp;
    }
}