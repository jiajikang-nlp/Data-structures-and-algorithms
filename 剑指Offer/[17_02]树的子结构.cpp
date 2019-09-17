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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        /*1、判断二叉树是否为空*/
        //说明：pRoot2是B，pRoot1是A
        if(pRoot2==NULL||(pRoot1==NULL && pRoot2!=NULL)){
            return false;
        }
        //第一步：在树A中找到和树B的根节点的值一样的节点R,实际上就是树的遍历，可以采用递归的方式
        bool flag = false;
        if(pRoot1->val == pRoot2->val){// 根节点值相同-设置flag
            flag = isSubTree(pRoot1,pRoot2); // 调用第二步：判断子节点函数
        }
        // 第一个if不成立：那就开始
        if(!flag){// 为真-找到相同的左右子节点
            flag = HasSubtree(pRoot1->left,pRoot2); // 判断A的左子树节点寻找子根节点是否相同
            if(!flag){
                flag = HasSubtree(pRoot1->right,pRoot2);// 判断A的右子树节点寻找子根节点是否相同
            }
        }
        return flag;

    }
    // 第二步：再判断树A中以R为根节点的子树是不是包含和树B一样结构
    bool isSubTree(TreeNode* pRoot1,TreeNode* pRoot2){
        if(pRoot2==NULL){
            return true; // 注意
        }
        if(pRoot1==NULL && pRoot2!=NULL){ // A的根节点为空，同时B的根节点不为空--所以没有意义：返回false
            return false;
        }
        // 如果根节点相同-那就继续判断A、B的左右子节点是否也相同
        if(pRoot1->val==pRoot2->val){
            return isSubTree(pRoot1->left,pRoot2->left) && isSubTree(pRoot1->right,pRoot2->right);
        }
        else
        {
            return false;
        }
        
    }
};