/*
既然往右移动会出现死循环，那么可以考虑往左移，于是定义一个flag，
从最小位开始，每判断一次，就往左移一位，直到flag与数字做与操作为为0，
说明数字的最大值都已经判断完了，所以结束循环。
*/
public class Solution {
    public int NumberOf1(int n) {
        int count = 0; // 记录出现1的个数
        int flag = 1;
        while(flag != 0){
            if((n & flag)!=0){
                count++;
            }
            flag = flag<<1; // 左移
        }
        return count;

    }
}