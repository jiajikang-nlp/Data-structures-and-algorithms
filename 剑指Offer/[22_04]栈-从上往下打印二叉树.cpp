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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode *> global;
        global.push(root);
        bool isEnd = false;
        
        if (NULL == root) {
            return ret;
        }
        
        while(false == isEnd) {
            isEnd = true;
            stack<TreeNode *> local;
            
            while(global.size() != 0) {
                TreeNode *temp = global.top();
                global.pop();
                if (NULL != temp) {
                    ret.push_back(temp->val);
                    local.push(temp->left);
                    local.push(temp->right);
                    if ((NULL != temp->left) || (NULL != temp->right)) {
                        isEnd = false;
                    }
                }
                else {
                    local.push(NULL);
                    local.push(NULL);
                }
            }
            while(local.size() != 0) {
                global.push(local.top());
                local.pop();
            }
        }
        
        return ret;
    }
};