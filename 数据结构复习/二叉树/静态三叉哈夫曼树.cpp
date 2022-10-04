#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define N 20
#define M 2*N-1
#define MAXSUM 99999

//定义节点 
typedef struct{
	int weigth;
	int parent,left,right;
}HTNode,HuffmanTree[M+1];

//初始化数组 
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

//输入每个结点的权重 
void inputHuffmanTree(HuffmanTree HT,int n)
{
	int i,w;
	printf("输入权值:");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&w);
		HT[i].weigth = w;
	}
}
//找出节点中权重最小的两个节点
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
//构建哈夫曼树 
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
//输出哈夫曼树 
void printfHuffmanTree(HuffmanTree HT,int n)
{
	for(int i=1;i<=2*n-1;i++)
	{
		printf("节点序号:%d ",i);
		printf("节点权重:%d ",HT[i].weigth);
		printf("节点left:%d ",HT[i].left);
		printf("节点parent:%d ",HT[i].parent);
		printf("节点right:%d ",HT[i].right);
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
