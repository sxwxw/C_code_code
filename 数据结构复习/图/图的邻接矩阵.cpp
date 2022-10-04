#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define inf '#' //����Ȩֵ���ֵ 
#define MAXVEX 10 //���嶥�����������ֵ 

struct MGraph {
	char Vertex[MAXVEX];//�������� 
	int arc[MAXVEX][MAXVEX];//�ڽӾ��� 
	int vexnum;//��������� 
	int edgenum;//�ߵ����� 
};

//����ͼ 
void Creat(MGraph &g)
{
	int i,j,k,w,h;
	printf("�����붥����:\n");
	scanf("%d",&g.vexnum);
	printf("���������:\n");
	scanf("%d",&g.edgenum);
	printf("�����붥����Ϣ:\n");
	for(i=0;i<g.vexnum;i++)
	{
		scanf("%d",&g.Vertex[i]);//�������붥����±� 
	} 
	//�ڽӾ����ʼ��
	for(i=0;i<g.vexnum;i++)
	{
		for(j=0;j<g.vexnum;j++)
		{
			g.arc[i][j] = inf;//inf���ǳ�ʼ����ֵ,���߶�û������ 
		}
	} 
	//�����ڽӾ�����Ϣ
	for(k=0;k<g.edgenum;k++)
	{
		printf("�������(vi,vj)���±�i,j��Ȩ��w:");//�����൱�ڽ���������������� 
		scanf("%d%d%d",&i,&j,&w);
		g.arc[i][j] = w;
		g.arc[j][i] =  g.arc[i][j]; //����ͼ��Ҫ��һ�䣬��Ϊ����ͼ�ǶԳƴ��ڵ� 
	}
	 
}
//������� 
void Print(MGraph &g)//MGraph &g����ʹ�õ������� ��& �� 
{
	for(int i=0;i<g.vexnum;i++)//�������� 
	{
		for(int j=0;j<g.vexnum;j++)
		{
			printf("%4d",g.arc[i][j]);
		}
		printf("\n");
	}
} 

int main(){
	MGraph mg;//����һ���ṹ����� 
	Creat(mg);
	Print(mg);
	return 0;
}


