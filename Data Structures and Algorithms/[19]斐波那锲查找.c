/*
 * @Author: jjk 
 * @Date: 2019-08-21 18:17:41 
 * @Last Modified by: jjk
 * @Last Modified time: 2019-08-21 21:48:43
 */
/*
    1、斐波那契搜索（Fibonacci search）：又称斐波那契查找，是“区间中单峰函数”的搜索技术。
    斐波那契搜索是在“二分查找”的基础上根据“斐波那契数列”进行分割的（即也属于对于“有序”数列进行查找！！！）。
    2、斐波那契搜索的时间复杂度： O(n) = log2n,且期望复杂度也为log2n

    3、斐波那契搜索与二分查找的对比：
        斐波那契查找的优点是“它只涉及加法和减法运算，而不用除法“，而除法比加减法要占用的时间更多，因此，斐波那契查找的运行时间”理论上比这般查找小“，但是还是得视具体情况而定。

    4、已经被证明：斐波那契搜索是一种“函数估值次数最少的最优”搜索算法！！！！！

    5、斐波那契搜索思想：在斐波那契数列找到第一个“大于等于”表中元素个数的数F[n]，将原来的查找表“扩展为长度为F[n]（如果要补元素，则补充“重复最后一个元素”，

*/

#include <stdio.h>
#include <stdlib.h>

const int max_size = 20; //斐波那契数组的长度
int F[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55};

/*构造一个斐波那锲数组*/
void Fibonacci(int *F)
{
    F[0] = 1;
    F[1] = 1;
    for (int i = 2; i < max_size; ++i)
    {
        /* code */
        F[i] = F[i + 1] + F[i + 2];
    }
}



// 斐波那锲查找
/*a为要查找的数组,n为要查找的数组长度,key为要查找的关键字*/
int Fibonacci_serch(int *a, int n, int key)
{
    int low, high, mid, i, k;
    low = 1;  /*定义最低下标为记录首位*/
    high = n; /*定义最高下标为记录末位*/
   
    // int F[max_size];
    // Fibonacci(F); // 构造一个斐波那锲数组

    k = 0;
    while (n > F[k] - 1) /*计算n位于斐波那契数列的位置*/
    {
        /* code */
        k++;
    }
    /*当有序表的元素个数不是斐波那契数列中的某个数字时，需要把有序表的元素个数长度补齐，让它成为斐波那契数列中的一个数值，当然把原有序表截断肯定是不可能的，不然还怎么查找*/
    for (i = n; i < F[k] - 1; i++) /*将不满的数值补全*/
    {
        /* code */
        a[i] = a[n];
    }


    while (low <= high)
    {
        mid = low + F[k - 1] - 1; /*计算当前分隔的下标*/
        if (key < a[mid])         /*若查找记录小于当前分隔记录*/
        {
            /* code */
            // 说明:low = mid + 1说明待查找的元素在 [low, mid - 1]
            // 范围内，k -= 1 说明范围[low, mid - 1] 内的元素个数为F(k - 1) - 1 个，所以可以递归 的应用斐波那契查找
            high = mid - 1; // 最高下标调整到分隔下标mid-1处
            k = k - 1;      /*菲波那切数列下标减一位*/
        }
        else if (key > a[mid]) /*若查找记录大于当前分隔记录*/
        {
            // low=mid+1说明待查找的元素在[mid+1,hign]范围内，k-=2
            // 说明范围[mid+1,high]内的元素个数为n-（F(k-1))= Fk-1-F(k-1)=Fk-F(k-1)-1=F(k-2)-1个，所以可以递归的应用斐波那契查找
            low = mid + 1; // 最低下标调整到分隔下标mid+1处
            k = k - 2;     /*菲波那切数列下标减一位*/
        }
        else
        {
            /* code */
            if (mid <= n)
            {
                /* code */
                return mid; /*若相等则说明mid即为查找到的位置*/
            }
            else
            {
                return n; /*若mid>n说明是补全数值，返回n*/
            }
        }
    }

    return 0;
}

int main(int argc, char const *argv[])
{

    //int array[] = {0, 16, 24, 35, 47, 59, 62, 73, 88, 99};
    int array[] = {0, 1, 26, 24, 35, 47, 59, 62, 73, 88, 99};
    int longs = sizeof(array) / sizeof(int);
    printf("longs=%d\n",longs);
    int co = Fibonacci_serch(array,longs, 24);
    printf("co = %d",co);
    return 0;
}

