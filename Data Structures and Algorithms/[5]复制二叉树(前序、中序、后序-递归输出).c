/*
 * @Author: jjk 
 * @Date: 2019-08-11 21:33:09 
 * @Last Modified by: jjk
 * @Last Modified time: 2019-08-12 19:50:51
 * 程序功能：复制二叉树(递归)
 * coding:gbk
 * 输入形式：AB#C##D##
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef char TelemType; // 二叉树元素类型
/*二叉树结构体*/
typedef struct bitnode{ 
    TelemType data;
    struct bitnode *lchild, *rchild; 
}TreeNode, *btree;


/*递归创建二叉树*/
btree createBitree(){
    char ch = 0;
    TreeNode *pstNextNode = NULL;
    scanf("%c",&ch);
    if (ch == '#')
    {
        /* code */
        pstNextNode = NULL;
    }else
    {
        
        /*内存分配*/
        pstNextNode = (TreeNode *)malloc(sizeof(TreeNode));
        /*创建新节点内容*/
        pstNextNode ->data = ch;
        /*递归调用产生二叉树*/
        pstNextNode ->lchild = createBitree();
        pstNextNode ->rchild = createBitree();
    }
    return pstNextNode;
}

/*复制二叉树*/
btree Copy(btree root){
    btree newroot;
    if (root == NULL)
    {
        /* code */
        return NULL;

    }else
    {
        newroot = (btree)malloc(sizeof(TreeNode)); //内存分配
        newroot ->data = root->data;   /*复制节点内容*/
        newroot->lchild =  Copy(root->lchild); /*复制左子树*/
        newroot->rchild =  Copy(root->rchild); /*复制右子树*/
    }
    return newroot;
}


/*二叉树前序输出*/
void pre_order(btree ptr){
    if (ptr)
    {
        /* code */
        printf("%2c",ptr->data);
        pre_order(ptr->lchild);
        pre_order(ptr->rchild);
    }
}

/*二叉树中序输出*/
void in_order(btree ptr)
{
    if (ptr)
    {
        /* code */
        pre_order(ptr->lchild);
        printf("%2c", ptr->data);
        pre_order(ptr->rchild);
    }
}

/*二叉树后序输出*/
void pos_order(btree ptr)
{
    if (ptr)
    {
        /* code */
        pre_order(ptr->lchild);
        pre_order(ptr->rchild);
        printf("%2c", ptr->data);
    }
}



// 4、主函数
int main(void)
{
    btree root = NULL; // 原始二叉树树根
    btree temp = NULL; // 复制二叉树树根
    /*递归创建二叉树*/
    root = createBitree();
    printf("\n----------原二叉树前序遍历----------\n");
    pre_order(root);

    printf("\n----------原二叉树中序遍历----------\n");
    in_order(root);

    printf("\n----------原二叉树后序遍历----------\n");
    pos_order(root);



    printf("\n--------复制该二叉树并打印----------\n\n");
    printf("\n--------复制的二叉树前序遍历----------\n");
    temp = Copy(root);
    pre_order(temp);

    printf("\n--------复制的二叉树中序遍历----------\n");
    temp = Copy(root);
    in_order(temp);

    printf("\n--------复制的二叉树后序遍历----------\n");
    temp = Copy(root);
    pos_order(temp);

    return 0;
}
