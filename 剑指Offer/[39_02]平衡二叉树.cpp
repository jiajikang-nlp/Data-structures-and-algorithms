#include<math.h>
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot==NULL){
            return true;
        }
        int left = getDepth(pRoot->left);
        int right = getDepth(pRoot->right);
        int diff = left-right;
        if(diff>1 || diff<-1){
            return false;
        }
        return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }
      // 获取根节点
      int getDepth(TreeNode* root){
            if(root==NULL){
                return 0;
            }
            int left = getDepth(root->left);
            int right = getDepth(root->right);
            int res = left = left>right?left:right;
            return res+1;
            
        }
};



改进：

class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int depth = 0;
        return isBalance(pRoot,depth);
    }
    bool isBalance(TreeNode* pRoot, int &pDepth){
        if(!pRoot){
            pDepth = 0;
            return true;
        }
        // 记录左节点和右 节点的深度
        int left = 0;
        int right = 0;
         // 采用传引用的方式，下层递归进行对深度进行修改以后，影响上一层
        if(isBalance(pRoot->left,left) && isBalance(pRoot->right,right)){
            if(abs(left-right)<=1){ // 计算平衡因子
                pDepth = 1+(left>right?left:right);
                return true;     
            }
        }
        return false;
    }
};