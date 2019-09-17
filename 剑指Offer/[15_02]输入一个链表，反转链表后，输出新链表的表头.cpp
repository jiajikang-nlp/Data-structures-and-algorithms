/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == NULL){
            return NULL;
        }
        ListNode* pre = NULL;
        ListNode* tem = NULL;
        while(pHead!=NULL){
            //保存当前节点的下一个节点，防止出现断列
            tem = pHead->next;
            // 保存好之后，则当前节点指向pre
            // 例如，当前是第一次循环，则1->2 转化成NULL<-1;方向发生了变化
            pHead->next = pre;
            // 记住当前每个节点的状态，我们将节点都向后移一步
            pre = pHead;
            pHead = tem; 
        }
        return pre;
    }
};