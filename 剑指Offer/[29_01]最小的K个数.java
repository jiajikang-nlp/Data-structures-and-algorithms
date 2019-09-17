import java.util.Arrays;
import java.util.ArrayList;
public class Solution {
    public ArrayList<Integer> GetLeastNumbers_Solution(int [] input, int k) {
        ArrayList<Integer> result = new ArrayList<>(); // 创建一个用于存储输出结果的对象
        if(input==null||k<=0||k>input.length){ // 永远记住，正式开始前的前提条件
            return result;
        }
        Arrays.sort(input); // 对数组input排序
        for(int i=0;i<k;i++){
            result.add(input[i]); //遍历0-k个数
        }
        return result;
    }
}



import java.util.ArrayList;
import java.util.Random;


public class Solution {
    public ArrayList<Integer> GetLeastNumbers_Solution(int [] input, int k) {
        ArrayList<Integer> result = new ArrayList<>();// 创建一个返回结果的对象
        if(input==null||k<=0||k>input.length){
            return result;
        }
        findKthVal(input,0,input.length-1,k-1);
        for(int i=0;i<k;i++){
            result.add(input[i]);
        }
        return result;
        
    }
   
    
    public static void findKthVal(int[] input,int low,int high,int k){
        if(low<high){
            int pivot = new Random().nextInt(high-low+1) + low;
            swap(input,pivot,high);
            int index = low;
            for(int i=low;i<high;i++){
                if(input[i]<input[high]){
                    swap(input,i,index);
                    index++;
                }
            }
            swap(input,index,high);
            if(index>k){
                findKthVal(input,low,index-1,k);
            }else if(index<k){
                findKthVal(input,index+1,high,k);
            }
        }
    }
    
    // 交换函数
     public static void swap(int[] input,int x, int y){
        int temp = input[x];
        input[x] = input[y];
        input[y] = temp;
    }
    
}




import java.util.ArrayList;
import java.util.Queue; // 队列
import java.util.Comparator; // 大顶堆
import java.util.PriorityQueue;
public class Solution {
    public ArrayList<Integer> GetLeastNumbers_Solution(int [] input, int k) {
        ArrayList<Integer> result = new ArrayList<>();
        if(input==null || k<=0 || k>input.length){
            return result;
        }
        
        //PriorityQueue<Integer> minHeap = new PriorityQueue<Integer>(); //小顶堆，默认容量为11
        PriorityQueue<Integer> q = new PriorityQueue<Integer>(k,new Comparator<Integer>(){
           //因为要满足大根堆需求，所以使用自定义比较器，比较策略为o1大于o2时，o1放o2的前面
            public int compare(Integer i1,Integer i2){
                return i2-i1;
            }
        });
  
        for(int i=0;i<input.length;i++){
            if(i<k){
                q.add(input[i]);
            }else{
                if(q.peek()>input[i]){
                    q.poll();
                    q.add(input[i]);
                }
            }
        }
        
         for(int i=0;i<k;i++){
             result.add(q.peek()); // 假如栈顶
             q.poll(); // 弹出
            }
          return result;
        
    }
}




