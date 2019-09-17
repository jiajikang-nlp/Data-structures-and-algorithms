/**
public class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;

    }

}
*/
public class Solution {
    public TreeNode Convert(TreeNode pRootOfTree) {
        if(pRootOfTree==null){
            return pRootOfTree;
        }
        TreeNode[] pLastNode = new TreeNode[1];
        ConvertNode(pRootOfTree,pLastNode);
        //已经完成双向链表的链接，找链表头节点返回
        TreeNode p = pRootOfTree;
        while(p.left!=null){ // 直到左节点为空
            p = p.left;
        }
        return p; //返回链表头结点
    }
    
    // 创建一个转变函数
    public void ConvertNode(TreeNode root, TreeNode[] pLastNode){
        if(root==null){
            return;
        }
         if(root.left != null){
             ConvertNode(root.left,pLastNode); // 调用递归函数
         }
        // 走到这，当前结点的左子树已经转换好了，pLastNode指向左子树中的最后一个结点
        // 用pLastNode指向已经转换好的链表的最后一个结点，也就是右子树第一个最小的节点
        root.left = pLastNode[0]; // 设置left指向前一个节点
       if(pLastNode[0]!=null){
           pLastNode[0].right = root; // pLastNode right指向root
       }
        //记录当前的尾节点
        pLastNode[0] = root;
        if(root.right!=null){
            ConvertNode(root.right,pLastNode);
        }
   
    }
}