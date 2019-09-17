class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size()<=0){
            return false;
        }
        /*只有一个元素*/
        if(sequence.size()==1){
            return true;
        }
        /*直接调用判断函数*/
        return judge(sequence,0,sequence.size()-1);
    }
    // a: 整数数列；start：开始位置；end：结束位置也就是根节点的位置
    bool judge(vector<int> a,int start, int end){
        // 1、当起始位置大于终止位置的时候，说明这颗子树为空，直接返回true即可。
        if(start>=end){
            return true;
        }
        // 找到的i即是分割左子树与右子树的位置。i-1的位置到start为左子树，i到last-1位置为右子树
        // 因为二叉树的左子树的所有元素小于根节点的值，右子树的所有元素的值大于根节点的值
        int i = end;
        while(i>start && a[i-1]>a[end]){ /*获取临界点,顺道判断了右子树>根节点*/
            --i;
        }
        // int j =i; // 此时就是临界点
        for(int j=i-1;j>=start;--j){ // 倒序方式进行判断左子树小于右子树
            if(a[j]>a[end]){
                return false;
            }
        }

        return (judge(a,start,i-1)) && (judge(a,i,end-1)); 
    }
 
    
};