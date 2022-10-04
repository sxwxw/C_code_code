#include<stdio.h>
int main()
{
	float i,s=0;
	for(i=1;i<=5;i++)
	{
		scanf("%f",&i);
		s=s+i;
	}
	s=1.0*s/5;
	printf("%f",s);
	return 0;
}

