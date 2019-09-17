public class Solution {
    public boolean VerifySquenceOfBST(int [] sequence) {
        // 首先要做的就是排空
        if(sequence==null || sequence.length==0){
            return false; // 因为是布尔型奥
        }
        // 2：如果只有一个根节点那就没有继续下去的意思啦，直接输出一个根节点，这是完全符合题目要去的奥
        if(sequence.length==1){
            return true;
        }
        int len = sequence.length-1;
        return judge(sequence,0,len);
    }
    // 定义判断函数
    private boolean judge(int[] sequence, int start, int last){
        if(start>last){
            return true;
        }
         // 后序遍历，最后的一个位置元素即是根节点
        int i = last;
        // 找到的i即是分割左子树与右子树的位置。i-1的位置到start为左子树，i到last-1位置为右子树
        // 因为二叉树的左子树的所有元素小于根节点的值，右子树的所有元素的值大于根节点的值
        // 判断右子树---获取左子树右子树的临界分隔符
        while(i>start && sequence[i-1]>sequence[last]){ // 右子树都>根节点
            --i;
        }
        // 左子树的元素都<根节点
        for(int j=i-1;j>=start;--j){ // 从后往前(根节点外)遍历，从临界点开始：左子树<根节点
            if(sequence[j]>sequence[last]){
                return false;
            }
        }
        
        //在递归判断左子树与右子树是否满足后序遍历
        return judge(sequence,start,i-1) && judge(sequence,i,last-1);  
    }
}