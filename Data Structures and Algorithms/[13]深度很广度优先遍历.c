/*
 * @Author: jjk
 * @Date: 2019-08-13 13:29:41
 * @Last Modified by: jjk
 * @Last Modified time: 2019-08-14 14:13:20
 * �����ܣ�
 * coding��gbk
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*�ڽӱ�ṹ*/
typedef char VertexType; /*�������Ͷ���*/
typedef int EdgeType;    /*����Ȩֵ���Ͷ���*/
#define MAXVEX 100       /*��󶥵���*/
#define INFINITY 65535   /*��65535�������*/
#define TRUE 1
#define FALSE 0
typedef int Boole; // �������� �洢TRUE FALSE
Boole visited[MAXVEX]; // ���ñ�־����

/* �߱���*/
typedef struct EdgeNode
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
} GraphAdjList, *GraphAdj;

/*����ѭ�����нṹ��*/
typedef struct LoopQueue
{ 
    int data[MAXVEX];
    int front;
    int rear; //ע��ÿ�ζ�β���ָ�����һ��Ԫ�ص���һ��λ��
} Queue, *LQueue;

/*��ʼ������*/
void InitQueue(LQueue Q) 
{
    Q->front = Q->rear = 0;
}

/*�ж϶����Ƿ�����*/
bool QueueisFull(LQueue Q)
{
    if ((Q->rear + 1) % MAXVEX == Q->front)
    {
        return true; //����
    }
    else
    {
        return false;
    }
}

/*�ж϶����Ƿ�Ϊ��*/
bool QueueisEmpty(LQueue Q){
    if (Q->front == Q->rear)
    {
        /* code */
        return true;
    }
    return false;
}

/*�����*/
void EnQueue(LQueue Q, int i)
{ 
    if (!QueueisFull(Q))
    {
        Q->data[Q->rear] = i;
        Q->rear = (Q->rear + 1) % MAXVEX; //��βָ�����
    }
}
/*������*/
void DeQueue(LQueue Q, int *k)
{ 
    if (!QueueisEmpty(Q))
    {
        *k = Q->data[Q->front];
        Q->front = (Q->front + 1) % MAXVEX;
    }
}

/*�ڽӱ���*/
void create(GraphAdj G)
{
    int i, j, k;
    EdgeNode *e;
    printf("���붥����,������");
    scanf("%d%d", &G->numVertexes, &G->numEdges);
    setbuf(stdin, NULL);                 // �������
    for (i = 0; i < G->numVertexes; i++) //���������
    {
        scanf("%c", &G->adjList[i].data);
        G->adjList[i].firstedge = NULL; //ע�⽫�߱��ÿ�
    }
    for (k = 0; k < G->numEdges; k++) //�����߱�
    {
        printf("�����(Vi,Vj)�ϵĶ�����ţ�");
        scanf("%d%d", &i, &j); /*�����(Vi,Vj)�ϵĶ������*/
        /*ʹ��ͷ�巨����߱���*/
        e = (EdgeNode *)malloc(sizeof(EdgeNode)); //���ڴ�����ռ䣬���ɱ߱���

        e->adjvex = j;                     /*�ڽ����j*/
        e->next = G->adjList[i].firstedge; /*��eָ��ָ��ǰ����ָ��Ľ��*/
        G->adjList[i].firstedge = e;       /* ����ǰ�����ָ��ָ��e */

        e = (EdgeNode *)malloc(sizeof(EdgeNode)); //���ڴ�����ռ䣬���ɱ߱���

        e->adjvex = i;                     /* �ڽ����Ϊi */
        e->next = G->adjList[j].firstedge; /*��eָ��ָ��ǰ����ָ��Ľ��*/
        G->adjList[j].firstedge = e;       /* ����ǰ�����ָ��ָ��e*/
    }
}


// �ڽӱ��������ȱ���ͬ�ڽӾ����������ȱ�����ͬС�죬����Ҫ����һ����־���飬������bool���ͳ�ԱTRUE��FALSE��
// ����TRUE��ʾ�Ѿ����ʹ��� ��ͬ�㣺�ڵݹ麯������Ҫ����һ��EdgeNode
// *���͵ı���p�����б߱�ı�����Ҳ�����ڱ߱�������б����ڽӵ㡣

/*�ڽӱ��������ȵݹ��㷨*/
/*�ڽӱ��������ȵݹ�*/
void DFS(GraphAdj G, int i)
{
    EdgeNode *p;
    visited[i] = TRUE; //���ʹ��˸ö��㣬���ΪTRUE
    printf("%c", G->adjList[i].data);
    p = G->adjList[i].firstedge; //��pָ��߱��һ�����
    while (p)                    //�ڱ߱��ڱ���
    {
        if (!visited[p->adjvex]) //��δ���ʵ��ڽӶ���ݹ����
            DFS(G, p->adjvex);
        p = p->next;
    }
}

//�ڽӱ����ȱ�������
void DFSTraverse(GraphAdj G)
{
    int i;
    for (i = 0; i < G->numVertexes; i++)
        visited[i] = FALSE; //��ʼ����Ϊδ����?
    for (i = 0; i < G->numVertexes; i++)
        if (!visited[i])
            DFS(G, i); //��δ���ʵĶ������DFS��������ͨͼֻ��ִ��һ��?
}

/*������ȱ���*/
void BFS(GraphAdj G)
{

    Queue *Q = (LQueue)malloc(sizeof(Queue));
    for (int i = 0; i < G->numVertexes; i++)
    {
        visited[i] = FALSE;
    }
    InitQueue(Q); //��ʼ������
    for (int i = 0; i < G->numVertexes; i++)
    {
        visited[i] = TRUE;
        printf("\t%c", G->adjList[i].data);
        EnQueue(Q, i);

        while (!QueueisEmpty(Q))
        {
            DeQueue(Q, &i);                        //���ﲻ�ϵ��޸�i��ֵ����
            EdgeNode *e = G->adjList[i].firstedge; // i������ڽ�����ĵ�һ�����
            while (e)
            { // e����ʱ����e�������ڽӵ�������,Ҳ���Ǳ���i�������ڽӵ�
                if (!visited[e->adjvex])
                { // adjvex��e����ʾ�Ľ���±�
                    visited[e->adjvex] = TRUE;
                    printf("\t%c", G->adjList[e->adjvex].data);
                    EnQueue(Q, e->adjvex); //���ý�����
                }
                e = e->next; //����i����һ���ڽӵ�
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
    printf("\nͼ�������");
    system("pause");
    return 0;
}