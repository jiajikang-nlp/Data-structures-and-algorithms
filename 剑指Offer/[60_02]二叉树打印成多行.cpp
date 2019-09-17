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
            vector<vector<int>> ret; // 创建返回对象
            if(pRoot==NULL){
                return ret;
            }
            // 创建一个对象
            queue<TreeNode*> q; // 创建一个队列
            q.push(pRoot); // 将头结点添加到队列中
            while(!q.empty()){ // 当队列不为空
                int size = q.size(); // 元素个数
                vector<int> list; // 存储当前行元素个数
                for(int i=0;i<size;i++){
                    TreeNode* temp = q.front(); // 弹出队首元素
                    q.pop(); // 删除
                    list.push_back(temp->val);// list.push_back(temp->val);
                    if(temp->left)
                        q.push(temp->left);
                    if(temp->right)
                        q.push(temp->right);
                }
                ret.push_back(list); // 当前行添加到ret中
            }
            return ret;
        
        }
    
};