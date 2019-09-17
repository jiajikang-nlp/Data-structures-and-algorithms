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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        //用于记录双向链表的尾结点
        TreeNode* pLastNode = NULL;
        // 开始转换节点
        ConvertNode(pRootOfTree,&pLastNode);
        TreeNode* pHead = pLastNode;
        while(pHead!=NULL && pHead->left!=NULL){//找到头结点，返回
            pHead = pHead->left;
        }
        return pHead;
        
        
    }
    // 创建转换函数
    void ConvertNode(TreeNode* pNode, TreeNode** pLastNode){ // 尾部节点
        if(pNode==NULL){
            return ; // 如果树节点为空，不返回任何
        }
        TreeNode* pCur = pNode; // 创建一个当前节点
        if(pCur->left!=NULL){
            ConvertNode(pCur->left,pLastNode);
        }
        //走到这，当前结点的左子树已经转换好了，pLastNode指向左子树中的最后一个结点
        //用pLastNode指向已经转换好的链表的最后一个结点，也就是右子树第一个最小的节点
        pCur->left = *pLastNode;
        if(*pLastNode!=NULL){
            (*pLastNode)->right = pCur;
        }
        // *pLastNode指向当前节点
        *pLastNode = pCur;
        if(pCur->right!=NULL){
            ConvertNode(pCur->right,pLastNode);
        }
    }
    
};