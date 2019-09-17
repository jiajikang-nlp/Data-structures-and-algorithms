import java.util.ArrayList;
import java.util.Queue;
import java.util.LinkedList;

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
    ArrayList<ArrayList<Integer> > Print(TreeNode pRoot) {
        // 层序遍历二叉树，依次打印出每层节点，遇到空节点跳过。
        ArrayList<ArrayList<Integer>> ret = new ArrayList<ArrayList<Integer>>();
        if(pRoot == null){
            return ret;
        }
        // 创建一个队列
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.add(pRoot); // 将根节点添加到队列中
        
        int last = q.size(); // 下一行元素个数
        int count = 0;  // 本层打印多少个
        while(!q.isEmpty()){
            count = 0;
            last = q.size(); //元素个数
            ArrayList<Integer> list = new ArrayList<Integer>();
            while(count<last){
                TreeNode tr = q.poll(); // 弹出
                count++;
                list.add(tr.val); // 当前行元素添加到list中
                if(tr.left!=null){
                    q.add(tr.left); // 添加到队列
                }
                if(tr.right!=null){
                    q.add(tr.right);
                }
            }
            ret.add(list);
        }
        return ret;
    }
    
}
-------------------------------------------------------------------------------------------------------
import java.util.ArrayList;
import java.util.Queue;
import java.util.LinkedList;

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
    ArrayList<ArrayList<Integer> > Print(TreeNode pRoot) {
        ArrayList<ArrayList<Integer>> ret = new ArrayList<ArrayList<Integer>>(); // 创建结果返回对象
        if(pRoot==null){
            return ret;
        }
        
        Queue<TreeNode> q = new LinkedList<TreeNode>();// 创建一个队列
        q.add(pRoot); // 根节点添加到队列
        
        while(!q.isEmpty()){ // 当队列不为空时
            int size = q.size(); // 队列中元素个数
            ArrayList<Integer> list = new ArrayList<>(); //存储一行
            for(int i=0;i<size;i++){
                TreeNode temp = q.poll(); // 弹出队列顶部元素
                list.add(temp.val); // 将队列弹出的元素添加到list集合中
                if(temp.left!=null)
                    q.add(temp.left);
                if(temp.right!=null) 
                    q.add(temp.right);
            }
            ret.add(list); // 将一行的元素添加到ret集合中
        }
        return ret;
    }
}


 





