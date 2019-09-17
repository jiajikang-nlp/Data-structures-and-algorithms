/*
 * @Author: jjk 
 * @Date: 2019-08-11 21:33:09 
 * @Last Modified by: jjk
 * @Last Modified time: 2019-08-14 12:42:01
 * �����ܣ����ƶ�����(�ݹ�)
 * coding:gbk
 * ������ʽ��AB#C##D##
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 1000
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


/*����������ڵ�����*/
/*����ǿ������������Ϊ0�����򣬽�����Ϊ������+�������Ľ�������+1*/
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

/*���������Ҷ�ӽڵ�*/
int LeadCount(btree root){
    if (root == NULL)
    {
        return 0;
    }
    if (root->lchild ==NULL && root->rchild == NULL)
    {
        /* code */
        return 1;// �����Ҷ�ӽڵ㷵��1
    }else
    {
         return LeadCount(root->lchild) + LeadCount(root->rchild);
    }
    
}

/*���������Ҷ�ӽڵ�-�ǵݹ�*/
int LeadCount2(btree root){
    int top = -1;// ջΪ��
    int count = 0;
    btree s[MAXSIZE]; // ����һ��ջ�ռ�
    while (root != NULL || top != -1) // ��ǰ���ĸ��ڵ㲻Ϊ�� �� ջ��Ϊ�գ�˵����Ҫ����������
    {
        /* code */
        while (root != NULL)/*��ǰ���ĸ��ڵ㲻Ϊ��*/
        {
            if (root->lchild == NULL && root->rchild == NULL) // ����ǰ���ڵ������������Ϊ�գ�����Ҷ�ӽڵ�
            {
                /* code */
                count++;
            }
            s[++top] = root;// ��++top��Ȼ�󽫵�ǰ�ĸ��ڵ���ջ
            root = root->lchild; // Ȼ����ʵ�ǰ���ڵ��������
        }
        if(top!= -1)
        { // ����ʱջ��Ϊ�գ���ʱ�����������while(T != NULL),˵���˵�ǰ���ڵ��������Ϊ�գ�
            root = s[top--]; // �Ȼ�ȡ��ǰ�ĸ��ڵ㣨���õ�ǰ�ĸ��ڵ��ջ����Ȼ�� top--��
            root = root->rchild; // Ȼ����ʵ�ǰ���ڵ��������
        }
    }
    return count;
    
}

// 4��������
int main(void)
{
    btree root = NULL; // ԭʼ����������
    btree temp = NULL; // ����,����������
    int depth = 0;
    /*�ݹ鴴��������*/
    root = createBitree();
    printf("Ҷ�ӽ������=%d\n",LeadCount(root));
    printf("Ҷ�ӽ������=%d", LeadCount2(root));
    return 0;
}

