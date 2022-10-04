/*有一分数序列：2/1，3/2，5/3，8/5，13/8，21/13…求出这个数列的前n项之和的整数部分。

n的值运行时通过键盘输入给定，并且n<=30。

输出值只保留整数（不要四舍五入）。

效果如下：

输入：20。

输出：32。*/
#include <stdio.h>
#define N 100
int main()
{
	int a[N],i,n,he=0;
	a[0]=1;
	a[1]=2;
	double sum=0;
	scanf("%d",&n);
	for(i=2;i<=n;i++)
	{
		a[i]=a[i-1]+a[i-2];
		sum+=1.0*a[i]/a[i-1];
	}
	he=sum+2;
	printf("%d",he);
	
}
