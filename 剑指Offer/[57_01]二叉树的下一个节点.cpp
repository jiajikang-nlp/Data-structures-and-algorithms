/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        /*
        1、如果二叉树为空，则直接返回空
	    2、如果该节点右孩子存在，那么就设置一个指针，从该节点的右孩子出发，
           一直沿着指向左孩子节点的指针，一直找到最左叶子节点，此时的节点就是该节点的下一个节点。
		3、当该节点不是根节点时：如果该节点是其父子节点的左孩子(4)，那么，该节点的下一个节点就是其父亲节点(4-2)；否则,就继续向上遍历其父亲节点的父亲节点，重复前半部分的操作，返回结果，
		
        */
        if(!pNode){
            return nullptr; // null只是一个宏定义，二nullptr是一个c++关键字，用于标识空指针
        }
        if(pNode->right){ // 如果存在右子树
            pNode = pNode->right; // 获取下一个右子树
            while(pNode->left){ // 当前节点的一下节点是左子树
                pNode = pNode->left; // 一直获取左子树,知道获取完截止
            }
            return pNode; // 返回最终的左节点
        }
        // 如果该节点没有右子树
        while(pNode->next){// 循环遍历下一个节点
            TreeLinkNode* pRoot = pNode->next; //下一个节点也就是父子节点
            if(pRoot->left == pNode){
                return pRoot;
            }
            pNode = pNode->next;
        }
        return nullptr;
    }
};