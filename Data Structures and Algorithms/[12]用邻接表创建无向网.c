/*
 * @Author: jjk 
 * @Date: 2019-08-12 11:23:53 
 * @Last Modified by: jjk
 * @Last Modified time: 2019-08-12 21:32:48
 * �����ܣ�����������(�ݹ�˼�룺ǰ�����򣬺���)
 * coding:gbk
 * ���뷽ʽ��AB#C##D##
 * ˵����û�нڵ���ԡ�#������
 */

#include <stdio.h>
#include <stdlib.h>

/*3���ڽӱ�ṹ*/
typedef char VertexType; /* �������Ͷ���*/
typedef int EdgeType;    /* ���ϵ�Ȩֵ����*/
#define MAXVEX 100       /*��󶥵���*/

typedef struct EdgeNode /* �߱���*/
{
    int adjvex;            /*�ڽӵ��򣬴洢�ö����Ӧ���±�*/
    EdgeType weigth;       /*���ڴ洢Ȩֵ�����ڷ���ͼ���Բ���Ҫ*/
    struct EdgeNode *next; /* ����ָ����һ���ڽӵ�*/
} EdgeNode;

typedef struct VertexNode /* ������� */
{
    VertexType data;     /* �����򣬴洢������Ϣ*/
    EdgeNode *firstedge; /* �߱�ͷָ��*/
} VertexNode, AdjList[MAXVEX];

typedef struct
{
    AdjList adjList;
    int numVertexes, numEdges; /*ͼ�е�ǰ�������ͱ���*/
} GraphAdjList;

/*����ͼ����ӱ���*/
// 4������ͼ����ӱ�ṹ*/
void CreateALGraph(GraphAdjList *G)
{
    int i, j, k;
    EdgeNode *e;
    printf("���붥�����ͱ���:\n");
    scanf("%d %d", &G->numVertexes, &G->numEdges); /*���붥�����ͱ���*/
    setbuf(stdin, NULL);                           //�������뻺���� Ϊ�ջ�����
    for (i = 0; i < G->numVertexes; i++)           /*��ȡ������Ϣ�����������*/
    {
        printf("\n�������%d������洢��ֵ:", i);
        scanf("%c", &G->adjList[i].data); /*���붥����Ϣ*/
        setbuf(stdin, NULL);              //�������뻺���� Ϊ�ջ�����
        G->adjList[i].firstedge = NULL;   /*���߱���Ϊ�ձ�*/
    }

    for (k = 0; k < G->numVertexes; k++) /*�����߱�*/
    {
        printf("�����(Vi,Vj)�ϵĶ�����ţ�");
        scanf("%d %d",&i,&j);                   /*�����(Vi,Vj)�ϵĶ������*/
        e = (EdgeNode *)malloc(sizeof(EdgeNode)); /*���ڴ�����ռ䣬���ɱ߱���*/
        e->adjvex = j;                            /*�ڽ����Ϊj*/
        e->next = G->adjList[i].firstedge = e;    /*��eָ��ָ��ǰ����ָ��Ľ��*/
        G->adjList[i].firstedge = e;              /*����ǰ�����ָ��ָ��e*/

        e = (EdgeNode *)malloc(sizeof(EdgeNode)); /*���ڴ�����ռ䣬���ɱ߱���*/
        e->adjvex = i;                            /*�ڽ����i*/
        e->next = G->adjList[i].firstedge;        /*��eָ��ָ��ǰ����ָ��Ľ��*/
        G->adjList[j].firstedge = e;              /*����ǰ�����ָ��ָ��e*/
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    GraphAdjList GL;
    CreateALGraph(&GL);
    return 0;
}
