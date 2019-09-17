/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
     public TreeNode reConstructBinaryTree(int [] pre, int [] in) {
        if (pre == null || in == null) {
            // empty param
            return null;
        } 
        int preLen = pre.length; // 前序遍历序列的长度
        int inLen = in.length;// 中序遍历序列的长度
        if (preLen != inLen) {/*如果序列长度不相等，说明非法，参数不合适*/
            // inValid param
            return null;
        }

        // 只有一个元素
        if (preLen == 1) {
            return new TreeNode(pre[0]);
        }

        return buildTree(pre, 0, preLen-1, in, 0, inLen-1); // 调用函数buildTree
    }

    private TreeNode buildTree(int[] preOrder, int preBegin, int preEnd, int[] inOrder, int inBegin, int inEnd) {
        if (preBegin > preEnd || inBegin > inEnd) { // 如果前序开始位置>结束位置，中序一样的道理
            return null;
        }
        // 1、根节点的值
        int rootVal = preOrder[preBegin]; // 也就是前序遍历的第一个元素

        // 2、找到该值在中序序列中的索引      
        int rootIdxInOrder = -1;
        for (int i=inBegin; i<= inEnd; i++) {
            if (inOrder[i] == rootVal) { // 中序遍历中根节点的位置
                rootIdxInOrder = i;// 将中序遍历中根节点的位置的索引赋值给rootIdxInOrder
                break;
            }
        }
        // 没找到，参数不合法，返回null
        if (rootIdxInOrder < 0) {
            return null;
        }

        // 3、生成头节点
        TreeNode root = new TreeNode(rootVal);

        // 只有一个元素，直接返回，减少递归层次
        if (preBegin == preEnd && inBegin == inEnd) {
            return root; 
        }

        // 4、左子树长度
        int leftTreeLen = rootIdxInOrder - inBegin;

        // 5、前序遍历序列中，左子树遍历序列结束索引为preBegin + 1 + leftTreeLen - 1
        int preIdxLeftTreeEnd = preBegin + leftTreeLen;

        // 6、递归处理左右子树，挂接左右节点， 要去掉当前根节点的索引
        root.left = buildTree(preOrder, preBegin+1, preIdxLeftTreeEnd, inOrder, inBegin, rootIdxInOrder-1);
        root.right = buildTree(preOrder, preIdxLeftTreeEnd+1, preEnd, inOrder, rootIdxInOrder+1, inEnd);
        return root;
    }
}