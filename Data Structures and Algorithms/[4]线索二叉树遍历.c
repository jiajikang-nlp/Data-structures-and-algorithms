/*
 * @Author: jjk 
 * @Date: 2019-08-13 13:29:41 
 * @Last Modified by: jjk
 * @Last Modified time: 2019-08-13 14:20:35
 * 程序功能：遍历线索二叉树
 */


#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    Link,
    Thread
} PointerTag; /*Link==0表示指向左右孩子指针，Thread==1表示指向前驱或后继的线索*/


typedef struct BiThrNode
{ /*二叉树存储结点结构*/

    char data;                         // 结点数据
    struct BiThrNode *lchild, *rchild; // 左右孩子指针
    int LTag;
    int RTag; // 左右标志
} BiThrNode, *BiThrTree;

BiThrTree pre; /*二叉树结构体全局变量，始终指向刚刚访问过的节点*/

/*中序遍历进行中序线索化*/
void InThreading(BiThrTree p)
{ /*二叉树结构体指针变量*/

    if (p)
    {
        /* code */
        InThreading(p->lchild); /*递归左子树线索化*/
        // 如果某节点的左指针域为空，因为其前驱节点刚刚访问过，赋值给了pre，所以可以将pre赋值给p->lchild,
        // 并修改p->LTag = Thread(也就是定义为1) 以完成前驱节点的线索化
        if (!p->lchild) /*没有左孩子*/
        {

            p->LTag = Thread; // 前驱线索
            p->lchild = pre;  // 左孩子指针指向前驱
        }
        // p节点的后继还没有访问到，因此只能对他的前驱节点pre的右指针rchild做判断，
        if (!pre->rchild) /*表示为空：前驱没有右孩子*/
        {

            pre->RTag = Thread; // 后序线索
            pre->rchild = p;    //p就是pre的后继：前驱右孩子指针指向后继(当前节点p)
        }

        pre = p;                // 完成前驱和后继的判断后，当前的节点p赋值给pre，，以便下一次使用：保持pre指向p的前驱
        InThreading(p->rchild); /*递归右子树线索化*/
    }
}

/*遍历线索二叉树-操作一个双向链表*/
/*和双向链表结构一样，在二叉树线索链表上添加一个头结点，令其lchild域的指针指向二叉树的根节点，其rchild域的指针指向
中序遍历时访问的最后一个节点。反之，领二叉树的中序序列中的第一个节点中，lchild域指针和最后一个结点的rchild域指针均
指向头结点.这样定义的好处就是我们既可以从第一个结点其顺后继继续遍历，也可以从最后一个节点起顺前驱进行遍历。
*/
/*T指向头结点，头结点左链lchild指向根节点，头结点右链rchild指向中序遍历的*/
/*最后一个节点。中序遍历二叉线索链表示的一个二叉树T*/
int InOrderTraverse_Thr(BiThrTree T)
{

    BiThrTree p;   // 指针p
    p = T->lchild; /*P指向根节点*/
    while (p != T) /*空树或遍历结束，p==T*/
    {

        while (p->LTag == Link) /*当LTag==0时循环到中序序列第一个节点*/
            p = p->lchild;
        printf("%c", p->data); /*显示结点数据，可以更改为其他对结点操作*/
        while (p->RTag == Thread && p->rchild != T) /*由于节点H的RTag==1且不是指向头结点*/
        {
            /* code */
            p = p->rchild;/*因此打印H的后继D,之后因为D的RTag是Link，因此退出循环*/
            printf("%c", p->data);
        }
        p = p->rchild; /*p进至其右子树根：p指向了节点D的有孩子I*/
    }
    return 0;
}