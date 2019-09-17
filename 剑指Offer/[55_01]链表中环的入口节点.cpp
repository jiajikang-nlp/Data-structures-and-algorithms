/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(!pHead){ // 先判断特殊情况
            return NULL;
        }
        ListNode *fast = pHead;
        ListNode *slow = pHead; // 创建两个指针：以不同速度的走
        while(fast && fast->next){ // 不为空时往前走
            slow = slow->next; // 速度慢的也往前走
            fast = fast->next->next;
            if(slow==fast){ // 第一次相遇时m2
                slow = pHead; // 重置slow到头指针
                while(slow-fast){ // 当不为空时
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; // 此时就是遇到了
            }
        }
        return NULL;

    }
};