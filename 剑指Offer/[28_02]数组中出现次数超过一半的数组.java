import java.util.Arrays;
public class Solution {
    public int MoreThanHalfNum_Solution(int [] array) {
        if(array.length==0){
            return 0;
        }
        Arrays.sort(array); // 先排序
        int middle = array[array.length/2];
        int counts = 0;
        for(int i=0;i<array.length;i++){
            if(array[i] == middle){
                counts+=1;
            }
        }
        if(counts>array.length/2){
            return middle;
        }else{
            return 0;
        }
    }
}





public class Solution {
    public int MoreThanHalfNum_Solution(int [] array) {
         int len = array.length; // 数组元素的个数
        if(len==0){
            return 0;
        }
        if(len>=1){
            int res = array[0]; //初始值
            int count = 1;
            for(int i=1;i<len;i++){
                if(count==0){
                    res = array[i];
                    count =1;
                }
                if(array[i]==res){
                    count += 1;
                }
                if(array[i]!=res){
                    count -= 1;
                }
                    
            }
            int counts = 0;
            for(int j=0;j<len;j++){
                if(array[j]==res){
                    counts +=1;
                }
            }
            if(counts>len/2){
                return res;
            }else{
                return 0;
            }
        }
        return 0;
    }
}