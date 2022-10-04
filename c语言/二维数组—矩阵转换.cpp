#include <stdio.h>
#define M  3 
#define N  4
int main()
{
	int i,j,a[M][N],b[N][M];
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%d",&a[i][j]);
			b[j][i]=a[i][j]; 
		}
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			
			printf("%6d",b[i][j]);
			
		}
	}
 }
 
