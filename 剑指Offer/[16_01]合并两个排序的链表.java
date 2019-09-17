/*
public class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}*/
public class Solution {
    public ListNode Merge(ListNode list1,ListNode list2) {
        // 递归思想
        /*1、判断链表是否为空-哪个为空就先返回另一个链表*/
        if(list1==null){ 
            return list2;
        }
        if(list2==null){
            return list1;
        }
        if(list1.val<=list2.val){ /*当链表1的值<=链表2的值*/
            list1.next =Merge(list1.next,list2);// 递归调用-判断list1的next的值的大小-赋值给链表1的next节点
            return list1;
        }else{
            list2.next = Merge(list1,list2.next);
            return list2;
        }
        
        
        
    }
}