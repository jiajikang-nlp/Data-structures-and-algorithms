public class Solution {
    public int Sum_Solution(int n) {
        int result = 0;
        int a = 0;
        boolean temp = ((n>0) && a==(result=Sum_Solution(n-1)+n));
        return result;
    }
}