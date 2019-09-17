/*
public class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}*/

思路分析：
	            思路一：暴力破解法
				1：在第一个链表上顺序遍历每个节点，每遍历到一个节点的时候，在第二个链表上顺序遍历每个节点。
				2：如果在第二个链表上有一个节点和第一个链表上的结点一样，说明两个链表在这个节点上重合，于是就到找到了它们的公共节点。
				3：如果第一个链表的长度m,第二个链表的长度是n,那么它们的时间复杂度O(mn)
				
				步骤：
				1：用两个指针同时从两个链表的表头开始走，当走到自己的链表结尾的时候开始从另一个链表的表头开始向后走。
			    2：终止条件就是两个指针第一次相遇。此时指针位置即为所求。
				说明：两个链表的节点和是一定的，所以两个指针一定可以同时遍历完两条链表，即在最后时刻两个指针一定是重合的
			
            			
				
public class Solution {
    public ListNode FindFirstCommonNode(ListNode pHead1, ListNode pHead2) {
        ListNode p1 = pHead1;
        ListNode p2 = pHead2;
        while(p1!=p2){
   
            p1 = (p1==null ? pHead2:p1.next);
            p2 = (p2==null ? pHead1:p2.next);
        }
        return p1;
        
 
    }
}