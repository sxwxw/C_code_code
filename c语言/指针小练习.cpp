#include <stdio.h>

	int reserva(int* x,int n)
	{
		int* p,temp,*i,*j,m;
		m=(n-1)/2;
		i=x;
		j=x-1+n;
		p=x+m;
		for(;i<=p;i++,j--)
		{
			temp=*i;
			*i=*j;
			*j=temp;
		}
	}
int main ()
{
	int i,a[10]={1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,0};
	reserva(a,10);
	for(i=0;i<10;i++)
	{
		printf("%d",a[i]);
	}
}	
	
  
