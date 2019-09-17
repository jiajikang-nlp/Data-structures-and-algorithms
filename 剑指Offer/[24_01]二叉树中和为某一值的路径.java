import java.util.ArrayList;
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
    ArrayList<ArrayList<Integer>> res = new ArrayList<>(); // 用于存储路径
    ArrayList<Integer> path = new ArrayList<>(); // 路径
    public ArrayList<ArrayList<Integer>> FindPath(TreeNode root,int target) {
        if(root == null){
            return res;
        }
        findPath(root,target,0);
        return res;
    }
    public void findPath(TreeNode root,int target,int sum){
        //因为FindPath中和 下面程序中都进行了判null操作，root绝对不可能为 null
        path.add(root.val);
        sum+=root.val; // 求节点和
        //已经到达叶子节点，并且正好加出了target
        if(sum==target && root.left==null && root.right==null){
            // 将该路径加入到ret结果集合中
            res.add(new ArrayList(path));
        }
        //如果左子树非空，递归左子树
        if(root.left!=null){
            findPath(root.left,target,sum);
        }
        // //如果右子树非空，递归右子树
        if(root.right!=null){
            findPath(root.right,target,sum);
        }
        //无论当前路径是否加出了target，必须去掉最后一个，然后返回父节点，去查找另一条路径，最终的path肯定为null
    path.remove(path.size()-1);
    }
}


----------------------------------------------------


import java.util.ArrayList;
import java.util.Stack;
import java.util.List;
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
    public ArrayList<ArrayList<Integer>> FindPath(TreeNode root,int target) {
        ArrayList<ArrayList<Integer>> pathList = new ArrayList<ArrayList<Integer>>();
        if(root==null||target==0){//如果此树为空则直接返回
            return pathList;
        }
        Stack<Integer> path = new Stack<>();//定义栈来存储一条路径
        findPath(root,target,path,pathList);
        return pathList;
 
    }
    private void findPath(TreeNode root,int target,Stack<Integer> path,ArrayList<ArrayList<Integer>> pathList){
        if(root==null){
            return;
        }
        //判断其是不是叶子结点，如果是看其是不是等于期望值，是的话直接添加到ArrayList集合当中
        if(root.left==null && root.right==null){
            if(root.val==target){//如果等于期望值，则添加到list集合中
			
                ArrayList<Integer> list = new ArrayList<>();
                for(int val:path){// 遍历栈-添加到list集合中
                    list.add(val);
                }
                list.add(root.val);// 将根节点值添加入集合
                pathList.add(list);//将这条路径添加到pathList集合中
            }
        }else{
            //不是叶子结点，前序遍历，将当前结点值放入path栈中
            path.push(root.val);
            findPath(root.left,target-root.val,path,pathList);
            findPath(root.right,target-root.val,path,pathList);
            //在返回到父结点之前，在路径上删除当前结点的值
            path.pop();
        }
        
    }
    
}




