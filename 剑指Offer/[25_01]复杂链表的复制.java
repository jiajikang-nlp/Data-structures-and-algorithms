/*
public class RandomListNode {
    int label;
    RandomListNode next = null;
    RandomListNode random = null;

    RandomListNode(int label) {
        this.label = label;
    }
}
*/
public class Solution {
    // 主函数
    public RandomListNode Clone(RandomListNode pHead)
    {
        // 先判断一下链表是否为空，如果为空，那还用复制的必要嘛
        if(pHead==null){
            return null;
        }
        // 一共分为三步
        // 第一步：复制节点
        // 第二步：为复制结点的random指针域赋值
        // 第三步：将结点和复制结点分为两个链表
        copyNode(pHead); // 复制节点函数
        connectRandomNodes(pHead); // 给复制结点的random指针域赋值
        return split2list(pHead);
    }
    // 1. 加入copy结点
    public void copyNode(RandomListNode pHead){
        
        RandomListNode pNode = pHead; // 创建结点
        while(pNode !=null){
            //创建cloneNode结点即A'结点,使其指向原始链表中A结点的下一结点B,不过A'的m_pSibling设置为null
            RandomListNode cloneNode  = new RandomListNode(pNode.label);// pNode.label
            //cloneNode.label = pNode.lable; // 将A结点给cloneNode
            cloneNode.next = pNode.next;// 将A节点的下一个给cloneNode的下一个
            //cloneNode.random = null;
            pNode.next = cloneNode; // 将A结点指向A'节点
            //使pNode指向A的下一结点B并以此循环修改(此时中间已将克隆结点A‘插入了原始列表)
            pNode =cloneNode.next;
        }
    }
    // 2、设置每个结点的random指针(注：random为空结点不做修改)
    public void connectRandomNodes(RandomListNode pHead){
        RandomListNode pNode = pHead; // 创建结点
        while(pNode!=null){
            RandomListNode cloneNode = pNode.next;
            if(pNode.random!=null){
                cloneNode.random = pNode.random.next;
            }
            pNode = cloneNode.next;
        }
    }
    
    // 2、拆分链表
    public RandomListNode split2list(RandomListNode pHead){
        RandomListNode pNode = pHead;
        RandomListNode cloneNode = null;
        RandomListNode cloneHead = null;
        if(pNode!=null){
            cloneHead = cloneNode = pNode.next;
            pNode.next = cloneNode.next;
            pNode = pNode.next;
        }
        while(pNode!=null){
            cloneNode.next = pNode.next;
            cloneNode = cloneNode.next;
            pNode.next = cloneNode.next;
            pNode = pNode.next;
        }
        return cloneHead;
    }
 
}