/*
 * @Author: jjk 
 * @Date: 2019-08-11 21:33:09 
 * @Last Modified by: jjk
 * @Last Modified time: 2019-08-12 19:50:51
 * �����ܣ����ƶ�����(�ݹ�)
 * coding:gbk
 * ������ʽ��AB#C##D##
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char TelemType; // ������Ԫ������
/*�������ṹ��*/
typedef struct bitnode
{
    TelemType data;
    struct bitnode *lchild, *rchild;
} TreeNode, *btree;

/*�ݹ鴴��������*/
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

        /*�ڴ����*/
        pstNextNode = (TreeNode *)malloc(sizeof(TreeNode));
        /*�����½ڵ�����*/
        pstNextNode->data = ch;
        /*�ݹ���ò���������*/
        pstNextNode->lchild = createBitree();
        pstNextNode->rchild = createBitree();
    }
    return pstNextNode;
}

/*���ƶ�����*/
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
        newroot = (btree)malloc(sizeof(TreeNode)); //�ڴ����
        newroot->data = root->data;                /*���ƽڵ�����*/
        newroot->lchild = Copy(root->lchild);      /*����������*/
        newroot->rchild = Copy(root->rchild);      /*����������*/
    }
    return newroot;
}

/*��������������*/
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

// 4��������
int main(void)
{
    btree root = NULL; // ԭʼ����������
    btree temp = NULL; // ����,����������
    int depth = 0;
    /*�ݹ鴴��������*/
    root = createBitree();
    printf("depth=%d",Depth(root));
    return 0;
}

