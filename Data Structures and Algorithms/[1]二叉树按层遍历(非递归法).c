/*
 * @Author: jjk 
 * @Date: 2019-08-11 21:33:09 
 * @Last Modified by: jjk
 * @Last Modified time: 2019-08-12 13:56:00
 * 程序功能：按层访问二叉树(非递归)
 */

/**
 * 用队列存储左右子女的地址，当从队列拿出一个节点时，将这个节点的左右子女的地址也放入到队列中
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1、创建二叉树结构
typedef struct binode
{
    char data;                   // 存储节点的值
    struct binode *left, *right; // 二叉树的左右节点的指针

} BiTree; // 结构体变量名

// 2、建立二叉树
BiTree *CreateBiTree(int a[], int n)
{
    BiTree *root;       // 创建二叉树根节点
    BiTree *pa, *c, *p; // 创建二叉树结构体指针变量
    // 或者
    // struct binode = *pa, *c, *p;
    // BiTree = &pa,&c,&p;

    root = (BiTree *)malloc(sizeof(BiTree)); // 动态分配内存
    root->data = a[0];                       // 根节点指向第一个元素
    root->left = NULL;
    root->left = NULL; // 左右子树初始化

    // printf("ceshi");
    int i;
    for (i= 1; i < n; i++) // 从第一个元素开始遍历
    {
        /* code */
        p = (BiTree *)malloc(sizeof(BiTree)); // 动态内存分配
        p->data = a[i];                       // 获取每一个元素
        p->right = p->left = NULL;
        c = root;                             // 根节点
        while (c)
        {
            /* code */
            pa = c;
            if (c->data > p->data) // 根节点元素>其他元素
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
    return root; // 返回根节点
}

// 3、按层遍历二叉树
void Level_order(BiTree *root, int n)
{

    BiTree **Q;      // 队列指针
    BiTree *p;       // 二叉树结构体指针变量
    int front, rear; // 队尾指针，队首指针
    front = rear = -1;
    Q = (BiTree **)malloc((n + 1)*sizeof(BiTree *)); // 申明队列空间
    Q[++rear] = root;                                  // 根结对首先存储到队列

    //当队列为空的时候，则遍历结束
    while (front != rear)
    {
        p = Q[++front];
        printf("%d\t", p->data);
        //将左右子女的地址存入队列
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

// 4、主函数
int main(void)
{
    /* code */
    // struct binode *root;  /*定义二叉树结构体类型指针*/
    // BiTree = &root; /*指针指向结构体变量*/

    BiTree *root; // 创建二叉树结构体，指针变量
    int data[] = {3, 2, 5, 8, 4, 7, 6, 9, 0, 1};
    int length =sizeof(data)/sizeof(int);
    // 创建二叉查找树
    root = CreateBiTree(data, length);
    // 按层变量
    Level_order(root, length);
    return 0;
}
