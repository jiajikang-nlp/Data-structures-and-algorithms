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
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead==NULL){ // 判断特殊情况：如果pHead为空或者只有一个节点
            return NULL;
        }
        // 创建零时头结点，用于返回(有可能从一开始就重复)
        ListNode* head = new ListNode(-1);
        head->next = pHead; // 头结点指向首元结点
        // 建立索引指针
        ListNode* pre = head; // 建立前驱节点:指向头结点
        ListNode* cur = pHead; // 建立当前节点
        ListNode* nex = cur->next; // 当前节点的后继节点
        // 开始遍历判断
        while(cur!=NULL && cur->next!=NULL){ // 当前节点及当前节点的下一个节点不为空
            
            if(cur->val==nex->val){ // 当前节点和当前节点的下一个节点元素相同
              
                 // 循环查找，找到与当前节点不同的节点
                while(nex!=NULL && cur->val == nex->val){ //当前节点的下一个节点不为空且当前面节点的值和当前节点的下一个节点相同
                    ListNode* temp = nex;
                    nex = nex->next; // 当前节点的下一个节点=下一个节点的下一个节点
                    delete temp; // 删除内存中的重复节点
                    temp = nullptr;
                }
              
                pre->next = nex; // 删除操作：前驱节点的next直接等于现在的节点，相当于把中间的节点直接跨过
                cur = nex;
            }else{// 如果相邻的节点不相同,则往后移动一位
                pre = cur;// 前驱节点指向当前节点 ，也就是往前移动
                cur = cur->next;// 继续下一个节点
            }
            nex = cur->next;
        }
        return head->next;
    }
};