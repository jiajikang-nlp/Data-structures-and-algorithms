class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        if(n<=0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        int count = 0;
        for(int i=0;i<=n;i++){
            int temp = i;
            while(temp!=0){
                if(temp%10==1){
                    count++;
                }
                temp /=10;
            }
        }
    return count;
    }
};