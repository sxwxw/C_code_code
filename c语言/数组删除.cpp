#include <stdio.h>
#define N 4 
int main()
{
	int a[N];
	int i,c,k=0;
	int j=0;
	for(i=0;i<N;i++)
	{
	  scanf("%d",&a[i]);
	}	 
	scanf("%d",&c);
	for(i=0;i<N;i++)
	{
		if(a[i]!=c)
		{
			a[k++]=a[i];
			j++;
		}
	}
	for(k=0;k<j;k++)
	{
		
		printf("%d",a[k]);
	}
}	

	
	
	

