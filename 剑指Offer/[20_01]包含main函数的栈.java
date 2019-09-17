import java.util.Stack;

public class Solution {
    Stack<Integer> m_data_stack = new Stack<>(); // 创建栈对象：存储数据栈
    Stack<Integer> m_min_stack = new Stack<>(); // 创建栈对象：辅助栈

    /*push:压入*/
    public void push(int node) {
        m_data_stack.push(node); // 存储数据
        if(m_min_stack.isEmpty()){
            m_min_stack.push(node); // 如果当前辅助栈没有元素，当前元素直接压入
        }else{
            m_min_stack.push(Math.min(node,m_min_stack.peek()));//如果当前辅助栈中有元素，且当前待压入的元素小于辅助栈栈顶元素，那就直接压入
        }
    }
    /*pop：弹出*/
    public void pop() {
        if(m_data_stack.isEmpty() == true && m_min_stack.isEmpty() == true){
            return;
        }
        m_data_stack.pop();
        m_min_stack.pop();
    }
    /*栈顶*/
    public int top() {
        if(m_data_stack.isEmpty()==true && m_min_stack.isEmpty()==true){
            return Integer.MIN_VALUE;
        }
        return m_data_stack.peek();
    }
    /*最小元素min函数*/
    public int min() {
        if(m_data_stack.isEmpty()==true && m_min_stack.isEmpty()==true){
            return Integer.MIN_VALUE;
        }
        return m_min_stack.peek();
    }
}