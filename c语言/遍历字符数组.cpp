#include <stdio.h>
int main()
{
	char a[100];
	int i=0;
	int j=0,k=0,g=0,l=0,f=0;
	gets(a);
	while(a[i]!='\0')
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			j++;
		}
		else if(a[i]<='z'&&a[i]>='a')
		{
			k++;
		}
		else if(a[i]<='Z'&&a[i]>='A')
		{
			g++;
		}
		else if(a[i]==32)
		{
			l++;
		}
		else
		{
			f++;
		}
		i++;
	}
	printf("%d\n%d\n%d\n%d\n",j,l,g+k,f);
} 
