/*
 * @Author: jjk 
 * @Date: 2019-08-12 11:23:53 
 * @Last Modified by: jjk
 * @Last Modified time: 2019-08-12 21:32:48
 * 程序功能：遍历二叉树(递归思想：前序，中序，后序)
 * coding:gbk
 * 输入方式：AB#C##D##
 * 说明：没有节点的以‘#’代替
 */

#include <stdio.h>
#include <stdlib.h>

/*3、邻接表结构*/
typedef char VertexType; /* 顶点类型定义*/
typedef int EdgeType;    /* 边上的权值类型*/
#define MAXVEX 100       /*最大顶点数*/

typedef struct EdgeNode /* 边表结点*/
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
} GraphAdjList;

/*无向图的领接表创建*/
// 4、建立图的领接表结构*/
void CreateALGraph(GraphAdjList *G)
{
    int i, j, k;
    EdgeNode *e;
    printf("输入顶点数和边数:\n");
    scanf("%d %d", &G->numVertexes, &G->numEdges); /*输入顶点数和边数*/
    setbuf(stdin, NULL);                           //设置输入缓冲区 为空缓冲区
    for (i = 0; i < G->numVertexes; i++)           /*读取顶点信息，建立顶点表*/
    {
        printf("\n请输入第%d个顶点存储的值:", i);
        scanf("%c", &G->adjList[i].data); /*输入顶点信息*/
        setbuf(stdin, NULL);              //设置输入缓冲区 为空缓冲区
        G->adjList[i].firstedge = NULL;   /*将边表置为空表*/
    }

    for (k = 0; k < G->numVertexes; k++) /*建立边表*/
    {
        printf("输入边(Vi,Vj)上的顶点序号：");
        scanf("%d %d",&i,&j);                   /*输入边(Vi,Vj)上的顶点序号*/
        e = (EdgeNode *)malloc(sizeof(EdgeNode)); /*向内存申请空间，生成边表结点*/
        e->adjvex = j;                            /*邻接序号为j*/
        e->next = G->adjList[i].firstedge = e;    /*将e指针指向当前顶点指向的结点*/
        G->adjList[i].firstedge = e;              /*将当前顶点的指针指向e*/

        e = (EdgeNode *)malloc(sizeof(EdgeNode)); /*向内存申请空间，生成边表结点*/
        e->adjvex = i;                            /*邻接序号i*/
        e->next = G->adjList[i].firstedge;        /*将e指针指向当前顶点指向的结点*/
        G->adjList[j].firstedge = e;              /*将当前顶点的指针指向e*/
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    GraphAdjList GL;
    CreateALGraph(&GL);
    return 0;
}
