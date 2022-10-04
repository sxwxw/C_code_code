#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define N 20
#define M 2*N-1
#define MAXSUM 99999

//����ڵ� 
typedef struct{
	int weigth;
	int parent,left,right;
}HTNode,HuffmanTree[M+1];

//��ʼ������ 
void initHuffmanTree(HuffmanTree HT,int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		HT[i].weigth = 0;
		HT[i].left = 0;
		HT[i].right = 0;
		HT[i].parent = -1;
	}
	for(i=n+1;i<=2*n-1;i++)
	{
		HT[i].weigth = 0;
		HT[i].left = 0;
		HT[i].right = 0;
		HT[i].parent = 0;
	}
}

//����ÿ������Ȩ�� 
void inputHuffmanTree(HuffmanTree HT,int n)
{
	int i,w;
	printf("����Ȩֵ:");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&w);
		HT[i].weigth = w;
	}
}
//�ҳ��ڵ���Ȩ����С�������ڵ�
void select(HuffmanTree HT,int len,int &s1,int &s2)
{
	int min1,min2,i;
	min1 = min2 = MAXSUM;
	for(i=1;i<=len;i++)
	{
		if(HT[i].weigth<min1 && HT[i].parent ==-1)
		{
			min1 = HT[i].weigth;
			s1 = i; 
		}else{
			if(HT[i].weigth<min2 && HT[i].parent ==-1)
			{
				min2 = HT[i].weigth;
				s2 = i;
			}
		}
	}
}
//������������ 
void creatHuffmanTree(HuffmanTree HT,int n)
{
	int s1,s2;
	initHuffmanTree(HT,n);
	inputHuffmanTree(HT,n);
	for(int i=n+1;i<=2*n-1;i++)
	{
		select(HT,i-1,s1,s2);
		HT[i].weigth = HT[s1].weigth + HT[s2].weigth;
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].left = s1;
		HT[i].right = s2; 
	}
	
}
//����������� 
void printfHuffmanTree(HuffmanTree HT,int n)
{
	for(int i=1;i<=2*n-1;i++)
	{
		printf("�ڵ����:%d ",i);
		printf("�ڵ�Ȩ��:%d ",HT[i].weigth);
		printf("�ڵ�left:%d ",HT[i].left);
		printf("�ڵ�parent:%d ",HT[i].parent);
		printf("�ڵ�right:%d ",HT[i].right);
		printf("\n");
	}
}
int main(){
	int n;
	scanf("%d",&n);
	HuffmanTree HT;
	creatHuffmanTree(HT,n);
	printfHuffmanTree(HT,n);
	system("pause");
	return 0; 
}
