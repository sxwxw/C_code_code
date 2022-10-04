#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXNUM 100

//�߱�
struct EdgeNode {
	int adjvex;//�ڵ����Ϣ 
	int weight;//�ڵ��Ȩ�� 
	EdgeNode *next; //��һ���ڵ� 
}; 

//����
struct VexNode {
	int data;//�ڵ���Ϣ 
	EdgeNode * first;//ָ��߱� 
}; 

//�ڽӱ�
struct GraAdjList {
	VexNode AdjList[MAXNUM];//�ṹ������ 
	int vexnum;//������Ŀ 
	int edgenum;//�� 
}; 

//�����ڽӱ�  
void Creat(GraAdjList &g)
{
	int i,j,k,w;
	EdgeNode*e = NULL;//��������ָ�� 
	EdgeNode*q = NULL;
	printf("�����붥�����ͱ���:");
	scanf("%d%d",&g.vexnum,&g.edgenum);
	printf("�����붥����Ϣ:");
	for(k=0;k<g.vexnum;k++)
	{
		scanf("%d",&g.AdjList[k].data);//0 1 2 3 
		g.AdjList[k].first = NULL;
	}
	for(k=0;k<g.edgenum;k++)//��ʼ����߱���Ϣ 
	{
		printf("�������(vi,vj)���±�i��j��Ȩֵw:");
		scanf("%d%d%d",&i,&j,&w);
		//����ͼ�Ľ���
		e =  (EdgeNode*)malloc(sizeof(EdgeNode));
		e->adjvex = j;
		e->weight = w;
		e->next = g.AdjList[i].first;
		g.AdjList[i].first = e;//��һ���ڵ�ͽ���e�ĺ��� 
		//���������ͼ�Ļ����������
		q =  (EdgeNode*)malloc(sizeof(EdgeNode));
		q->adjvex = i;
		e->weight = w;
		q->next = g.AdjList[j].first;
		g.AdjList[j].first = q;
	 } 
}
//����ڽӱ�
void Print(GraAdjList &g) 
{
	printf("����ڽӱ�:");
	EdgeNode* p;
	for(int i=0;i<g.vexnum;i++)
	{
		printf("����:%d",g.AdjList[i].data);//�����ͷ�ڵ� 
		for(p = g.AdjList[i].first;p;p = p->next)
		{
			printf("%d(%d)",p->adjvex,p->weight);
			printf(" ");
		}
		printf("\n");
	}
}
int main(){
	GraAdjList g;
	Creat(g);
	Print(g);
	return 0;
}
