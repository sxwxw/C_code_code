#include<stdio.h>
#include<stdlib.h>
int fun(int x[],int n)
{
	int i;
	int min=x[0];
	for(i=0;i<n;i++)
	{
		if(x[i]<min)
		{
			min=x[i];
		}
	}
	return min;
}
int main()
{
	int a[10],i,min;
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	for(i=0;i<10;i++)
		printf("%3d",a[i]);
	printf("\n");
	min=fun(a,10);
	printf("%d\n",min);
	system("pause");
}

