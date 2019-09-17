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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> > pathList;
        vector<int> path; // 相当于栈
        if(root==NULL){
            return pathList;
        }
        findPath(root,expectNumber,path,pathList);
        return pathList;
    }
    void findPath(TreeNode *root, int target,vector<int> &path,vector<vector<int>> &pathList){
        if(root->left==NULL && root->right==NULL){
            if(root->val==target){
                path.push_back(root->val);
                pathList.push_back(path);
                path.pop_back(); // 删除最后一个元素（栈顶元素）
            }
            return;
        }
        path.push_back(root->val); // 存入根节点
        if(root->left)
            findPath(root->left,target-root->val,path,pathList);
        if(root->right){
           findPath(root->right,target-root->val,path,pathList);
        }
        path.pop_back();
        
    }
};