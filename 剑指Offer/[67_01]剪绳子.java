public class Solution {
    public int cutRope(int target) {
        // 贪婪算法
       
        if(target==0)
            return 0;
        if(target==2)// 长度为2时，因为要求剪下段数m>1,所以最大是：1*1=1
            return 1;
        if(target==3)// 长度为3时，因为要求剪下段数m>,所以最大是：1*2=2
            return 2;
        //运行至此,说明绳子的长度是>3的,这之后0/1/2/3这种子问题最大就是其自身长度
        int[] products = new int[target+1];
        products[0] = 0;
        products[1] = 1;
        products[2] = 2;
        products[3] = 3;//到3为止都是不剪最好

        // 当n>=5时候，尽可能的剪长度为3的绳子
        int time3 = target/3;
        // 当n==4时候，剪成长度为2的两段
        if(target-time3*3==1){
            time3 -=1;
        }
        // 剪成长度为2的两段
        int time2 = (target-time3*3) / 2;
        return (int)((Math.pow(3,time3)) * (Math.pow(2,time2)));
 
    }
}

----------------------------------------------------------

public class Solution {
    public int cutRope(int target) {
        // 动态规划
        if(target<2)
            return 0;
        if(target==2)
            return 1;
        if(target==3)
            return 2;
        // 将最优解存储在数组中
        int[] products = new int[target+1];
        int max = 0;// 用于记录最大乘积
        products[0] = 0;
        products[1] = 1;
        products[2] = 2;
        products[3] = 3;
        for(int i=4;i<=target;i++){
            max = 0;
            //求出所有可能的f(j)*f(i-j)并比较出他们的最大值
            // 因为要计算f(j)乘以f(i-j)的最大值,j超过i的一半时是重复计算
            // 所以只需要考虑j不超过i的一半的情况
            for(int j=1;j<=i/2;j++){
                int product = products[j]*products[i-j];
                if(product>max){
                    max = product;
                }
                products[i] = max;
            }
        }
        max = products[target];
        return max;

    }
}