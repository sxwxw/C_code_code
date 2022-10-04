#include<stdio.h>
long fun(long s,long t)
{
	long s1=10;
	s=s/10;
	t=s%10;
	
	while(s>0)
	{
		s=s/100;
		t=s%10*s1+t;
		s1=s1*10;
	} 
	return t;
}
int main()
{
	long s, t=0,m;
	printf("\nPlease enter s:");
	scanf("%ld",&s);
	m=fun(s,t);
	printf("The result is:%ld\n",m);
}

