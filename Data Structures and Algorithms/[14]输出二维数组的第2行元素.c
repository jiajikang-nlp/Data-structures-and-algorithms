#include<stdio.h>
/*

*((a+n)+m):��n�е�m��
*(a[n]+m):��n�е�m��

*/
void main()
{
	int a[3][5],i,j;
	printf("please input:\n");
	for(i=0;i<3;i++)								/*���ƶ�ά���������*/
		for(j=0;j<5;j++)							/*���ƶ�ά���������*/
			scanf("%d",*(a+i)+j);					/*Ϊ��ά�����е�Ԫ�ظ�ֵ*/								/*pΪ��һ��Ԫ�صĵ�ַ*/
		printf("the second line is:\n");
		for(j=0;j<5;j++)
				printf("%5d",*(*(a+1)+j));				/*�����ά�����е�Ԫ��*/
			printf("\n");
}
