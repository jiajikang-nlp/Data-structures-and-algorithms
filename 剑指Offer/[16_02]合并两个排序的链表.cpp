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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1==NULL){
            return pHead2;
        }
        if(pHead2==NULL){
            return pHead1;
        }
        if(pHead1->val < pHead2->val){
            pHead1->next = Merge(pHead1->next,pHead2);
            return pHead1;
        }else{
            pHead2->next = Merge(pHead2->next,pHead1);
            return pHead2;
        }
         
        
    }
};