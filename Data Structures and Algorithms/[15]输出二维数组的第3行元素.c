#include<stdio.h>
/*

*((a+n)+m):��n�е�m��
*(a[n]+m):��n�е�m��

*/
void main()
{
	int a[3][5],i,j,(*p)[5];
	p=&a[0];
	printf("please input:\n");
	for(i=0;i<3;i++)								/*���ƶ�ά���������*/
		for(j=0;j<5;j++)							/*���ƶ�ά���������*/
			scanf("%d",(*(p+i))+j);					/*Ϊ��ά�����е�Ԫ�ظ�ֵ*/
		p=&a[2]; 								/*pΪ��һ��Ԫ�صĵ�ַ*/
		printf("the third line is:\n");
			for(j=0;j<5;j++)
				printf("%5d",*((*p)+j));				/*�����ά�����е�Ԫ��*/
			printf("\n");
}
