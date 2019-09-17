class Solution {
public:
    int Sum_Solution(int n) {
        
        //return n+n*(n-1)/2;
        //return n == 1 ? 1 : (n+Sum_Solution(n-1)); //递归
        int ans = n;
        n && (ans = n+Sum_Solution(n-1));
        return ans;
    }
};