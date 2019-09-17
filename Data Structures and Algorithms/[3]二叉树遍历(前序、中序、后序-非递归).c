/*
 * Description:
 *           ��������������ز���������������ڵ㣬ǰ���С�����ݹ�ͷǵݹ������������
 * Author  :FinL
 * Language: C
 * Date    : 2010-08-29
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node /*�������ṹ��*/
{
    int data;
    struct node *leftchild;
    struct node *rightchild;
} Node;

/*
 ��ʼ��һ�ö�������������
*/
void InitBinaryTree(Node **root, int elem)
{
   
    *root = (Node *)malloc(sizeof(Node));
    if (!(*root))
    {
        printf("Memory allocation for root failed.\n");
        return;
    }
    (*root)->data = elem; 
    (*root)->leftchild = NULL;
    (*root)->rightchild = NULL;
}

/*
 ��������������в����㡣
*/
void InsertNode(Node *root, int elem)
{
    Node *newnode = NULL;
    Node *p = root, *last_p = NULL;

    newnode = (Node *)malloc(sizeof(Node));
    if (!newnode)
    {
        printf("Memory allocation for newnode failed.\n");
        return;
    }
    newnode->data = elem;
    newnode->leftchild = NULL;
    newnode->rightchild = NULL;

    while (NULL != p)
    {
        last_p = p;
        if (newnode->data < p->data)
        {
            p = p->leftchild;
        }
        else if (newnode->data > p->data)
        {
            p = p->rightchild;
        }
        else
        {
            printf("Node to be inserted has existed.\n");
            free(newnode);
            return;
        }
    }
    p = last_p;
    if (newnode->data < p->data)
    {
        p->leftchild = newnode;
    }
    else
    {
        p->rightchild = newnode;
    }
}

/*
 ����һ�ö�������������
*/
void CreatBinarySearchTree(Node **root, int data[], int num)
{
    int i;

    for (i = 0; i < num; i++)
    {
        if (NULL == *root)
        {
            InitBinaryTree(root, data[i]);
        }
        else
        {
            InsertNode(*root, data[i]);
        }
    }
}

/*
 ǰ��������������ݹ鷽����
*/
void PreOrderRec(Node *root)
{
    if (NULL != root)
    {
        printf("%d  ", root->data);
        PreOrderRec(root->leftchild);
        PreOrderRec(root->rightchild);
    }
}

/*
 ǰ��������������ǵݹ鷽����
*/
void PreOrderNoRec(Node *root)
{
    Node *p = root;
    Node *stack[30];
    int num = 0;
    while (NULL != p || num > 0)
    {
        while (NULL != p)
        {
            printf("%d  ", p->data);
            stack[num++] = p;
            p = p->leftchild;
        }
        num--;
        p = stack[num];
        p = p->rightchild;
    }
    printf("\n");
    
}

/*
 ����������������ݹ鷽����
*/
void InOrderRec(Node *root)
{
    if (NULL != root)
    {
        InOrderRec(root->leftchild);
        printf("%d  ", root->data);
        InOrderRec(root->rightchild);
    }
}

/*
 ����������������ǵݹ鷽����ʹ��ջ��
*/
void InOrderNoRec(Node *root)
{
    Node *p = root;
    int num = 0;
    Node *stack[30];
    while (NULL != p || num > 0)
    {
        while (NULL != p)
        {
            stack[num++] = p;
            p = p->leftchild;
        }
        num--;
        p = stack[num];
        printf("%d  ", p->data);
        p = p->rightchild;
    }
    printf("\n");
}

/*
 ����������������ݹ鷽����
*/
void PostOrderRec(Node *root)
{
    if (NULL != root)
    {
        PostOrderRec(root->leftchild);
        PostOrderRec(root->rightchild);
        printf("%d  ", root->data);
    }
}

/*
 ����������������ǵݹ鷽����
*/
void PostOrderNoRec(Node *root)
{
    Node *p = root;
    Node *stack[30];
    int num = 0;
    Node *have_visited = NULL;

    while (NULL != p || num > 0)
    {
        while (NULL != p)
        {
            stack[num++] = p;
            p = p->leftchild;
        }
        p = stack[num - 1];
        if (NULL == p->rightchild || have_visited == p->rightchild)
        {
            printf("%d  ", p->data);
            num--;
            have_visited = p;
            p = NULL;
        }
        else
        {
            p = p->rightchild;
        }
    }
    printf("\n");
}


int main()
{
    Node *root = NULL;
    int num = 0;
    int data[] = {5, 2, 4, 0, 0, 5, 0, 0, 3, 6, 8, 0, 10, 0, 7, 0, 9};
    num = sizeof(data) / sizeof(int);

    CreatBinarySearchTree(&root, data, num);

    printf("ǰ������ݹ���ǵݹ�.\n");
    PreOrderRec(root);
    printf("\n");
    PreOrderNoRec(root);

    printf("\n��������ݹ���ǵݹ�.\n");
    InOrderNoRec(root);
    InOrderRec(root);
    

    printf("\n��������ݹ���ǵݹ�\n");
    PostOrderNoRec(root);
    PostOrderRec(root);
   
    return 0;
    }