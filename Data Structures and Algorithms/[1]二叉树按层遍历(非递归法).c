/*
 * @Author: jjk 
 * @Date: 2019-08-11 21:33:09 
 * @Last Modified by: jjk
 * @Last Modified time: 2019-08-12 13:56:00
 * �����ܣ�������ʶ�����(�ǵݹ�)
 */

/**
 * �ö��д洢������Ů�ĵ�ַ�����Ӷ����ó�һ���ڵ�ʱ��������ڵ��������Ů�ĵ�ַҲ���뵽������
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1�������������ṹ
typedef struct binode
{
    char data;                   // �洢�ڵ��ֵ
    struct binode *left, *right; // �����������ҽڵ��ָ��

} BiTree; // �ṹ�������

// 2������������
BiTree *CreateBiTree(int a[], int n)
{
    BiTree *root;       // �������������ڵ�
    BiTree *pa, *c, *p; // �����������ṹ��ָ�����
    // ����
    // struct binode = *pa, *c, *p;
    // BiTree = &pa,&c,&p;

    root = (BiTree *)malloc(sizeof(BiTree)); // ��̬�����ڴ�
    root->data = a[0];                       // ���ڵ�ָ���һ��Ԫ��
    root->left = NULL;
    root->left = NULL; // ����������ʼ��

    // printf("ceshi");
    int i;
    for (i= 1; i < n; i++) // �ӵ�һ��Ԫ�ؿ�ʼ����
    {
        /* code */
        p = (BiTree *)malloc(sizeof(BiTree)); // ��̬�ڴ����
        p->data = a[i];                       // ��ȡÿһ��Ԫ��
        p->right = p->left = NULL;
        c = root;                             // ���ڵ�
        while (c)
        {
            /* code */
            pa = c;
            if (c->data > p->data) // ���ڵ�Ԫ��>����Ԫ��
            {
                /* code */
                c = c->left;
            }
            else
            {
                c = c->right;
            }
        }

        if (pa->data > p->data)
        {
            /* code */
            pa->left = p;
        }
        else
        {
            pa->right = p;
        }
    }
    return root; // ���ظ��ڵ�
}

// 3���������������
void Level_order(BiTree *root, int n)
{

    BiTree **Q;      // ����ָ��
    BiTree *p;       // �������ṹ��ָ�����
    int front, rear; // ��βָ�룬����ָ��
    front = rear = -1;
    Q = (BiTree **)malloc((n + 1)*sizeof(BiTree *)); // �������пռ�
    Q[++rear] = root;                                  // ��������ȴ洢������

    //������Ϊ�յ�ʱ�����������
    while (front != rear)
    {
        p = Q[++front];
        printf("%d\t", p->data);
        //��������Ů�ĵ�ַ�������
        if (p->left)
        {
            Q[++rear] = p->left;
        }
        if (p->right)
        {
            Q[++rear] = p->right;
        }
    }
    free(Q);
}

// 4��������
int main(void)
{
    /* code */
    // struct binode *root;  /*����������ṹ������ָ��*/
    // BiTree = &root; /*ָ��ָ��ṹ�����*/

    BiTree *root; // �����������ṹ�壬ָ�����
    int data[] = {3, 2, 5, 8, 4, 7, 6, 9, 0, 1};
    int length =sizeof(data)/sizeof(int);
    // �������������
    root = CreateBiTree(data, length);
    // �������
    Level_order(root, length);
    return 0;
}
