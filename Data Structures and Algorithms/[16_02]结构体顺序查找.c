/*
 * @Author: jjk 
 * @Date: 2019-08-21 22:05:11 
 * @Last Modified by: jjk
 * @Last Modified time: 2019-08-21 22:10:36
 */

#include <stdio.h>
#define listsize 100

/*创建表结构节点类型*/
typedef struct
{
    int data[listsize];
    int length;
} sqlist;

/*顺序表的类型*/
void createtsqlist(sqlist L, int a[], int n) //用数组创建顺序表
{
    L.length = 0;
    for (int i = 0; i < n; i++)
    {
        L.data[L.length++] = a[i];
    }
}

void findvalue(sqlist L, int x) //查找x是否在顺序表内
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == x)
        {
            printf("%d是第%d个元素\n", x, i + 1);
            return;
        }
    }
    printf("%d不在顺序表内\n", x);
}


void search_bin(sqlist L, int x) //折半查找有序表
{
    int low = 1;
    int high = L.length;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x == L.data[mid])
        {
            printf("%d是第%d元素\n", x, mid + 1);
            return;
        }
        else if (x < L.data[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    printf("%d不在顺序表内\n", x);
}


void main()
{
    int a[10] = {1, 23, 45, 34, 67, 87, 9, 13, 7, 11};
    int b[10] = {1, 2, 3, 4, 5, 6, 9, 14, 19, 23}; //保证b中元素有序
    sqlist L1, L2;                                 // L2创建为有序表
    createtsqlist(L1, a, 10);
    findvalue(L1, 1); //查找45是否在表内可以换成其他数
    
    //createtsqlist(L2, b, 10);
    //search_bin(L2, 14); //查找14是否在表内可以换成其他数
}


