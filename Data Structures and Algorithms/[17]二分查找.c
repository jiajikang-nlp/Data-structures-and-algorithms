/*
 * @Author: jjk
 * @Date: 2019-08-13 13:29:41
 * @Last Modified by: jjk
 * @Last Modified time: 2019-08-14 14:13:20
 * 程序功能： 顺序查找
 * coding：gbk
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*二分查找*/
int Binary_Search(int *a, int n, int key)
{
    int low, high, mid;
    low = 1;  /*定义最低下标为记录首位*/
    high = n; /*定义最高下标为记录末位*/
    while (low <= high)
    {
        /* code */
        mid = (low + high) / 2; //折半
        if (key < a[mid])       /*若查找值比中值小*/
        {
            /* code */
            high = mid - 1; /*最高位下标调整到中位下标小一位*/
        }
        else if (key > a[mid]) /*若查找值比中值大*/
        {
            low = mid + 1; /*最低位下标调整到中位下标大一位*/
        }
        else
        {
            return mid; /*如相等则说明mid即为查找到的位置*/
        }
    }
    return 0;
}
/*折半查找-递归算法*/
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
            return Search(key, mid + 1, high, k); /*在序列的后半部分查找*/
        }
        else
        {
            return Search(key, low, mid - 1, k); /*在序列的前半部分查找*/
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
    printf("\n-----------------------------二分查找顺序查找----------------------------\n");
    printf("i=%d", Binary_Search(a, length, 5));

    int n, i, addr;
    int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("递归查找法之数组的内容是：\n");
    for (i = 0; i < 10; i++)
    {
        /* code */
        printf("%d ", A[i]);
    }

    printf("\n请输入待查字符:");
    scanf("%d", &n);
    addr = Search(A, 0, 9, n);
    if (-1 != addr)
    {
        /* code */
        printf("%d is at the %dth unit is Arrav A\n", n, addr);
    }
    else
    {
        printf("查找失败");
    }
    getchar();
}
