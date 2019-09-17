class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        /*1、判断是否为空以及是否长度相同，如果不相同就没有比较的意义*/
        if(pushV.size()==0||popV.size()==0||pushV.size()!=popV.size()){
            return false;
        }
        /*2、创建辅助栈结构以及遍历元素，判断*/
        stack<int> stack;
        for(int i=0,j=0;i<pushV.size();i++){
            stack.push(pushV[i]); // 添加第一个序列元素到辅助栈中
            while(!stack.empty() && stack.top()==popV[j]){ // 如果栈顶的元素相同
                stack.pop(); // 弹出
                j++;
            }
        }
        return stack.empty(); // 返回布尔型是否为空
    }
};

https://blog.csdn.net/tham_/article/details/44733101