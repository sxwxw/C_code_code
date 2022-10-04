#include <stdio.h>
#include <math.h>
int IsValid( double a, double b, double c );
void JudgeShape( double a, double b, double c );
double Area( double a, double b, double c );
int main()
{
	double a, b, c, s, area;
	scanf("%lf%lf%lf", &a, &b, &c);
	if( IsValid( a, b, c ) )
	{
		JudgeShape ( a, b, c);
		area  = Area( a, b, c);
		
		printf("三角形的面积是：%f", area );
	}
	else
	{
		printf("输入的三条边无法组成三角形");
	}
	
	return 0;
}
int IsValid( double a, double b, double c)
{
	if( a + b <= c )
		return 0;
	if( a + c <= b )
		return 0;
	if( b + c <= a )
		return 0;
	return 1;	 
} 
void JudgeShape( double a, double b, double c )
{
	/********** Begin *********/
	int x;
	if(a>b)
	{
		x=a+b;
		a=x-b;
		b=x-a;
	}
	if(a>c)
	{
		x=a+c;
		a=x-c;
		c=x-a;
	}
	if(b>c)
	{
		x=b+c;
		b=x-c;
		c=x-b;
	}
	if(a*a+b*b==c*c)
	{
		printf("直角三角形\n"); 
	}
	if(a*a+b*b>c*c)
	{
		printf("锐角三角形\n"); 
	}
	if(a*a+b*b<c*c)
	{
		printf("钝角三角形\n");
	}
	/********** End **********/
}
double Area( double a, double b, double c )
{
	/********** Begin *********/
	int p,s;
	p=(a+b+c)/2;
	s=sqrt(p*(p-a)*(p-b)*(p-c));
	return s;
	/********** End **********/
	
}
