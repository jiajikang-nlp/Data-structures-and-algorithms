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
    public int TreeDepth(TreeNode root) {
        if(root==null)
            return 0;
        TreeNode node = root;
        int left = TreeDepth(node.left);
        int right = TreeDepth(node.right);
        int res = left = left>right?left:right;
        return res + 1;// 加根节点
        
    }
}