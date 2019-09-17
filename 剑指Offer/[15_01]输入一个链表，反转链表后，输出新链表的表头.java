/*
public class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}*/
public class Solution {
    public ListNode ReverseList(ListNode head) {
        if(head == null){
            return null;
        }
        ListNode pre = null;  // 指向下一个节点
        ListNode tem = null; // 暂时保存当前面节点
        while(head!=null){
            tem = head.next; // 让next指向下一个节点
            head.next = pre; // 让pre始终指向当前head的前一个节点，这样可以反转节点
            pre = head;
            head = tem;
        }
        return pre;

    }
}