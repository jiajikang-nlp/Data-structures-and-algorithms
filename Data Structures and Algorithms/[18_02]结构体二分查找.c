/*
 * @Author: jjk 
 * @Date: 2019-08-12 11:23:53 
 * @Last Modified by: jjk
 * @Last Modified time: 2019-08-21 18:10:37
 * 程序功能：折半查找
 * coding:gbk

 *  
 */

#include <stdio.h>
#include <stdlib.h>

typedef int keyType;
 
typedef struct
{
    /* data */
    keyType key; // 查找表中每个数据元素的值
    // 如果需要，还可以添加其他属性
} ElemType;

/*定义节点结构*/
typedef struct
{
    ElemType *elem; //存放查找表中数据元素的数组
    int length;     ////记录查找表中数据的总数量
} SSTable;

/*创建查找表*/
void Create(SSTable **st, int length)
{
    (*st) = (SSTable *)malloc(sizeof(SSTable));
    (*st)->length = length;
    (*st)->elem = (ElemType *)malloc(sizeof(ElemType) * length);
    printf("输入表中的数据元素：\n");
    //根据查找表中数据元素的总长度，在存储时，从数组下标为 1 的空间开始存储数据
    for (int i = 1; i <= length; i++)
    {
        /* code */
        scanf("%d", &((*st)->elem[i].key));   
    }

    free((*st)->elem);
    free((*st));
}

/*折半查找法*/
int search(SSTable *ST, keyType key)
{
    int low = 1;           //初始状态 low 指针指向第一个关键字
    int high = ST->length; // high 指向最后一个关键字
    int mid = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;         //int 本身为整形，所以，mid 每次为取整的整数
        if ((ST->elem[mid].key) == key) /*如果 mid 指向的同要查找的相等，返回 mid 所指向的位置*/
        {
            /* code */
            return mid;
        }
        else if (key < (ST->elem[mid].key)) /*如果mid指向的关键字较大，则更新high 指针的位置*/
        {
            high = mid - 1;
        }
        else /* 反之，则更新 low 指针的位置*/
        {
            low = mid + 1;
        }
    }
    //printf("mid=%d\n", mid);
    return 0;
}

void main()
{
    SSTable *st; // 创建结构体指针变量
    int key;

    Create(&st, 5); // 引用节点结构体，表长度

    printf("请输入查找数据的关键字：\n");
    scanf("%d", &key);
    int location = search(st, key);

    printf("loca=%d\n", location);
    //如果返回值为 0，则证明查找表中未查到 key 值，
    if (location == 0)
    {
        printf("查找表中无该元素");
    }
    else
    {
        printf("数据在查找表中的位置为：%d", location);
    }
    
}
