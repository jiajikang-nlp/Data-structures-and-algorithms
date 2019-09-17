/*
 public class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}
*/
public class Solution {

    public ListNode EntryNodeOfLoop(ListNode pHead)
    {
        if(pHead==null || pHead.next==null){
            return null;
        }
        ListNode fast = pHead;
        ListNode slow = pHead;// 创建两个速度不一的指针
        while(fast!=null && fast.next!=null){
            slow = slow.next; //  速度慢的也往前走
            fast = fast.next.next;
            if(slow==fast){ //第一次相遇时m2
                slow = pHead;//重置slow到头指针
                while(fast!=slow){
                    fast = fast.next;
                    slow = slow.next;
                }
                return slow;
            }
        }
        return null;
        
    }
}