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
    int count = 0;
    TreeNode ans;
    TreeNode KthNode(TreeNode pRoot, int k)
    {
        // 递归方法，二叉搜索树按照中序遍历的顺序打印出来是一个升序遍历，设置一个计数器，
        // 按照中序排序找到第K个即可
        helper(pRoot,k);
        return ans;
    }
    public void helper(TreeNode node, int k){
        if(node==null || k<0){
            return;
        }
        helper(node.left,k);
        count++;
        if(count == k){
            ans = node;
        }
        helper(node.right,k);
    }
}

------------------------------------------------------------

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
import java.util.Stack;
public class Solution {
    TreeNode KthNode(TreeNode pRoot, int k)
    {
        // 非递归方法：构建一个栈，思路同中序遍历的非递归方法
        if(pRoot==null||k<0){
            return null;
        }
        int count = 0; // 记录节点号
        Stack<TreeNode> stack = new Stack<>(); // 创建一个栈对象:左根右
        TreeNode temp = null;
        while(!stack.isEmpty() || pRoot!=null){
            while(pRoot!=null){ 
                stack.push(pRoot); // 存储根节点
                pRoot = pRoot.left; // 左节点
            }
            TreeNode node = stack.pop(); // 一直弹出：按照中序遍历的顺序
            count++;
            if(count==k){
                temp = node;
            }
            pRoot = node.right; // 右节点
        }
        return temp;
    }
}








