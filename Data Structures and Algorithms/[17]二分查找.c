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
/*���ֲ���*/
int Binary_Search(int *a, int n, int key)
{
    int low, high, mid;
    low = 1;  /*��������±�Ϊ��¼��λ*/
    high = n; /*��������±�Ϊ��¼ĩλ*/
    while (low <= high)
    {
        /* code */
        mid = (low + high) / 2; //�۰�
        if (key < a[mid])       /*������ֵ����ֵС*/
        {
            /* code */
            high = mid - 1; /*���λ�±��������λ�±�Сһλ*/
        }
        else if (key > a[mid]) /*������ֵ����ֵ��*/
        {
            low = mid + 1; /*���λ�±��������λ�±��һλ*/
        }
        else
        {
            return mid; /*�������˵��mid��Ϊ���ҵ���λ��*/
        }
    }
    return 0;
}
/*�۰����-�ݹ��㷨*/
int Search(int key[], int low, int high, int k)
{
    int mid;
    if (low > high)
    {
        return -1;
    }
    else
    {
        mid = (high + low) / 2;
        if (key[mid] == k)
            return mid;
        if (k > key[mid])
        {
            return Search(key, mid + 1, high, k); /*�����еĺ�벿�ֲ���*/
        }
        else
        {
            return Search(key, low, mid - 1, k); /*�����е�ǰ�벿�ֲ���*/
        }
    }
    return 0;
}

void main()
{

    int *a = NULL;
    int a1[] = {1, 2, 3, 4, 5, 6, 7};
    a = a1;
    int length = sizeof(a1) / sizeof(a1[0]);
    printf("length=%d", length);
    printf("\n-----------------------------���ֲ���˳�����----------------------------\n");
    printf("i=%d", Binary_Search(a, length, 5));

    int n, i, addr;
    int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("�ݹ���ҷ�֮����������ǣ�\n");
    for (i = 0; i < 10; i++)
    {
        /* code */
        printf("%d ", A[i]);
    }

    printf("\n����������ַ�:");
    scanf("%d", &n);
    addr = Search(A, 0, 9, n);
    if (-1 != addr)
    {
        /* code */
        printf("%d is at the %dth unit is Arrav A\n", n, addr);
    }
    else
    {
        printf("����ʧ��");
    }
    getchar();
}
