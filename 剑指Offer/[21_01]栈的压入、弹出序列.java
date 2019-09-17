import java.util.ArrayList;
import java.util.Stack; // 引入栈类
public class Solution {
    public boolean IsPopOrder(int [] pushA,int [] popA) {
        /*1、如何数组序列为空或者二者不相同则就不符合要求*/
        if(pushA.length==0 || popA.length==0|| popA.length!=pushA.length){
            return false;
        }
        /*2、创建辅助栈对象*/
        int j=0;
        Stack<Integer> stack = new Stack<>();
        for(int i=0;i<pushA.length;i++){ /*遍历第一个序列将数据添加到辅助栈*/
            stack.push(pushA[i]); // 添加数据到辅助栈
            while(!stack.isEmpty() && stack.peek()==popA[j]){ // peek()栈顶元素
                stack.pop(); // 弹出
                j++;
            }
        }
        return stack.isEmpty();// 返回布尔型
      
    }
}

https://www.cnblogs.com/JJCS/p/3480982.html