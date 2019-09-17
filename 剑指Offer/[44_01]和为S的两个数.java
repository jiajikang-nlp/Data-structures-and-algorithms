import java.util.ArrayList;
public class Solution {
    public ArrayList<Integer> FindNumbersWithSum(int [] array,int sum) {
        ArrayList<Integer> list = new ArrayList<>(); // 创建一个返回数组
        // 先处理特殊情况
        if(array.length<2 || array == null){
            return list; // 返回空列表
        }
        // 获取数组的长度
        int len = array.length;
        // 定义两个指针
        int start = 0;
        int end = len -1;
        while(start<end && end >0){
            if(array[start]+array[end] == sum){
                list.add(array[start]);
                list.add(array[end]);
                return list;
            }
            if(array[start] + array[end]>sum){ // 和大于目标sum，第二个指针往前移动
                end--;
            }
            if(array[start] + array[end]<sum){// 和小于目标sum，第一个指针往后移动
                start++;
            }
        }
        return list;
    }
}
