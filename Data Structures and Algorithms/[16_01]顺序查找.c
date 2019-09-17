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

/*
顺序查找（Sequential Search）又叫线性查找，是最基本的查找技术，
它的查找过程是：
    1:从表中第一个（或最后一个）记录开始，逐个进行记录的关键字和给定值比较，若某个记录的关键字和给定值相等，则查找成功，找到所查的记录；
    2:如果直到最后一个（或第一个）记录，其关键字和给定值比较都不等时，则表中没有所查的记录，查找不成功。
*/

/*顺序查找的算法实现一*/
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
    return 0; // 查不到就返回0
}
/*
这段代码非常简单，就是在数组a（注意元素值从下标1开始）中查看有没有关键字（key），
当你需要查找复杂表结构的记录时，只需要把数组a与关键字key定义成你需要的表结构和数据类型即可。
*/

/*顺序查找的算法实现二*/
/*时间复杂度O(n)*/
int Sequential_Search2(int *a, int n, int key)
{

    int i;
    a[0] = key; /*设置a[0]为关键字值，称之为“哨兵”*/
    i = n;      /*循环从数组尾部开始*/
    while (a[i] != key)
    {
        /* code */
        i--;
    }
    return i; /*返回零则说明查找失败*/
}

/*
使用结构体描述顺序表。
SeqList是新定义的结构体类型标识符，用来定义顺序表，可使用语句SeqList；定义一个顺序表。
也可使用语句SeqList *L；定义一个指向顺序表的指针L

*/


#define LIST_SIZE 20 //初始容量20
#define INCREAMENT 10 //每次扩容10
#define ERROR 0 // 标识定义
#define OK 1

typedef int elemType;
typedef int Status;


/*定义节点结构*/
typedef struct
{
    elemType *elems;  /*存储空间基址*/
    int length;       /*当前元素个数*/
    int listsize; /*总容量*/
} SqList;

/*初始化线性表*/
Status initList(SqList L)
{
    L.elems = (elemType *)malloc(LIST_SIZE*sizeof(elemType));
    if (!L.elems)
    {
        /* code */
        return ERROR;// 内存分配失败
    }
    L.length = 0; // 长度为0
    L.listsize = LIST_SIZE; // 容量为初始容量
    return OK;
}


/*结构体顺序查找1*/
Status Search_Seg(SqList L,Status key){
    for (int i = 0; i < L.length; i++)
    {
        /* code */
        if (L.elems[i]== key)
        {
            /* code */
            return i; // 返回索引值
        }
        
    }
    return 0; // 未能找到
}


void main()
{

    int *a = NULL;
    int a1[] = {1, 2, 3, 4, 5, 6, 7};
    a = a1;
    int length = sizeof(a1) / sizeof(a1[0]);
    printf("length=%d\n", length);
    printf("\n-----------------------------普通按顺查找-----------------------------\n");
    printf("key=%d", Sequential_Search(a, length, 2));
    printf("\n-----------------------------有哨兵顺序查找-----------------------------\n");
    printf("key=%d", Sequential_Search2(a, length, 2));
    printf("\n-----------------------------结构体顺序查找----------------------------\n");


}
