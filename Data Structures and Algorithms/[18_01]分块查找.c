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
/*����ڵ�ṹ*/
typedef struct IndexItem
{
    ElemType index; //Ԫ���±�
    int start;
    int length;
} IndexItem;
IndexItem indexlist[MAX]; // ����˳���ṹ����-��������

ElemType MainList[MAXSIZE] = {22, 12, 13, 8, 9, 20, 33, 42, 44,38, 24, 48, 60, 58, 74, 49, 86, 53}; // һάint�������ʼ��

/*
������
    1������ֳɼ��飬�ұ�������򣬻��߷ֿ�����
        ��i<j�����j�������м�¼�Ĺؼ��־����ڵ�i���е����ؼ���
    2����������������ÿ����㺬�����ؼ������ָ�򱾿��һ������ָ�룬�Ұ��ؼ�������
���ҹ��̣�
    ��ȷ�������¼���ڿ飨˳����۰���ң������ڿ��ڲ��ң�˳����ң���
*/

/*��ȷ�������Ҽ�¼���ڿ飺˳������۰����*/
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

/*���ڲ���*/
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