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
    TreeNode* ans=nullptr;
    int count = 0;
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot==NULL || k<0){
            return pRoot;
        }
        
        helper(pRoot,k);
        return ans;
    }
    
    private:
        void helper(TreeNode* root, int k){
        if(count>k || root==nullptr){
            return;
        }
        helper(root->left,k);
        count++;
        if(count==k){
            ans = root;
            return;
        }
        helper(root->right,k);
    }

    
};