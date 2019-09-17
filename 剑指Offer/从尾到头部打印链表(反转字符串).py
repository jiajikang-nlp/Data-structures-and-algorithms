

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
        // 栈数据结构
        Stack<Integer> stack = new Stack<>(); /*创建栈对象*/
        // 将链表元素全部存放在栈结构中
        while(listNode != null){
            stack.add(listNode.val); /*添加栈结构元素*/
            listNode = listNode.next; /*移动指针*/
        }
        ArrayList<Integer> ret = new ArrayList<>();
        /*打印栈内元素*/
        while(!stack.isEmpty()){ /*判断栈中是否为空*/
            ret.add(stack.pop()); /*将栈中当前元素出栈*/
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
    # 返回从尾部到头部的列表值序列，例如[1,2,3]
    def printListFromTailToHead(self, listNode):
        # write code here
        if not listNode: # 如果列表不为空
            return []
        result = [] # 创建一个空列表
        while listNode: # 遍历链表
            result.append(listNode.val) # 将链表中的数据添加到result列表中
            listNode = listNode.next # 移动指针到下一个
        #不能直接用return list.reverse是因为python中的list.reverse()没有返回值
        result.reverse()  #列表翻转
        return result
         
# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # 返回从尾部到头部的列表值序列，例如[1,2,3]
    def printListFromTailToHead(self, listNode):
        # write code here
        if not listNode:
            return []
        result = [] #创建一个空列表-用于返回最终的结果
        res = [] # 用于存储链表中元素
        while listNode:
            res.append(listNode.val) # 往resu列表中添加元素
            listNode = listNode.next
        while res:
            result.append(res.pop()) # 添加栈当前元素
        return result

# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # 返回从尾部到头部的列表值序列，例如[1,2,3]
    def printListFromTailToHead(self, listNode):
        # write code here
        if not listNode:
            return []
        # 这里的递归思想我不是特别的理解：我大体的理解就是：首先指针移动到下一个元素、获取元素。
        # 然后调用自身函数，再次判断是否存在listNode中，不存在就添加到列表中，也就是以此滑动
        # 链表指针，让最前的元素一直保持在最后。
        return self.printListFromTailToHead(listNode.next) + [listNode.val]