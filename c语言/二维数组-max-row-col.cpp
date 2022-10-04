#include <stdio.h>
int main()
{
	int a[3][4],i,j;
	int max,row=0,col=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	max=a[0][0];
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			if(a[i][j]>max)
			{
				max=a[i][j];
				row=i;
				col=j;
			}
		}
	}
	printf("%d%d%d",max,row,col);
}
