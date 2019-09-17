import java.util.ArrayList;
import java.util.Queue;
import java.util.LinkedList;
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
    public ArrayList<Integer> PrintFromTopToBottom(TreeNode root) {
        // 1、 创建树结构队列对象以及返回结果的list向量对象
        ArrayList<Integer> list = new ArrayList<>();
        Queue<TreeNode> queue = new LinkedList<>(); // 队列
        if(root==null){
            return list;
        }
        queue.offer(root); // 添加根节点到队列中
        while(!queue.isEmpty()){
            TreeNode tem = queue.peek();// 获取队列的首元素
            queue.poll();// 弹出队列头部元素，如果为空返回null
            list.add(tem.val);// 添加根节点
            if(tem.left!=null){
                queue.offer(tem.left);
            }
            if(tem.right!=null){
                queue.offer(tem.right);
            }
            
        }
        return list;
    }
}