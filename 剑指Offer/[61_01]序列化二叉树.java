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
    String Serialize(TreeNode root) {
        // 使用前序遍历序列化二叉树
        StringBuffer sb = new StringBuffer();
        if(root==null){
             // 空节点(#)
            sb.append("#,");// 空节点，使用'，'隔开
            return sb.toString(); // 转换成字符串
        }
           
        sb.append(root.val+",");
        sb.append(Serialize(root.left));
        sb.append(Serialize(root.right));
        return sb.toString(); // 转换成字符串
    }
    // 反序列化，根据某种遍历方式得到的序列化字符串结果，重构二叉树
    int index = -1;
    TreeNode Deserialize(String str) {
        index++;
        int len = str.length();
        if(index>=len)return null;
        // 以逗号分割，返回一个字符串数组
        String[] str1 = str.split(",");
        TreeNode node = null;
        
        // 遍历str1数组，重构数组，当前遍历元素非# 则作为一个节点插入到树中，作为上一个节点
        // 当前遍历元素为# 则表示此子树已结束，遍历下一个元素作为上一个节点的右孩子
        //  即遍历到数字作为上一个节点的左孩子，遇到#变向作为上一个节点的右孩子
        if(!str1[index].equals("#")){
            node = new TreeNode(Integer.valueOf(str1[index]));
            node.left = Deserialize(str);
            node.right = Deserialize(str);
        }
        return  node;



    }
}










