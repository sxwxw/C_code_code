#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define inf '#' //定义权值最大值 
#define MAXVEX 10 //定义顶点数量的最大值 

struct MGraph {
	char Vertex[MAXVEX];//顶点数量 
	int arc[MAXVEX][MAXVEX];//邻接矩阵 
	int vexnum;//顶点的数量 
	int edgenum;//边的数量 
};

//创建图 
void Creat(MGraph &g)
{
	int i,j,k,w,h;
	printf("请输入顶点数:\n");
	scanf("%d",&g.vexnum);
	printf("请输入边数:\n");
	scanf("%d",&g.edgenum);
	printf("请输入顶点信息:\n");
	for(i=0;i<g.vexnum;i++)
	{
		scanf("%d",&g.Vertex[i]);//就是输入顶点的下标 
	} 
	//邻接矩阵初始化
	for(i=0;i<g.vexnum;i++)
	{
		for(j=0;j<g.vexnum;j++)
		{
			g.arc[i][j] = inf;//inf就是初始化的值,两边都没有连接 
		}
	} 
	//读入邻接矩阵信息
	for(k=0;k<g.edgenum;k++)
	{
		printf("请输入边(vi,vj)的下标i,j和权重w:");//这里相当于将两个顶点给连接上 
		scanf("%d%d%d",&i,&j,&w);
		g.arc[i][j] = w;
		g.arc[j][i] =  g.arc[i][j]; //无向图需要这一句，因为无向图是对称存在的 
	}
	 
}
//输出矩阵 
void Print(MGraph &g)//MGraph &g这里使用的是引用 “& ” 
{
	for(int i=0;i<g.vexnum;i++)//遍历顶点 
	{
		for(int j=0;j<g.vexnum;j++)
		{
			printf("%4d",g.arc[i][j]);
		}
		printf("\n");
	}
} 

int main(){
	MGraph mg;//定义一个结构体变量 
	Creat(mg);
	Print(mg);
	return 0;
}


