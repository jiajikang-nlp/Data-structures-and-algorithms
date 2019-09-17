public class Solution {
    public int LastRemaining_Solution(int n, int m) {
        if(n<=0||m<1){// 先判断特殊情况
            return -1;
        }
        int res = 0;
        for(int i=2;i<=n;i++){
            res = (res+m) %i;
        }
        return res;
    }
}


import java.util.LinkedList;
import java.util.List;
public class Solution {
    public int LastRemaining_Solution(int n, int m) {
        if(n<1||m<1){
            return -1;
        }
        List<Integer> students = new LinkedList<>(); // 采用链表的结构，每次删除开销不断降低问题规模，避免不必要的遍历
        for(int i=0;i<n;i++){
            students.add(i);
        }
        int index = 0;
        while(students.size()>1){
            index = (index+m-1)% students.size();
            students.remove(index);
        }
        return students.get(0);
        
    }
}



public class Solution {
    public int LastRemaining_Solution(int n, int m) {
        if(n<1||m<1){
            return -1;
        }
        boolean[] visited = new boolean[n]; // 创建一个长度为n的布尔型变量数组
        int count = -1;
        int index = -1;
        int sum = 0;
        while(true){
            index = index + 1 ==n ? 0 : index + 1;
            if(!visited[index]){
                count++;
            }
            if(count ==m-1){
                visited[index] = true;
                if((++sum)==n){
                    return index;
                }
                count = -1;
            }
        }
    }
}