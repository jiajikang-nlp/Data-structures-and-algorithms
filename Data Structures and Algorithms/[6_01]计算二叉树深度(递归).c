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
typedef struct bitnode
{
    TelemType data;
    struct bitnode *lchild, *rchild;
} TreeNode, *btree;

/*递归创建二叉树*/
btree createBitree()
{
    char ch = 0;
    TreeNode *pstNextNode = NULL;
    scanf("%c", &ch);
    if (ch == '#')
    {
        /* code */
        pstNextNode = NULL;
    }
    else
    {

        /*内存分配*/
        pstNextNode = (TreeNode *)malloc(sizeof(TreeNode));
        /*创建新节点内容*/
        pstNextNode->data = ch;
        /*递归调用产生二叉树*/
        pstNextNode->lchild = createBitree();
        pstNextNode->rchild = createBitree();
    }
    return pstNextNode;
}

/*复制二叉树*/
btree Copy(btree root)
{
    btree newroot;
    if (root == NULL)
    {
        /* code */
        return NULL;
    }
    else
    {
        newroot = (btree)malloc(sizeof(TreeNode)); //内存分配
        newroot->data = root->data;                /*复制节点内容*/
        newroot->lchild = Copy(root->lchild);      /*复制左子树*/
        newroot->rchild = Copy(root->rchild);      /*复制右子树*/
    }
    return newroot;
}

/*计算二叉树的深度*/
int Depth(btree root)
{
    int m, n;
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        m = Depth(root->lchild);
        n = Depth(root->rchild);
        return (((m > n) ? m : n) + 1);
        // if (m > n)
        // {
        //     return m + 1;
        // }
        // else
        // {
        //     return n + 1;
        // }
        // printf("depth=%d", m > n ? m : n);
    } 
}

// 4、主函数
int main(void)
{
    btree root = NULL; // 原始二叉树树根
    btree temp = NULL; // 复制,二叉树树根
    int depth = 0;
    /*递归创建二叉树*/
    root = createBitree();
    printf("depth=%d",Depth(root));
    return 0;
}

