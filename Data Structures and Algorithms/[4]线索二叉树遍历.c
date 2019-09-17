/*
 * @Author: jjk 
 * @Date: 2019-08-13 13:29:41 
 * @Last Modified by: jjk
 * @Last Modified time: 2019-08-13 14:20:35
 * �����ܣ���������������
 */


#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    Link,
    Thread
} PointerTag; /*Link==0��ʾָ�����Һ���ָ�룬Thread==1��ʾָ��ǰ�����̵�����*/


typedef struct BiThrNode
{ /*�������洢���ṹ*/

    char data;                         // �������
    struct BiThrNode *lchild, *rchild; // ���Һ���ָ��
    int LTag;
    int RTag; // ���ұ�־
} BiThrNode, *BiThrTree;

BiThrTree pre; /*�������ṹ��ȫ�ֱ�����ʼ��ָ��ոշ��ʹ��Ľڵ�*/

/*���������������������*/
void InThreading(BiThrTree p)
{ /*�������ṹ��ָ�����*/

    if (p)
    {
        /* code */
        InThreading(p->lchild); /*�ݹ�������������*/
        // ���ĳ�ڵ����ָ����Ϊ�գ���Ϊ��ǰ���ڵ�ոշ��ʹ�����ֵ����pre�����Կ��Խ�pre��ֵ��p->lchild,
        // ���޸�p->LTag = Thread(Ҳ���Ƕ���Ϊ1) �����ǰ���ڵ��������
        if (!p->lchild) /*û������*/
        {

            p->LTag = Thread; // ǰ������
            p->lchild = pre;  // ����ָ��ָ��ǰ��
        }
        // p�ڵ�ĺ�̻�û�з��ʵ������ֻ�ܶ�����ǰ���ڵ�pre����ָ��rchild���жϣ�
        if (!pre->rchild) /*��ʾΪ�գ�ǰ��û���Һ���*/
        {

            pre->RTag = Thread; // ��������
            pre->rchild = p;    //p����pre�ĺ�̣�ǰ���Һ���ָ��ָ����(��ǰ�ڵ�p)
        }

        pre = p;                // ���ǰ���ͺ�̵��жϺ󣬵�ǰ�Ľڵ�p��ֵ��pre�����Ա���һ��ʹ�ã�����preָ��p��ǰ��
        InThreading(p->rchild); /*�ݹ�������������*/
    }
}

/*��������������-����һ��˫������*/
/*��˫������ṹһ�����ڶ������������������һ��ͷ��㣬����lchild���ָ��ָ��������ĸ��ڵ㣬��rchild���ָ��ָ��
�������ʱ���ʵ����һ���ڵ㡣��֮��������������������еĵ�һ���ڵ��У�lchild��ָ������һ������rchild��ָ���
ָ��ͷ���.��������ĺô��������Ǽȿ��Դӵ�һ�������˳��̼���������Ҳ���Դ����һ���ڵ���˳ǰ�����б�����
*/
/*Tָ��ͷ��㣬ͷ�������lchildָ����ڵ㣬ͷ�������rchildָ�����������*/
/*���һ���ڵ㡣�������������������ʾ��һ��������T*/
int InOrderTraverse_Thr(BiThrTree T)
{

    BiThrTree p;   // ָ��p
    p = T->lchild; /*Pָ����ڵ�*/
    while (p != T) /*���������������p==T*/
    {

        while (p->LTag == Link) /*��LTag==0ʱѭ�����������е�һ���ڵ�*/
            p = p->lchild;
        printf("%c", p->data); /*��ʾ������ݣ����Ը���Ϊ�����Խ�����*/
        while (p->RTag == Thread && p->rchild != T) /*���ڽڵ�H��RTag==1�Ҳ���ָ��ͷ���*/
        {
            /* code */
            p = p->rchild;/*��˴�ӡH�ĺ��D,֮����ΪD��RTag��Link������˳�ѭ��*/
            printf("%c", p->data);
        }
        p = p->rchild; /*p����������������pָ���˽ڵ�D���к���I*/
    }
    return 0;
}