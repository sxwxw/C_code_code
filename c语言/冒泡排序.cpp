#include <stdio.h>
#define N 10
int main()
{
	int i,j,k,a[N];
	for(i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
		
	}
	for(i=1;i<N;i++)
	{
		for(j=0;j<N-i;j++)
		{
			if(a[j]>a[j+1])
			{
				k=a[j];
				a[j]=a[j+1];
				a[j+1]=k;
			}
		}
		
	}
	for(i=0;i<N;i++)
	{    
		printf("%5d",a[i]);
	}    
 } 
