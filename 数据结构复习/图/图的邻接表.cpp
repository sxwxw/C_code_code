#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXNUM 100

//边表
struct EdgeNode {
	int adjvex;//节点的信息 
	int weight;//节点的权重 
	EdgeNode *next; //下一个节点 
}; 

//顶点
struct VexNode {
	int data;//节点信息 
	EdgeNode * first;//指向边表 
}; 

//邻接表
struct GraAdjList {
	VexNode AdjList[MAXNUM];//结构体数组 
	int vexnum;//顶点数目 
	int edgenum;//边 
}; 

//创建邻接表  
void Creat(GraAdjList &g)
{
	int i,j,k,w;
	EdgeNode*e = NULL;//创建两个指针 
	EdgeNode*q = NULL;
	printf("请输入顶点数和边数:");
	scanf("%d%d",&g.vexnum,&g.edgenum);
	printf("请输入顶点信息:");
	for(k=0;k<g.vexnum;k++)
	{
		scanf("%d",&g.AdjList[k].data);//0 1 2 3 
		g.AdjList[k].first = NULL;
	}
	for(k=0;k<g.edgenum;k++)//开始输入边表信息 
	{
		printf("请输入边(vi,vj)的下标i，j和权值w:");
		scanf("%d%d%d",&i,&j,&w);
		//有向图的建立
		e =  (EdgeNode*)malloc(sizeof(EdgeNode));
		e->adjvex = j;
		e->weight = w;
		e->next = g.AdjList[i].first;
		g.AdjList[i].first = e;//下一个节点就接在e的后面 
		//如果是无向图的还需以下语句
		q =  (EdgeNode*)malloc(sizeof(EdgeNode));
		q->adjvex = i;
		e->weight = w;
		q->next = g.AdjList[j].first;
		g.AdjList[j].first = q;
	 } 
}
//输出邻接表
void Print(GraAdjList &g) 
{
	printf("输出邻接表:");
	EdgeNode* p;
	for(int i=0;i<g.vexnum;i++)
	{
		printf("顶点:%d",g.AdjList[i].data);//先输出头节点 
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
