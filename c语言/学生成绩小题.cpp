#include <stdio.h>
int main()
{
	float a[30];int i;
	double sum=0,p=0,n,b=0;
	printf("the number of students:");
	scanf("%lf",&n);
	printf("the scores:");
	for(i=0;i<n;i++)
	{
		scanf("%f",&a[i]);
	}
	if(n>0)
	{
		for(i=0;i<n;i++)
		{
			sum+=a[i];
			
		 }
		 p=1.0*sum/n;
		 printf("average=%.2lf",p); 
		
	}
	else
	{
		printf("average=%.2lf",b);
	}
	
	
 } 
