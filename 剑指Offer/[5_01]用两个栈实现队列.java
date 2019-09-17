import java.util.Stack;

public class Solution {
    Stack<Integer> stack1 = new Stack<Integer>();
    Stack<Integer> stack2 = new Stack<Integer>();
    /*入栈函数*/
    public void push(int node) {
        stack1.push(node);//将int型数据都输入到stack1
    }
    /*出栈函数*/
    public int pop() {
       /*将stack1中的内容存入到stack2中*/
        while(!stack1.isEmpty()){
            stack2.push(stack1.pop());
        }
        /*从stack2出来*/
        int out = stack2.pop();
        /*在回到stack1中，恢复原来的状态*/
        while(!stack2.isEmpty()){
            stack1.push(stack2.pop());
        }
        return out;
    }
}