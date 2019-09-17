/*
public class TreeLinkNode {
    int val;
    TreeLinkNode left = null;
    TreeLinkNode right = null;
    TreeLinkNode next = null;

    TreeLinkNode(int val) {
        this.val = val;
    }
}
*/
public class Solution {
    public TreeLinkNode GetNext(TreeLinkNode pNode)
    {
        /*
        这里需要注意的是pNode.next是pNode结点的父结点
        1、如果有右子树，那么下一个结点就是右子树最左边的节点。
        2、如果没有右子树，分两种情况，
           第一种情况：如果该结点为父结点的左孩子，则该结点的父节点pNode.next则为该结点的下一个结点。
           第二种情况：则是如果该结点的为父节点的右孩子，则向上找父节点，直到父节点为该父节点的左孩子，则该父节点的父节点
        为下一个结点。
        */
        if(pNode==null){
            return null;
        }
        if(pNode.right!=null){ // 如果存在右节点
            pNode = pNode.right;
            while(pNode.left != null){//1、如果有右子树，那么下一个结点就是右子树最左边的节点。
                pNode = pNode.left;
            }
            return pNode; // 返回最终的左节点
        }
        while(pNode.next!=null){
            if(pNode.next.left == pNode){
                return pNode.next;
            }
            pNode = pNode.next;
        }
        return null; 
    }
}