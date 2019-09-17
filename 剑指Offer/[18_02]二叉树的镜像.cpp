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
    void Mirror(TreeNode *pRoot) {
        /*判断树是否为空*/
        if(pRoot==NULL){
            return;
        }
        /*判断树的左右子树是否为空*/
        if(pRoot->left==NULL && pRoot->right==NULL){
            return;
        }
        /*能走到这里-说明符合基本判断条件奥-那就开始交换左右子树吧*/
        TreeNode *tem = NULL; // 创建一个零时节点且初始化，用于转换
        tem = pRoot->left; // 左子树赋值给tem，以作为后面交换准备
        pRoot->left = pRoot->right; // 右子树交换给左子树
        pRoot->right = tem; // 左子树交换给右子树
        // 递归
        if(pRoot->left!=NULL){
            Mirror(pRoot->left); // 递归调用-交换树的左子树
        }
        if(pRoot->right!=NULL){
             Mirror(pRoot->right);//递归调用-交换树的右子树
        }
    }
};












