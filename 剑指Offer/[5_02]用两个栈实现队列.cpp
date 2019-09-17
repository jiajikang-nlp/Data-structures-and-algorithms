class Solution
{
public:
    /*入栈函数*/
    void push(int node) {
        stack1.push(node);
    }
    /*出栈函数*/
    int pop() {
        /*将stack1中的内容存入到stack2中*/
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
        // 将stack2内容出栈
        int out = stack2.top();
        stack2.pop();
        /*将stack2中内容存入到stack1中*/
        while(!stack2.empty()){
            stack1.push(stack2.top());
            stack2.pop();
        }
        return out;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};