#include<stdio.h>
/*

*((a+n)+m):第n行第m列
*(a[n]+m):第n行第m列

*/
void main()
{
	int a[3][5],i,j;
	printf("please input:\n");
	for(i=0;i<3;i++)								/*控制二维数组的行数*/
		for(j=0;j<5;j++)							/*控制二维数组的列数*/
			scanf("%d",*(a+i)+j);					/*为二维数组中的元素赋值*/								/*p为第一个元素的地址*/
		printf("the second line is:\n");
		for(j=0;j<5;j++)
				printf("%5d",*(*(a+1)+j));				/*输出二维数组中的元素*/
			printf("\n");
}
