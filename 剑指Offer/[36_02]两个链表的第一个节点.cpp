/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

思路分析：
	            思路一：暴力破解法
				1：在第一个链表上顺序遍历每个节点，每遍历到一个节点的时候，在第二个链表上顺序遍历每个节点。
				2：如果在第二个链表上有一个节点和第一个链表上的结点一样，说明两个链表在这个节点上重合，于是就到找到了它们的公共节点。
				3：如果第一个链表的长度m,第二个链表的长度是n,那么它们的时间复杂度O(mn)
				
				步骤：
				1：用两个指针同时从两个链表的表头开始走，当走到自己的链表结尾的时候开始从另一个链表的表头开始向后走。
			    2：终止条件就是两个指针第一次相遇。此时指针位置即为所求。
				说明：两个链表的节点和是一定的，所以两个指针一定可以同时遍历完两条链表，即在最后时刻两个指针一定是重合的
			
            			
				

class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode *p1 = pHead1;
        ListNode *p2 = pHead2;
        while(p1!=p2){
            p1 = (p1==NULL ? pHead2:p1->next);
            p2 = (p2==NULL ? pHead1:p2->next);
        }
        return p2;
        
    }
};



思路二：
				    1、先数出两条链表的长度，得到长度差d，
					2、将长链表从头结点往后走d步，之后第二个链表从头开始，
					3、两个链表一起一步一步走，直到两个链表的节点第一次相等为止，此时指针位置即为所求。



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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode *p1 = pHead1;
        ListNode *p2 = pHead2;
        int len1=0;
        int len2=0;
        int diff=0;
        while(p1!=NULL){
            p1 =p1->next;
            len1++;   
        }
        while(p2!=NULL){
            p2 = p2->next;
            len2++;
        }
        if(len1>len2){
            diff = len1-len2;
            p1 = pHead1; // 初始化指针
            p2 = pHead2; 
        }else{
            diff = len2-len1;
            p1 = pHead2;
            p2 = pHead1;
        }
        for(int i=0;i<diff;i++){
            p1 = p1->next;
        }
        while(p1!=NULL && p2!=NULL){
            if(p1==p2){
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};





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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode *p1 = pHead1;
        ListNode *p2 = pHead2;
        while(p1!=p2){
            //没有到链表尾部，则继续往后走
            if(p1!=NULL){
                p1 = p1->next;
            }
            if(p2!=NULL){
                p2 = p2->next;
            }
            if(p1!=p2){
                //若已到链表尾，则令其指向另一链表头 
                if(p1==NULL) p1=pHead2;
                if(p2==NULL) p2=pHead1;
            }
        }
        return p1;
    }
};




























