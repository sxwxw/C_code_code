#include <stdio.h>

int main()
{
	char a[100],c;
	int i,k=0;
	int j=0,n;
	gets(a);
		 	 
	scanf("%c",&c);
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]!=c)
		{
			a[k++]=a[i];
			
		}
	}
	a[k]='\0';
	puts(a);
}	

