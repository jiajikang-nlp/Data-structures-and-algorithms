/*
public class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}*/
public class Solution {
    public ListNode FindKthToTail(ListNode head,int k) {
        if(head==null) return null;
        ListNode p1 = head;
        ListNode p2 = head; // 开始p1，p2指针都指向头结点
        while(k>0&&p2 !=null){
            p2 = p2.next; // 下一个节点赋值给p2
            k--;
        }
        //p2指向head说明k<=0,p2==null && k>0说明k超过了链表的长度
        if(p2==head || (p2==null && k>0)){
            return null;
        }
        while(p2!=null){ // 还未到链表的尾节点
            p1 = p1.next;
            p2 = p2.next;
        }
        return p1;
    }
}