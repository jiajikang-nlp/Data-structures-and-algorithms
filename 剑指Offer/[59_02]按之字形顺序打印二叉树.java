---------------------------------------------------------------------------------------------
import java.util.ArrayList;

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
    public ArrayList<ArrayList<Integer> > Print(TreeNode pRoot) {
        // 创建存储返回对象
        ArrayList<ArrayList<Integer>> ret = new ArrayList<>();
        // 创建存储奇偶数层节点的栈
        Stack<TreeNode> stack1 = new Stack<TreeNode>(); // 存储奇数层
        Stack<TreeNode> stack2 = new Stack<TreeNode>(); // 存储偶数层 
        stack1.push(pRoot); //将根节点(第一层也就是奇数层)存入到栈stack1
        int layer = 1; // 层数
        while(!stack1.empty() || !stack2.empty()){
            if(layer%2!=0){ // 奇数层,如果当前打印的是奇数层，则先保存左子节点，后保存右字节点到一个栈中；
                ArrayList<Integer> list = new ArrayList<>(); // 存储当前层节点
                while(!stack1.empty()){ // 当存储奇数层节点不为空
                    TreeNode t = stack1.pop(); //  移除栈顶元素
                    if(t!=null){
                        list.add(t.val); 
                        stack2.push(t.left); // 从左到右-存储节点到偶数层
                        stack2.push(t.right);
                    }
                }
                if(!list.isEmpty()){
                    ret.add(list); // 添加到输出集合中 ，当前层结束。下一层
                    layer++; // 层数怎肩膀
                }
                
            }else{ // 偶数层
                ArrayList<Integer> list = new ArrayList<>(); // 当前存储偶数层节点
                while(!stack2.empty()){
                    TreeNode t = stack2.pop(); // 弹出栈顶元素
                    if(t!=null){
                        list.add(t.val);
                        stack1.push(t.right);
                        stack1.push(t.left);
                    }
                    
                }
                if(!list.isEmpty()){
                    ret.add(list);
                    layer++;
                }
                
            }
        }
        return ret;
    }

}