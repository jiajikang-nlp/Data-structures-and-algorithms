/*
 * @Author: jjk 
 * @Date: 2019-08-11 21:33:09 
 * @Last Modified by: jjk
 * @Last Modified time: 2019-08-14 14:32:44
 * �����ܣ����ƶ�����(�ݹ�)
 * coding:gbk
 * ������ʽ��AB#C##D##
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*��-˫�׽ṹ*/
typedef char TElemTpe;
#define MAX_TREE_SIZE 100

typedef struct ptnode{
    TElemTpe data;
    int parent; // ˫��λ����
}PTNode;


/*���ṹ*/
typedef struct{
    PTNode node[MAX_TREE_SIZE];
    int r,n; // ������λ�úͽ�����
}PTree;


/*��-���ӱ�ʾ��*/
typedef struct CTNode
{                        // ���ӽ��
    int child;           // ���ӽ����±�
    struct CTNode *next; // ָ����һ����ָ��
}*ChildPtr;
typedef struct /*��ͷ�ṹ*/
{                       
    ElemeType data;      // ��������еĽ������
    ChildPtr firstchild; // ָ���һ�����ӵ�ָ��
} CTBox;
typedef struct /*���ṹ*/
{                               
    CTBox nodes[MAX_TREE_SIZE]; // �������
    int r;                      // ����λ��
    int n;                      // �����
} CTree;



/*��-˫�׺��ӱ�ʾ��*/
/* ����˫�׺��ӱ�ʾ���ṹ����*/
typedef struct CTNode
{                        // ���ӽ��
    int child;           // ���ӽ����±�
    struct CTNode *next; // ָ����һ����ָ��
} * ChildPtr;

typedef struct
{                        // ��ͷ�ṹ
    ElemeType data;      // ��������еĽ������
    int parent;          // ���˫�׵��±�
    ChildPtr firstchild; // ָ���һ�����ӵ�ָ��
} CTBox;

typedef struct
{                               // ���ṹ
    CTBox nodes[MAX_TREE_SIZE]; // �������
    int r;                      // ����λ��
    int n;                      // �����
} CTree;

/* ��-�����ֵܱ�ʾ���ṹ����*/
#define MAX_TREE_SIZE 100
typedef int ElemeType;

typedef struct CSNode
{
    ElemeType data;
    struct CSNode *firstchild;
    struct CSNode *rightsib;

} CSNode, *CSTree;






// int main(void)
// {
//     BiThrTree root = NULL; // ԭʼ����������
//     BiThrTree temp = NULL; // ����,����������
//     int depth = 0;

//     /*�ݹ鴴��������*/
//     printf("������ǰ�������������:\n");
//     createTree(root); // ����������
//     InOrderThread_Head(temp,root);
//     printf("������������������:\n");
//     InOrderThraverse_Thr(temp);

//     return 0;
// }
