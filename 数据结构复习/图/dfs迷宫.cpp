#include <stdio.h>

int p, q, min=999;
int a[100][100];//地图  1->空，2->地
int v[100][100];//0->未访问,1->已访问 
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
void dfs(int x,int y,int step)
{
	if(x==p && y==q)
	{
		if(step < min)
		{
			min = step;
		}
		return;
	}
	//顺时针试探
	for(int k = 0;k<=3;k++)
	{
		int tx, ty;
		tx = x + dx[k];
		ty = y + dy[k];
		if(a[tx][ty] ==1 && v[tx][ty]==0)
		{
			v[tx][ty] = 1;
			dfs(tx,ty,step+1);
			v[tx][ty] = 0;
		}
	}
	/*
	//右 
	if(a[x][y+1]==1 && v[x][y+1] ==0)
	{
		v[x][y+1] = 1;
		dfs(x,y+1,step+1);
		v[x][y+1] = 0;
	} 
	//下 
	if(a[x+1][y]==1 && v[x+1][y] ==0)
	{
		v[x+1][y] = 1;
		dfs(x+1,y,step+1);
		v[x+1][y] = 0;
	} 
	//左 
	if(a[x][y-1]==1 && v[x][y-1] ==0)
	{
		v[x][y-1] = 1;
		dfs(x,y-1,step+1);
		v[x][y-1] = 0;
	} 
	//上 
	if(a[x-1][y+1]==1 && v[x-1][y] ==0)
	{
		v[x-1][y] = 1;
		dfs(x-1,y,step+1);
		v[x-1][y] = 0;
	} */
	return; 
	 
} 
/*
5 4
1 1 2 1
1 1 1 1
1 1 2 1
1 2 1 1 
1 1 1 2 
1 1 4 3
*/
int main()
{
	int m,n,my_x,my_y;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);//1->空，2->地
		}
	}
	scanf("%d%d%d%d",&my_x,&my_y,&p,&q);
	v[my_x][my_y] = 1;
	dfs(my_x,my_y,0);
	printf("%d",min);
	return 0;
}
