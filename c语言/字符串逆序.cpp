#include <stdio.h>
int main()
{
	char a[100];
	gets(a);
	int i,n=0,t;
	for(i=0;a[i]!='\0';i++)
	{
		n++; 
	 }
	 for(i=0;i<n;i++)
	 {
	 	t=a[i];
	 	a[i]=a[n-1];
	 	a[n-1]=t;
	 	n--; 
	  }
	  puts(a); 
} 
