#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
int list[MAXSIZE];
int n;
/*insert in a seqlist*/
int sq_insert(int list[], int *p_n, int i, int x)
{int j;
	if (i<0 || i>*p_n)  return(1);
	if (*p_n==MAXSIZE)  return(2);
	for (j=*p_n+1; j>i; j--)
		list[j]=list[j-1];
	list[i]=x;
	(*p_n)++;
	return(0);
	}
/*delete in a seq list*/
int sq_delete(int list[], int *p_n, int i)
	{int j;
	if (i<0 || i>=*p_n)  return(1);
	for (j = i+1; j<=*p_n; j++)
		list[j-1] = list[j];
	(*p_n)--;
	return(0);
	}

int build()
{
	int i;
	printf("\t输入数组元素个数\n");
	printf("\tn=");
	scanf_s("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("list[%d]=",i);
		scanf_s("%d",&list[i]);
	}
}

void display()
{
	int i;
	printf("\t数组元素是:\n");
	for(i=0; i<n; i++)
	{
		printf("   list[%d]=%4d",i,list[i]);
		if((i+1)%4==0) printf("\n");
	}
	printf("\n");
}

void main(){
	int i,x,temp,k;
	char ch;
	k=0;
/*
编写主调函数 wwl 2019年2月28日
*/
	do{
		printf("\n\n\n");
		printf("\t吴婉灵  线性表的顺序存储实验");
		printf("\n\t=====================");
		printf("\n\t1.建立线性表");
		printf("\n\t2.在第i位置插入元素e");
		printf("\n\t3.修改e的值为新值");
		printf("\n\t4.删除第i个元素");
		printf("\n\t5.查找值为e的元素");
		printf("\n\t6.对线性表排序(暂时为空)");
		printf("\n\t7.退出程序");
		printf("\n\t=====================\n\t请输入你的选择：");
		scanf("%d",&k);
		switch(k){
			case 1:{printf("\n\t1.建立线性表\n");
					build();
					display();}break;
			case 2:{printf("\n\t2.在第i位置插入元素e\n");
					printf("请输入要插入数值的位置i\n");
					scanf_s("%d",&i);
					printf("请输入要插入的数值x：\n");
					scanf_s("%d",&x);
					sq_insert(list,&n,i,x);
					display();}break;
			case 3:{printf("\n\t3.修改e的值为新值\n");
					printf("请输入要修改的元素下标i：\n");
					scanf_s("%d",&i);
					printf("请输入修改的数值x：\n");
					scanf_s("%d",&x);
					sq_delete(list,&n,i);
					sq_insert(list,&n,i,x);
					display();}break;
			case 4:{printf("\n\t4.删除第i个元素");
					printf("请输入要删除的数值的位置i：\n");
					scanf_s("%d",&i);
					printf("  删除之前的值：\n");
					display();
					sq_delete(list,&n,i);
					printf("  删除之后的值：\n");
					display();}break;
			case 5:{printf("\n\t5.查找值为e的元素");	}break;
			case 6:{printf("\n\t6.对线性表排序(暂时为空)");}break;
			case 7:{printf("\n\t7.退出程序");}break;
			}
		}while(k!=7);
	printf("\n      再见！");
	printf("\n      按Enter键返回。");
	ch=getchar();
}
