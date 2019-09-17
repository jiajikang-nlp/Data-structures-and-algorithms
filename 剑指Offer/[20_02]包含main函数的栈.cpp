#include <assert.h>
class Solution {
public:
    // 第一步：创建数据栈和存储最小元素辅助栈
    stack<int> m_data, m_min;
    // 第二步：数据入栈
    void push(int value) {
        m_data.push(value);// 元素进入到数据栈
        if(m_min.size() == 0 || m_min.top() > value){ // 辅助栈没有元素或者辅助栈顶的元素大于value时候
            m_min.push(value);// 将元素存入到辅助栈
        }else {
            m_min.push(m_min.top()); // 否则也就是说明：辅助栈顶的元素小，那就吧辅助栈顶的元素存入到辅助栈中
        }
    }
    // 第三步：弹出
    void pop() {
        // 说明:保持原信息内容不变     nNewSize<=0表示清除缓冲区
        assert(m_data.size() >0 && m_min.size() > 0); // 利用断言函数
        m_data.pop(); // 弹出
        m_min.pop();
    }
    int top() {
        assert(m_data.size() > 0 && m_min.size() > 0);
        return m_min.top();//这个top在这里根本就没有起到作用，返回栈顶的元素，但不删除该元素
    }
    int min() {
        assert(m_data.size() > 0 && m_min.size() > 0);
        return m_min.top();
    }
};

// 关于c++的stack相关的知识
https://blog.csdn.net/tham_/article/details/44733101
