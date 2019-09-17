/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

// 队列实现
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> list; // 创建一个int型向量
        queue<TreeNode *>  myQueue; // 创建一个树结构指针队列对象
        
        /*1、判断root是否为空*/
        if(root==NULL){
            return list;// 其实就是一个空的
        }
        /*2、将二叉树根节点存入到队列中*/
        myQueue.push(root);
        /*3、当队列不为空时候*/
        while(!myQueue.empty()){
            TreeNode* temp = myQueue.front(); // 将队首元素存到到临时树节点temp
            myQueue.pop(); // 弹出队首元素
            list.push_back(temp->val); // 将根节点存入到list中
            
            if(temp->left!=NULL){
                myQueue.push(temp->left);
            }
            if(temp->right!=NULL){
                myQueue.push(temp->right);
            }
        }
        return list;
    }
};














