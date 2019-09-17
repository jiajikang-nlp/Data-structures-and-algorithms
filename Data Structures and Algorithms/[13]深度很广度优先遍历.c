/*
 * @Author: jjk
 * @Date: 2019-08-13 13:29:41
 * @Last Modified by: jjk
 * @Last Modified time: 2019-08-14 14:13:20
 * 程序功能：
 * coding：gbk
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*邻接表结构*/
typedef char VertexType; /*顶点类型定义*/
typedef int EdgeType;    /*边上权值类型定义*/
#define MAXVEX 100       /*最大顶点数*/
#define INFINITY 65535   /*用65535来代表∞*/
#define TRUE 1
#define FALSE 0
typedef int Boole; // 布尔类型 存储TRUE FALSE
Boole visited[MAXVEX]; // 设置标志数组

/* 边表结点*/
typedef struct EdgeNode
{
    int adjvex;            /*邻接点域，存储该顶点对应的下标*/
    EdgeType weigth;       /*用于存储权值，对于非网图可以不需要*/
    struct EdgeNode *next; /* 链域，指向下一个邻接点*/
} EdgeNode;

typedef struct VertexNode /* 顶点表结点 */
{
    VertexType data;     /* 顶点域，存储顶点信息*/
    EdgeNode *firstedge; /* 边表头指针*/
} VertexNode, AdjList[MAXVEX];

typedef struct
{
    AdjList adjList;
    int numVertexes, numEdges; /*图中当前顶点数和边数*/
} GraphAdjList, *GraphAdj;

/*定义循环队列结构体*/
typedef struct LoopQueue
{ 
    int data[MAXVEX];
    int front;
    int rear; //注意每次队尾标记指向最后一个元素的下一个位置
} Queue, *LQueue;

/*初始化队列*/
void InitQueue(LQueue Q) 
{
    Q->front = Q->rear = 0;
}

/*判断队列是否满了*/
bool QueueisFull(LQueue Q)
{
    if ((Q->rear + 1) % MAXVEX == Q->front)
    {
        return true; //已满
    }
    else
    {
        return false;
    }
}

/*判断队列是否为空*/
bool QueueisEmpty(LQueue Q){
    if (Q->front == Q->rear)
    {
        /* code */
        return true;
    }
    return false;
}

/*入队列*/
void EnQueue(LQueue Q, int i)
{ 
    if (!QueueisFull(Q))
    {
        Q->data[Q->rear] = i;
        Q->rear = (Q->rear + 1) % MAXVEX; //队尾指针后移
    }
}
/*出队列*/
void DeQueue(LQueue Q, int *k)
{ 
    if (!QueueisEmpty(Q))
    {
        *k = Q->data[Q->front];
        Q->front = (Q->front + 1) % MAXVEX;
    }
}

/*邻接表创建*/
void create(GraphAdj G)
{
    int i, j, k;
    EdgeNode *e;
    printf("输入顶点数,边数：");
    scanf("%d%d", &G->numVertexes, &G->numEdges);
    setbuf(stdin, NULL);                 // 清楚缓冲
    for (i = 0; i < G->numVertexes; i++) //建立顶点表
    {
        scanf("%c", &G->adjList[i].data);
        G->adjList[i].firstedge = NULL; //注意将边表置空
    }
    for (k = 0; k < G->numEdges; k++) //建立边表
    {
        printf("输入边(Vi,Vj)上的顶点序号：");
        scanf("%d%d", &i, &j); /*输入边(Vi,Vj)上的顶点序号*/
        /*使用头插法加入边表结点*/
        e = (EdgeNode *)malloc(sizeof(EdgeNode)); //向内存申请空间，生成边表结点

        e->adjvex = j;                     /*邻接序号j*/
        e->next = G->adjList[i].firstedge; /*将e指针指向当前顶点指向的结点*/
        G->adjList[i].firstedge = e;       /* 将当前顶点的指针指向e */

        e = (EdgeNode *)malloc(sizeof(EdgeNode)); //向内存申请空间，生成边表结点

        e->adjvex = i;                     /* 邻接序号为i */
        e->next = G->adjList[j].firstedge; /*将e指针指向当前顶点指向的结点*/
        G->adjList[j].firstedge = e;       /* 将当前顶点的指针指向e*/
    }
}


// 邻接表的深度优先遍历同邻接矩阵的深度优先遍历大同小异，都需要创建一个标志数组，数组存放bool类型成员TRUE，FALSE。
// 其中TRUE表示已经访问过。 不同点：在递归函数中需要声明一个EdgeNode
// *类型的变量p来进行边表的遍历，也就是在边表的链表中遍历邻接点。

/*邻接表的深度优先递归算法*/
/*邻接表的深度优先递归*/
void DFS(GraphAdj G, int i)
{
    EdgeNode *p;
    visited[i] = TRUE; //访问过了该顶点，标记为TRUE
    printf("%c", G->adjList[i].data);
    p = G->adjList[i].firstedge; //让p指向边表第一个结点
    while (p)                    //在边表内遍历
    {
        if (!visited[p->adjvex]) //对未访问的邻接顶点递归调用
            DFS(G, p->adjvex);
        p = p->next;
    }
}

//邻接表的深度遍历操作
void DFSTraverse(GraphAdj G)
{
    int i;
    for (i = 0; i < G->numVertexes; i++)
        visited[i] = FALSE; //初始设置为未访问?
    for (i = 0; i < G->numVertexes; i++)
        if (!visited[i])
            DFS(G, i); //对未访问的顶点调用DFS，若是连通图只会执行一次?
}

/*广度优先遍历*/
void BFS(GraphAdj G)
{

    Queue *Q = (LQueue)malloc(sizeof(Queue));
    for (int i = 0; i < G->numVertexes; i++)
    {
        visited[i] = FALSE;
    }
    InitQueue(Q); //初始化队列
    for (int i = 0; i < G->numVertexes; i++)
    {
        visited[i] = TRUE;
        printf("\t%c", G->adjList[i].data);
        EnQueue(Q, i);

        while (!QueueisEmpty(Q))
        {
            DeQueue(Q, &i);                        //这里不断的修改i的值！！
            EdgeNode *e = G->adjList[i].firstedge; // i顶点的邻接链表的第一个结点
            while (e)
            { // e存在时，将e的所有邻接点加入队列,也就是遍历i的所有邻接点
                if (!visited[e->adjvex])
                { // adjvex是e所表示的结点下标
                    visited[e->adjvex] = TRUE;
                    printf("\t%c", G->adjList[e->adjvex].data);
                    EnQueue(Q, e->adjvex); //将该结点入队
                }
                e = e->next; //遍历i的下一个邻接点
            }
        }
    }
}

int main(int argc, char **argv)
{
    GraphAdj G;
    create(G);
    printf("\n");
    DFSTraverse(G);
    printf("\n图遍历完毕");
    system("pause");
    return 0;
}