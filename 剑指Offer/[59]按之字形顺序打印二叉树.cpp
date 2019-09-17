/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        
        vector<vector<int>> ret; // 用于返回结果
        // 特殊情况
        if(pRoot==NULL)
            return ret;
        // 创建栈
        stack<TreeNode*> stacks[2]; // stacks[0] 用来保存奇数层节点，stacks[1]用来存储偶数层节点
        int cur = 0; // 0 表示当前遍历的是奇数层 1表示当期遍历的是偶数层
        int next = 1;
        stacks[cur].push(pRoot); // 当前节点(根节点)存入到栈中
        vector<int> curVec; // 用来存储当前层所有节点的值
        while(!stacks[0].empty() || !stacks[1].empty()){
            
            TreeNode* pNode = stacks[cur].top(); // 出栈-返回栈顶元素
            curVec.push_back(pNode->val); // 值存入到curVec中
            stacks[cur].pop(); // 存完之后，删除
            
            if(cur==0){ //如果当前遍历的是奇数层，依次将其左子结点和右子结点保存在stacks[1]中
                if(pNode->left){ // 如果左节点存在:
                    stacks[next].push(pNode->left);
                }
                if(pNode->right){
                    stacks[next].push(pNode->right);
                }
            }else{//  如果当前打印的是偶数层，则先保存右字节点再保存左子节点到另一个栈中
                if(pNode->right){
                    stacks[next].push(pNode->right);
                }
                if(pNode->left){
                    stacks[next].push(pNode->left);
                }
                
                
            }
            
            if(stacks[cur].empty()){ // 堆栈为空则返回真
                ret.push_back(curVec); // curVec用来存储当前层所有节点的值,存入到ret中
                curVec.clear(); //  清空当前层所有节点的值
                cur = 1-cur;//1-0，进入到下一个节点和节点的子节点
                next = 1-next;// 1-1
            }
        }
        return ret;
    }
    
};













