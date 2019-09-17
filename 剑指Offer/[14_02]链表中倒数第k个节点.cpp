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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead==NULL||k<=0){
            return NULL;
        }
        // 创建两个指针且都指向头结点
        ListNode* p1=pListHead;
        ListNode* p2=pListHead;
        //让p2先走，走k-1步，如果k大于链表长度返回空，否则继续走
        while(k>1){
            if(p2->next!=NULL){
                p2 = p2->next;
                k -=1;
            }else{
                return NULL;
            }
        }
        //两个指针一起走，一直走到p2为最后一个元素，p1即为所求。
        while(p2->next!=NULL){
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    
    }
};