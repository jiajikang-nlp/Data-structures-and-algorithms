public class Solution {
    public int InversePairs(int [] array) {
        if(array==null||array.length==0){
            return 0;
        }
        int len = array.length;// 数组长度
        int[] copy = new int[len];
        for(int i=0;i<len;i++){
            copy[i] = array[i];
        }
        int count=InversePairsCore(array,copy,0,len-1); // 逆序对的个数
        return count;
    }
    
    private int InversePairsCore(int[] array, int[] copy, int low, int high){
        if(low==high){
            return 0; // 其实就是判断数组是否为空
        }
        int mid = (low+high)>>1; // 获取中位数:先把数组分割成子数组,>>1 = /2
        int leftCount = InversePairsCore(array,copy,low,mid)%1000000007;
        int rightCount= InversePairsCore(array,copy,mid+1,high)%1000000007;
        int count = 0;
        int i = mid;
        int j = high;
        int locCopy = high;
        while(i>=low&&j>mid){
            if(array[i]>array[j]){
                count += j-mid;
                copy[locCopy--] = array[i--];
                if(count>=1000000007){//数值过大求余
                    count %= 1000000007;
                }
            }else{
                copy[locCopy--] = array[j--];
            }
        }
        for(;i>=low;i--){
            copy[locCopy--]=array[i];
        }
        for(;j>mid;j--){
            copy[locCopy--]=array[j];
        }
        for(int s=low;s<=high;s++){
            array[s] = copy[s];
        }
        return (leftCount+rightCount+count)%1000000007;
        
    }
}