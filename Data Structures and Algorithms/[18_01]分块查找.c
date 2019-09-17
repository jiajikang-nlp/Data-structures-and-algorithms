/*
 * @Author: jjk
 * @Date: 2019-08-21 13:05:41
 * @Last Modified by: jjk
 * @Last Modified time: 2019-08-21 13:19:47
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 3
#define MAXSIZE 18
typedef int ElemType;
/*定义节点结构*/
typedef struct IndexItem
{
    ElemType index; //元素下标
    int start;
    int length;
} IndexItem;
IndexItem indexlist[MAX]; // 定义顺表表结构变量-变量数组

ElemType MainList[MAXSIZE] = {22, 12, 13, 8, 9, 20, 33, 42, 44,38, 24, 48, 60, 58, 74, 49, 86, 53}; // 一维int型数组初始化

/*
条件：
    1、将表分成几块，且表或者有序，或者分块有序；
        若i<j，则第j块中所有记录的关键字均大于第i块中的最大关键字
    2、建立“索引表”（每个结点含有最大关键字域和指向本块第一个结点的指针，且按关键字有序）
查找过程：
    先确定待查记录所在块（顺序或折半查找），再在块内查找（顺序查找）。
*/

/*先确定待查找记录所在块：顺序或者折半查找*/
int sequential(IndexItem indexlist[], ElemType key)
{
    int index;
    if (indexlist[0].index >= key)
        return 1;
    for (index = 1; index <= MAX; index++)
    {
        if ((indexlist[index - 1].index < key) && (indexlist[index].index >= key))
            return index + 1;
    }
    return 0;
}

/*块内查找*/
int mainsequential(ElemType MainList[], int index, ElemType key)
{
    int i, num = 0;
    for (i = 0; i < index - 1; i++)
    {
        num += indexlist[i].length;
    }
    for (i = num; i < num + indexlist[index - 1].length; i++)
    {
        if (MainList[i] == key)
            return i + 1;
    }
    return -1;
}

int main(void)
{
    indexlist[0].index = 22;
    indexlist[0].start = 1;
    indexlist[0].length = 6;
    indexlist[1].index = 48;
    indexlist[1].start = 7;
    indexlist[1].length = 6;
    indexlist[2].index = 86;
    indexlist[2].start = 13;
    indexlist[2].length = 6;
    int index = sequential(indexlist, 38);
    printf("index = %d.\n", index);
    int mainindex = mainsequential(MainList, index, 38);
    printf("mainindex = %d.\n", mainindex);
    return 0;
}