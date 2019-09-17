/*
 * @Author: jjk 
 * @Date: 2019-08-12 11:23:53 
 * @Last Modified by: jjk
 * @Last Modified time: 2019-08-21 18:10:37
 * �����ܣ��۰����
 * coding:gbk

 *  
 */

#include <stdio.h>
#include <stdlib.h>

typedef int keyType;
 
typedef struct
{
    /* data */
    keyType key; // ���ұ���ÿ������Ԫ�ص�ֵ
    // �����Ҫ�������������������
} ElemType;

/*����ڵ�ṹ*/
typedef struct
{
    ElemType *elem; //��Ų��ұ�������Ԫ�ص�����
    int length;     ////��¼���ұ������ݵ�������
} SSTable;

/*�������ұ�*/
void Create(SSTable **st, int length)
{
    (*st) = (SSTable *)malloc(sizeof(SSTable));
    (*st)->length = length;
    (*st)->elem = (ElemType *)malloc(sizeof(ElemType) * length);
    printf("������е�����Ԫ�أ�\n");
    //���ݲ��ұ�������Ԫ�ص��ܳ��ȣ��ڴ洢ʱ���������±�Ϊ 1 �Ŀռ俪ʼ�洢����
    for (int i = 1; i <= length; i++)
    {
        /* code */
        scanf("%d", &((*st)->elem[i].key));   
    }

    free((*st)->elem);
    free((*st));
}

/*�۰���ҷ�*/
int search(SSTable *ST, keyType key)
{
    int low = 1;           //��ʼ״̬ low ָ��ָ���һ���ؼ���
    int high = ST->length; // high ָ�����һ���ؼ���
    int mid = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;         //int ����Ϊ���Σ����ԣ�mid ÿ��Ϊȡ��������
        if ((ST->elem[mid].key) == key) /*��� mid ָ���ͬҪ���ҵ���ȣ����� mid ��ָ���λ��*/
        {
            /* code */
            return mid;
        }
        else if (key < (ST->elem[mid].key)) /*���midָ��Ĺؼ��ֽϴ������high ָ���λ��*/
        {
            high = mid - 1;
        }
        else /* ��֮������� low ָ���λ��*/
        {
            low = mid + 1;
        }
    }
    //printf("mid=%d\n", mid);
    return 0;
}

void main()
{
    SSTable *st; // �����ṹ��ָ�����
    int key;

    Create(&st, 5); // ���ýڵ�ṹ�壬����

    printf("������������ݵĹؼ��֣�\n");
    scanf("%d", &key);
    int location = search(st, key);

    printf("loca=%d\n", location);
    //�������ֵΪ 0����֤�����ұ���δ�鵽 key ֵ��
    if (location == 0)
    {
        printf("���ұ����޸�Ԫ��");
    }
    else
    {
        printf("�����ڲ��ұ��е�λ��Ϊ��%d", location);
    }
    
}
