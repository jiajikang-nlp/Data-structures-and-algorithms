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
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot==NULL){ // 如果根节点为空，直返返回真
            return true;
        }
        return isSymmetrical2(pRoot->left,pRoot->right);
    }
    bool isSymmetrical2(TreeNode* left, TreeNode* right){
            if(left==NULL && right==NULL) return true;
            if(left==NULL || right==NULL) return false;
            if(left->val == right->val){
                return isSymmetrical2(left->left,right->right) && isSymmetrical2(left->right,right->left);
            }
        return false;
        }
};