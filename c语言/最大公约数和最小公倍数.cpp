#include <stdio.h>
int main()
{
	int a,b,c,m,n;
	scanf("%d%d",&a,&b);
	m=a;
	n=b;
	while(b!=0)
	{
		c=a%b;
		a=b;
		b=c;
	}
    printf("���Լ����%d\n",a);
	printf("��С��������%d\n",m*n/a); 
 } 
