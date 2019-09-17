public class Solution {
    public int NumberOf1Between1AndN_Solution(int n) {
        if(n<=0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        int count = 0; // 统计1的个数
        for(int i=0;i<=n;i++){
            int temp = i;
            // 如果temp的任意位为1则count++
            while(temp!=0){
                if(temp%10==1){
                    count++;
                }
                temp /= 10; // 以10的倍数递增
            }
        }
        return count;
    }
}




public class Solution {
    public int NumberOf1Between1AndN_Solution(int n) {
        if(n<=0)
            return 0;
        if(n==1)
            return 1;
        /*
        总结一下以上的算法，可以看到，当计算右数第i位包含的X的个数时：
		 取第i位左边（高位）的数字，乘以 10^(i−1)，得到基础值 a。
		 取第i位数字，计算修正值： 
			 1、如果大于 X，则结果为 a+10^(i−1)。
			 2、如果小于 X，则结果为 a。
			 3、如果等 X，则取第 i 位右边（低位）数字，设为 b，最后结果为 a+b+1。
        */
        int count = 0; // 统计出现1的个数
        for(int i=1;i<=n;i*=10){
            int a = n / i; // 求整
            int b = n % i; // 求余
            // 之所以补8，是因为当百位=0，则a/10 == (a+8)/10
            // 当百位>=2,补8会产生进位，效果等同于(a/10+1)
            count += (a+8) / 10*i + ((a %10 ==1)?b+1:0);
        }
    return count;
    }
}