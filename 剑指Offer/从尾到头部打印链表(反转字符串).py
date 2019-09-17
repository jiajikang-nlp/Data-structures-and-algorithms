

"""
/**
*    public class ListNode {
*        int val;
*        ListNode next = null;
*
*        ListNode(int val) {
*            this.val = val;
*        }
*    }
*
*/
import java.util.ArrayList;
import java.util.Stack;
public class Solution {
    public ArrayList<Integer> printListFromTailToHead(ListNode listNode) {
        // ջ���ݽṹ
        Stack<Integer> stack = new Stack<>(); /*����ջ����*/
        // ������Ԫ��ȫ�������ջ�ṹ��
        while(listNode != null){
            stack.add(listNode.val); /*���ջ�ṹԪ��*/
            listNode = listNode.next; /*�ƶ�ָ��*/
        }
        ArrayList<Integer> ret = new ArrayList<>();
        /*��ӡջ��Ԫ��*/
        while(!stack.isEmpty()){ /*�ж�ջ���Ƿ�Ϊ��*/
            ret.add(stack.pop()); /*��ջ�е�ǰԪ�س�ջ*/
        }
        return ret;
    }
}

"""

# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # ���ش�β����ͷ�����б�ֵ���У�����[1,2,3]
    def printListFromTailToHead(self, listNode):
        # write code here
        if not listNode: # ����б�Ϊ��
            return []
        result = [] # ����һ�����б�
        while listNode: # ��������
            result.append(listNode.val) # �������е�������ӵ�result�б���
            listNode = listNode.next # �ƶ�ָ�뵽��һ��
        #����ֱ����return list.reverse����Ϊpython�е�list.reverse()û�з���ֵ
        result.reverse()  #�б�ת
        return result
         
# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # ���ش�β����ͷ�����б�ֵ���У�����[1,2,3]
    def printListFromTailToHead(self, listNode):
        # write code here
        if not listNode:
            return []
        result = [] #����һ�����б�-���ڷ������յĽ��
        res = [] # ���ڴ洢������Ԫ��
        while listNode:
            res.append(listNode.val) # ��resu�б������Ԫ��
            listNode = listNode.next
        while res:
            result.append(res.pop()) # ���ջ��ǰԪ��
        return result

# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # ���ش�β����ͷ�����б�ֵ���У�����[1,2,3]
    def printListFromTailToHead(self, listNode):
        # write code here
        if not listNode:
            return []
        # ����ĵݹ�˼���Ҳ����ر����⣺�Ҵ���������ǣ�����ָ���ƶ�����һ��Ԫ�ء���ȡԪ�ء�
        # Ȼ��������������ٴ��ж��Ƿ����listNode�У������ھ���ӵ��б��У�Ҳ�����Դ˻���
        # ����ָ�룬����ǰ��Ԫ��һֱ���������
        return self.printListFromTailToHead(listNode.next) + [listNode.val]