/*
 * @Author: jjk 
 * @Date: 2019-08-11 21:33:09 
 * @Last Modified by: jjk
 * @Last Modified time: 2019-08-14 14:32:44
 * 程序功能：复制二叉树(递归)
 * coding:gbk
 * 输入形式：AB#C##D##
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*树-双亲结构*/
typedef char TElemTpe;
#define MAX_TREE_SIZE 100

typedef struct ptnode{
    TElemTpe data;
    int parent; // 双亲位置域
}PTNode;


/*树结构*/
typedef struct{
    PTNode node[MAX_TREE_SIZE];
    int r,n; // 根结点的位置和结点个数
}PTree;


/*树-孩子表示法*/
typedef struct CTNode
{                        // 孩子结点
    int child;           // 孩子结点的下标
    struct CTNode *next; // 指向下一结点的指针
}*ChildPtr;
typedef struct /*表头结构*/
{                       
    ElemeType data;      // 存放在数中的结点数据
    ChildPtr firstchild; // 指向第一个孩子的指针
} CTBox;
typedef struct /*树结构*/
{                               
    CTBox nodes[MAX_TREE_SIZE]; // 结点数组
    int r;                      // 根的位置
    int n;                      // 结点树
} CTree;



/*树-双亲孩子表示法*/
/* 树的双亲孩子表示法结构定义*/
typedef struct CTNode
{                        // 孩子结点
    int child;           // 孩子结点的下标
    struct CTNode *next; // 指向下一结点的指针
} * ChildPtr;

typedef struct
{                        // 表头结构
    ElemeType data;      // 存放在数中的结点数据
    int parent;          // 存放双亲的下标
    ChildPtr firstchild; // 指向第一个孩子的指针
} CTBox;

typedef struct
{                               // 树结构
    CTBox nodes[MAX_TREE_SIZE]; // 结点数组
    int r;                      // 根的位置
    int n;                      // 结点树
} CTree;

/* 树-孩子兄弟表示法结构定义*/
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
//     BiThrTree root = NULL; // 原始二叉树树根
//     BiThrTree temp = NULL; // 复制,二叉树树根
//     int depth = 0;

//     /*递归创建二叉树*/
//     printf("请输入前序二叉树的内容:\n");
//     createTree(root); // 建立二叉树
//     InOrderThread_Head(temp,root);
//     printf("输出中序二叉树的内容:\n");
//     InOrderThraverse_Thr(temp);

//     return 0;
// }
