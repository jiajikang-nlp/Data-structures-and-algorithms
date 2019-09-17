/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot==NULL){
            return 0;
        }
        //TreeNode* node = pRoot; // 创建一个根节点
        int left = TreeDepth(pRoot->left);
        int right = TreeDepth(pRoot->right);
        int res = left=left>right?left:right;
        return res+1;
    
    }
};