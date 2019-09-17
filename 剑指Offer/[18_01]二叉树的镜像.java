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
    public void Mirror(TreeNode root) {
        if(root!=null&&(root.left!=null||root.right!=null)){
            TreeNode tem = root.left; // 创建一个树节点，存储零时节点
            root.left=root.right;// 右子树交换给左子树
            root.right = tem; // 将左子树交换给右子树
            Mirror(root.left); // 递归调用左子树
            Mirror(root.right); // 递归调用右子树
        }
        
    }
}