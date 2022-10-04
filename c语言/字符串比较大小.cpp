#include <stdio.h>
int main()
{
	int i,j;
	int n=0,m=0;
	char a[100],b[100],c[100];
	gets(a);
	gets(b);
	for(i=0;a[i]!='\0';i++)
	{
		n=i;
	}
	for(i=0;a[i]!='\0';i++)
	{
		m=i;
	}
	while(a[i]!='\0'&&b[i]!='\0')
	{
		if(a[i]==b[i])
		{
			for(i=0;a[i]!='\0';i++)
			{
				printf("%c",a[i]);
			}
		}
		else if(a[i]>b[i])
		{
			for(i=0;a[i]!='\0';i++)
			{
				c[i]=a[i];
			}
			for(i=0;b[j]!='\0';j++)
			{
				c[i+j]=b[j];
			}
			for(i=0;a[i]!='\0';i++)
			{
				printf("%c",c[i]);
			}
		}
		else
		{
			for(i=0;a[i]!='\0';i++)
			{
				c[i]=a[i];
			}
			for(i=0;b[j]!='\0';j++)
			{
				c[i+j]=b[j];
			}
			for(i=0;a[i]!='\0';i++)
			{
				printf("%c",c[i]);
			}
		}
		
		
	}
	
}
