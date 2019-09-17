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
    public ListNode deleteDuplication(ListNode pHead)
    {
        // 判断空或者是否只有一个节点
        if(pHead==null || pHead.next==null){
            return pHead;
        }
     
  
        ListNode head = new ListNode(0); // 我们采用带头链表，创建一个头结点
        head.next = pHead; // 把头节点链接在链表上:链表的第一个节点
        
        ListNode pre = head; // 用来保存头结点，用于返回删除后的链表
        ListNode nex = head.next; // 下一个节点 pre.next
        while(nex!=null){ // 下一个节点不为null
            // 遍历节点的同时判断当前节点与下一个节点是否相同，如果相同则删除，
            // 删除方法  使用相同节点的前一个节点，指向相同节点的下一个节点如图
            if(nex.next!=null && nex.val==nex.next.val){//nex和nex的下一个节点值相等 也就是出现重复节点
                while(nex.next!=null&&nex.next.val==nex.val){ // 连续出现重复节点
                    nex = nex.next;
                }
                //连续相等的节点已经遍历结束
                pre.next = nex.next; // 
                nex = nex.next;
            }else{// nex和nex的下一个节点值不等，说明未出现重复的节点：
                nex = nex.next;
                pre = pre.next; // 头指针和下一个节点都往前移动
            }
        }
        return head.next; // 返回第一个元素
    }
}
---------------------------------------------------------------------------------------------------
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
    public ListNode deleteDuplication(ListNode pHead)
    {
        if(pHead == null){
            return null; // 如果头结点为空
        }
        // 创建头结点(因为可能从头就开始重复)，以留作备用返回
        ListNode head = new ListNode(0);
        head.next = pHead;// 头结点指向首元结点
        
        ListNode cur = pHead; // 创建当前节点且初始化
        // 前驱节点
        ListNode pre = head; // 前驱节点指向头结点
        
        // 开始遍历判断
        while(cur != null && cur.next !=null){ // 当前节点及当前节点的下一个节点不为空
            if(cur.val == cur.next.val){ // 当前节点和当前节点的下一个节点元素相同
                int val = cur.val; // 记录当前相同的值，用于下一个节点的判断
                while(cur !=null && cur.val==val){  // 这一步用于跳过连续相同的节点，也就是删除
                    cur = cur.next;
                }
                pre.next = cur; // 删除操作：前驱节点的next直接等于现在的节点，相当于把中间的节点直接跨过
            }else{ // 如果相邻的节点不相同
                pre = cur; // 前驱节点指向当前节点 ，也就是往前移动
                cur = cur.next; // 继续下一个节点
            }
            
        }
        return head.next;

    }
}

















