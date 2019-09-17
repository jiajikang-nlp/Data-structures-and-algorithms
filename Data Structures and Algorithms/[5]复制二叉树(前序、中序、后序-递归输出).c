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
typedef struct bitnode{ 
    TelemType data;
    struct bitnode *lchild, *rchild; 
}TreeNode, *btree;


/*�ݹ鴴��������*/
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
        
        /*�ڴ����*/
        pstNextNode = (TreeNode *)malloc(sizeof(TreeNode));
        /*�����½ڵ�����*/
        pstNextNode ->data = ch;
        /*�ݹ���ò���������*/
        pstNextNode ->lchild = createBitree();
        pstNextNode ->rchild = createBitree();
    }
    return pstNextNode;
}

/*���ƶ�����*/
btree Copy(btree root){
    btree newroot;
    if (root == NULL)
    {
        /* code */
        return NULL;

    }else
    {
        newroot = (btree)malloc(sizeof(TreeNode)); //�ڴ����
        newroot ->data = root->data;   /*���ƽڵ�����*/
        newroot->lchild =  Copy(root->lchild); /*����������*/
        newroot->rchild =  Copy(root->rchild); /*����������*/
    }
    return newroot;
}


/*������ǰ�����*/
void pre_order(btree ptr){
    if (ptr)
    {
        /* code */
        printf("%2c",ptr->data);
        pre_order(ptr->lchild);
        pre_order(ptr->rchild);
    }
}

/*�������������*/
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

/*�������������*/
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



// 4��������
int main(void)
{
    btree root = NULL; // ԭʼ����������
    btree temp = NULL; // ���ƶ���������
    /*�ݹ鴴��������*/
    root = createBitree();
    printf("\n----------ԭ������ǰ�����----------\n");
    pre_order(root);

    printf("\n----------ԭ�������������----------\n");
    in_order(root);

    printf("\n----------ԭ�������������----------\n");
    pos_order(root);



    printf("\n--------���Ƹö���������ӡ----------\n\n");
    printf("\n--------���ƵĶ�����ǰ�����----------\n");
    temp = Copy(root);
    pre_order(temp);

    printf("\n--------���ƵĶ������������----------\n");
    temp = Copy(root);
    in_order(temp);

    printf("\n--------���ƵĶ������������----------\n");
    temp = Copy(root);
    pos_order(temp);

    return 0;
}
