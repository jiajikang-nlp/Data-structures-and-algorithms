/*
 * @Author: jjk 
 * @Date: 2019-08-13 13:29:41 
 * @Last Modified by: jjk
 * @Last Modified time: 2019-08-14 14:13:20
 * �����ܣ� ����ѵ������ģ��
 * coding��gbk
 */

#include <stdio.h>
#include <stdlib.h>

typedef char VertexType; /*�������Ͷ���*/
typedef int EdgeType;    /*����Ȩֵ���Ͷ���*/
#define MAXVEX 100       /*��󶥵���*/
#define INFINITY 65535   /*��65535�������*/

/*1��ͼ�ṹ*/
typedef struct
{

    VertexType vexs[MAXVEX];      /*�����һά����*/
    EdgeType arc[MAXVEX][MAXVEX]; /*��Ӿ��󣬿ɿ����߱���ά����*/
    int numVertexes, numEdges;    /*ͼ�е�ǰ�Ķ���ͱ���*/

} MGraph;                         /*ͼ�ṹ����*/
/*�������ϵĽṹ���壬����һ��ͼ����ʵ���Ǹ������ͱ߱��������ݵĹ���*/
/*2������������ͼ����Ӿ���*/
/*n�������e���ߵ�������ͼ�Ĵ�����ʱ�临�Ӷ�ΪO(n+n*n+e),���ж��ڽӾ���Garc�ĳ�ʼ���ķ���O(n*n)��ʱ��*/

void CreateMGraph(MGraph *G){
    int i,j,k,w;
    printf("�����붥�����ͱ���:\n");
    scanf("%d %d",&G->numVertexes,&G->numEdges);/*���붥�����ͱ���*/
    setbuf(stdin, NULL);//�������뻺���� Ϊ�ջ�������ÿ������һ���س����������� \n�ַ����ڻ�������
    for (i = 0; i < G->numVertexes; i++) /*��������������ȡ������Ϣ�����������*/
    {
        /* code */
        printf("\n�������%d������洢��ֵ:",i);
        scanf("%c",&G->vexs[i]);
        setbuf(stdin, NULL);
    }

    for (i = 0; i < G->numVertexes; i++)
    {
        for (j = 0; j < G->numVertexes; j++)
        {
            G->arc[i][j] = INFINITY; /*�ڽӾ����ʼ��*/
        }
        
    }

    for (k = 0; k < G->numEdges; k++)/*����numEdges���ߣ�������Ӿ���*/
    {
        /* code */
        printf("����(Vi,Vj)�ϵ��±�i���±�j��Ȩw:");
        scanf("%d %d %d",&i,&j,&w);/*�����(Vi,Vj)�ϵ�Ȩw*/
        G->arc[i][j] = w;
        G->arc[j][i] = G->arc[i][j]; /*��Ϊ������ͼ������Գ�*/

    }
}

int main(int argc, char **argv)
{
    MGraph MG;
    CreateMGraph(&MG);
    system("pause");
    return 0;
}