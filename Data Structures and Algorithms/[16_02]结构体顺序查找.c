/*
 * @Author: jjk 
 * @Date: 2019-08-21 22:05:11 
 * @Last Modified by: jjk
 * @Last Modified time: 2019-08-21 22:10:36
 */

#include <stdio.h>
#define listsize 100

/*������ṹ�ڵ�����*/
typedef struct
{
    int data[listsize];
    int length;
} sqlist;

/*˳��������*/
void createtsqlist(sqlist L, int a[], int n) //�����鴴��˳���
{
    L.length = 0;
    for (int i = 0; i < n; i++)
    {
        L.data[L.length++] = a[i];
    }
}

void findvalue(sqlist L, int x) //����x�Ƿ���˳�����
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == x)
        {
            printf("%d�ǵ�%d��Ԫ��\n", x, i + 1);
            return;
        }
    }
    printf("%d����˳�����\n", x);
}


void search_bin(sqlist L, int x) //�۰���������
{
    int low = 1;
    int high = L.length;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x == L.data[mid])
        {
            printf("%d�ǵ�%dԪ��\n", x, mid + 1);
            return;
        }
        else if (x < L.data[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    printf("%d����˳�����\n", x);
}


void main()
{
    int a[10] = {1, 23, 45, 34, 67, 87, 9, 13, 7, 11};
    int b[10] = {1, 2, 3, 4, 5, 6, 9, 14, 19, 23}; //��֤b��Ԫ������
    sqlist L1, L2;                                 // L2����Ϊ�����
    createtsqlist(L1, a, 10);
    findvalue(L1, 1); //����45�Ƿ��ڱ��ڿ��Ի���������
    
    //createtsqlist(L2, b, 10);
    //search_bin(L2, 14); //����14�Ƿ��ڱ��ڿ��Ի���������
}


