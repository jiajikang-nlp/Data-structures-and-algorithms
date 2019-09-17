/*
 * @Author: jjk
 * @Date: 2019-08-13 13:29:41
 * @Last Modified by: jjk
 * @Last Modified time: 2019-08-14 14:13:20
 * �����ܣ� ˳�����
 * coding��gbk
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
˳����ң�Sequential Search���ֽ����Բ��ң���������Ĳ��Ҽ�����
���Ĳ��ҹ����ǣ�
    1:�ӱ��е�һ���������һ������¼��ʼ��������м�¼�Ĺؼ��ֺ͸���ֵ�Ƚϣ���ĳ����¼�Ĺؼ��ֺ͸���ֵ��ȣ�����ҳɹ����ҵ�����ļ�¼��
    2:���ֱ�����һ�������һ������¼����ؼ��ֺ͸���ֵ�Ƚ϶�����ʱ�������û������ļ�¼�����Ҳ��ɹ���
*/

/*˳����ҵ��㷨ʵ��һ*/
int Sequential_Search(int *a, int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
    {
        /* code */
        if (a[i] == key)
        {
            /* code */
            return i;
        }
    }
    return 0; // �鲻���ͷ���0
}
/*
��δ���ǳ��򵥣�����������a��ע��Ԫ��ֵ���±�1��ʼ���в鿴��û�йؼ��֣�key����
������Ҫ���Ҹ��ӱ�ṹ�ļ�¼ʱ��ֻ��Ҫ������a��ؼ���key���������Ҫ�ı�ṹ���������ͼ��ɡ�
*/

/*˳����ҵ��㷨ʵ�ֶ�*/
/*ʱ�临�Ӷ�O(n)*/
int Sequential_Search2(int *a, int n, int key)
{

    int i;
    a[0] = key; /*����a[0]Ϊ�ؼ���ֵ����֮Ϊ���ڱ���*/
    i = n;      /*ѭ��������β����ʼ*/
    while (a[i] != key)
    {
        /* code */
        i--;
    }
    return i; /*��������˵������ʧ��*/
}

/*
ʹ�ýṹ������˳���
SeqList���¶���Ľṹ�����ͱ�ʶ������������˳�����ʹ�����SeqList������һ��˳���
Ҳ��ʹ�����SeqList *L������һ��ָ��˳����ָ��L

*/


#define LIST_SIZE 20 //��ʼ����20
#define INCREAMENT 10 //ÿ������10
#define ERROR 0 // ��ʶ����
#define OK 1

typedef int elemType;
typedef int Status;


/*����ڵ�ṹ*/
typedef struct
{
    elemType *elems;  /*�洢�ռ��ַ*/
    int length;       /*��ǰԪ�ظ���*/
    int listsize; /*������*/
} SqList;

/*��ʼ�����Ա�*/
Status initList(SqList L)
{
    L.elems = (elemType *)malloc(LIST_SIZE*sizeof(elemType));
    if (!L.elems)
    {
        /* code */
        return ERROR;// �ڴ����ʧ��
    }
    L.length = 0; // ����Ϊ0
    L.listsize = LIST_SIZE; // ����Ϊ��ʼ����
    return OK;
}


/*�ṹ��˳�����1*/
Status Search_Seg(SqList L,Status key){
    for (int i = 0; i < L.length; i++)
    {
        /* code */
        if (L.elems[i]== key)
        {
            /* code */
            return i; // ��������ֵ
        }
        
    }
    return 0; // δ���ҵ�
}


void main()
{

    int *a = NULL;
    int a1[] = {1, 2, 3, 4, 5, 6, 7};
    a = a1;
    int length = sizeof(a1) / sizeof(a1[0]);
    printf("length=%d\n", length);
    printf("\n-----------------------------��ͨ��˳����-----------------------------\n");
    printf("key=%d", Sequential_Search(a, length, 2));
    printf("\n-----------------------------���ڱ�˳�����-----------------------------\n");
    printf("key=%d", Sequential_Search2(a, length, 2));
    printf("\n-----------------------------�ṹ��˳�����----------------------------\n");


}
