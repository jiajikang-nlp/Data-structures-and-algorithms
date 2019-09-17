/*
 * @Author: jjk 
 * @Date: 2019-08-11 21:33:09 
 * @Last Modified by: jjk
 * @Last Modified time: 2019-08-14 12:42:01
 * 程序功能：复制二叉树(递归)
 * coding:gbk
 * 输入形式：AB#C##D##
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 1000
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


/*计算二叉树节点总数*/
/*如果是空树，则结点个数为0，否则，结点个数为左子树+右子树的结点个数再+1*/
int NodeCount(btree root){
    if (root == NULL)
    {
        return 0;
    }
    else
    {
         return NodeCount(root->lchild) + NodeCount(root->rchild) + 1;
    }
}

/*计算二叉树叶子节点*/
int LeadCount(btree root){
    if (root == NULL)
    {
        return 0;
    }
    if (root->lchild ==NULL && root->rchild == NULL)
    {
        /* code */
        return 1;// 如果是叶子节点返回1
    }else
    {
         return LeadCount(root->lchild) + LeadCount(root->rchild);
    }
    
}

/*计算二叉树叶子节点-非递归*/
int LeadCount2(btree root){
    int top = -1;// 栈为空
    int count = 0;
    btree s[MAXSIZE]; // 申请一个栈空间
    while (root != NULL || top != -1) // 当前树的根节点不为空 或 栈不为空（说明需要继续遍历）
    {
        /* code */
        while (root != NULL)/*当前树的根节点不为空*/
        {
            if (root->lchild == NULL && root->rchild == NULL) // 若当前根节点的左右子树都为空，则是叶子节点
            {
                /* code */
                count++;
            }
            s[++top] = root;// 先++top，然后将当前的根节点入栈
            root = root->lchild; // 然后访问当前根节点的左子树
        }
        if(top!= -1)
        { // 若此时栈不为空（此时跳出了上面的while(T != NULL),说明了当前根节点的左子树为空）
            root = s[top--]; // 先获取当前的根节点（即让当前的根节点出栈），然后 top--；
            root = root->rchild; // 然后访问当前根节点的右子树
        }
    }
    return count;
    
}

// 4、主函数
int main(void)
{
    btree root = NULL; // 原始二叉树树根
    btree temp = NULL; // 复制,二叉树树根
    int depth = 0;
    /*递归创建二叉树*/
    root = createBitree();
    printf("叶子结点总数=%d\n",LeadCount(root));
    printf("叶子结点总数=%d", LeadCount2(root));
    return 0;
}

