#include <stdio.h>
int main()
{
	char a[100],b[100],c[100];
	gets(a);
	gets(b);
	int i,j,d;
	for(i=0;a[i]!='\0';i++)
	{
	    c[i]=a[i]; 
	}
	for(j=0;b[j]!='\0';j++)
	{
		c[i+j]=b[j];
	}
	puts(c);
}
