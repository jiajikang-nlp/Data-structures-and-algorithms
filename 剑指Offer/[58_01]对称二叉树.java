/*
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
    boolean isSymmetrical(TreeNode pRoot)
    {
        if(pRoot==null){
            return true; // 如果为空之间返回真
        }
        return isSymmetrical2(pRoot.left,pRoot.right);
    }
    public boolean isSymmetrical2(TreeNode left,TreeNode right){
        if(left==null && right==null) return true;
        if(left==null||right==null) return false;
        if(left.val==right.val){ // 如果左子树的值=右子树的值
            return isSymmetrical2(left.left,right.right) && isSymmetrical2(left.right,right.left);
        }
        return false;
    }
}

--------------------------------------------------

/*
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
    boolean isSymmetrical(TreeNode pRoot)
    {
        TreeNode node = getMirror(pRoot); // 根节点
        return isSymmetrical2(pRoot,node);
        
    }
    // 判断左右子节点是否相等
    boolean isSymmetrical2(TreeNode pRoot,TreeNode node){
        if(pRoot == null && node == null) return true;
        if(pRoot == null||node == null) return false;
        if(pRoot.val == node.val){
            return isSymmetrical2(pRoot.left,node.left) && isSymmetrical2(pRoot.right,node.right);
        }
        return false;
    }
    
    TreeNode getMirror(TreeNode pRoot){
        if(pRoot==null){
            return null;
        }
        TreeNode root = new TreeNode(pRoot.val); // 创建一个树结构对象且获取初始值
        root.right = getMirror(pRoot.left);
        root.left = getMirror(pRoot.right); // 左右节点交换
        return root; // 返回根节点
    }
}































