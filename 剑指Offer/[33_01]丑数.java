public class Solution {
    public int GetUglyNumber_Solution(int index) {
       if(index<=0){
           return 0;
       }
        int number = 0;
        int frequency = 0;
        while(frequency<index){
            number++;
            //如果这个数是丑数，则修改循环变量，减少一次循环次数
            //如果这个数不是丑数，则不用修改循环变量，继续让numder向后枚举
            if(isUglyNumber(number)==1){
                frequency++;
            }
        }
        return number;
        
    }
    // 判断一个数是否是丑数
    public static int isUglyNumber(int num){
        while((num%2)==0){
            num /=2;
        }
        while((num%3)==0){
            num /= 3;
        }
        while((num%5)==0){
            num /= 5;
        }
        return (num==1) ? 1:0;
    }
}


import java.util.ArrayList;
public class Solution {
    public int GetUglyNumber_Solution(int index) {
        ArrayList<Integer> out=new ArrayList<Integer>();
        out.add(1);
        if(index<=0){
            return 0;
        }
        int count=0;
        int M2=1,index2=0;
        int M3=1,index3=0;
        int M5=1,index5=0;
        // 记录丑数序列a中最大的丑数为M,第一个丑数为1
        // 下一个要找的丑数比已有最大丑数刚刚大，这样可以得到一个有序的丑数序列
        while(count<index){
            out.add(Math.min(Math.min(M2,M3),Math.min(M3,M5)));
            count++;
            while(out.get(index2)*2<=out.get(out.size()-1))
            {index2++;}
            M2=out.get(index2)*2;
            
             while(out.get(index3)*3<=out.get(out.size()-1))
            {index3++;}
            M3=out.get(index3)*3;
            
            while(out.get(index5)*5<=out.get(out.size()-1))
            {index5++;}
            M5=out.get(index5)*5;
        }
        return out.get(out.size()-1);
    }
}