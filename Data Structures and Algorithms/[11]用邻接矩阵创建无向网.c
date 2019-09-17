/*
 * @Author: jjk 
 * @Date: 2019-08-13 13:29:41 
 * @Last Modified by: jjk
 * @Last Modified time: 2019-08-14 14:13:20
 * 程序功能： 处理训练规则模板
 * coding：gbk
 */

#include <stdio.h>
#include <stdlib.h>

typedef char VertexType; /*顶点类型定义*/
typedef int EdgeType;    /*边上权值类型定义*/
#define MAXVEX 100       /*最大顶点数*/
#define INFINITY 65535   /*用65535来代表∞*/

/*1、图结构*/
typedef struct
{

    VertexType vexs[MAXVEX];      /*顶点表：一维数组*/
    EdgeType arc[MAXVEX][MAXVEX]; /*领接矩阵，可看作边表：二维数组*/
    int numVertexes, numEdges;    /*图中当前的顶点和边数*/

} MGraph;                         /*图结构变量*/
/*有了以上的结构定义，构造一个图，其实就是给顶点表和边表输入数据的过程*/
/*2、建立无向网图的领接矩阵*/
/*n个顶点和e条边的无向网图的创建，时间复杂度为O(n+n*n+e),其中对邻接矩阵Garc的初始化耗费了O(n*n)的时间*/

void CreateMGraph(MGraph *G){
    int i,j,k,w;
    printf("请输入顶点数和边数:\n");
    scanf("%d %d",&G->numVertexes,&G->numEdges);/*输入顶点数和边数*/
    setbuf(stdin, NULL);//设置输入缓冲区 为空缓冲区（每次输入一个回车，这里会造成 \n字符存在缓冲区）
    for (i = 0; i < G->numVertexes; i++) /*遍历顶点数，读取顶点信息，建立顶点表*/
    {
        /* code */
        printf("\n请输入第%d个顶点存储的值:",i);
        scanf("%c",&G->vexs[i]);
        setbuf(stdin, NULL);
    }

    for (i = 0; i < G->numVertexes; i++)
    {
        for (j = 0; j < G->numVertexes; j++)
        {
            G->arc[i][j] = INFINITY; /*邻接矩阵初始化*/
        }
        
    }

    for (k = 0; k < G->numEdges; k++)/*读入numEdges条边，建立领接矩阵*/
    {
        /* code */
        printf("输入(Vi,Vj)上的下标i，下标j和权w:");
        scanf("%d %d %d",&i,&j,&w);/*输入边(Vi,Vj)上的权w*/
        G->arc[i][j] = w;
        G->arc[j][i] = G->arc[i][j]; /*因为是无向图，矩阵对称*/

    }
}

int main(int argc, char **argv)
{
    MGraph MG;
    CreateMGraph(&MG);
    system("pause");
    return 0;
}