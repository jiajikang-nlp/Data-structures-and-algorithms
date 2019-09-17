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
    public boolean HasSubtree(TreeNode root1,TreeNode root2) {
        /*1、判断二叉树是否为空*/
        if(root2==null||(root1==null && root2!=null)){
            return false;
        }
        boolean flag = false;
        // 第一步：在树A中找到和树B的根节点的值一样的节点R,实际上就是树的遍历，可以采用递归的方式
        if(root1.val==root2.val){ // 根节点相同-调用第判断左右叶子节点函数
            flag = isSubTree(root1,root2); // 判断相对根节点的叶子节点
        }
        
        if(!flag){// 为假-找到相同的根节点
            flag = HasSubtree(root1.left,root2); // 递归调用-判断左子树
            if(!flag){ // 左子树未能找到相同的根节点-继续以root1的右节点查找
                flag = HasSubtree(root1.right,root2);
            }
        }
        
        return flag; // 最终反馈ture or false
    }
    // 第二步：判断A中以R为根节点的子树是不是和树B具有相同的结构。
    private boolean isSubTree(TreeNode root1,TreeNode root2){
        if(root2==null){
            return true;
        }
        if(root1==null && root2!=null){
            return false;
        }
        if(root1.val == root2.val){
            return isSubTree(root1.left,root2.left) && isSubTree(root1.right,root2.right);
        }else{
            return false;
        }
    }
}