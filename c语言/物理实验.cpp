#include <stdio.h>
#include <math.h>
int main()
{
	double d,h,v,p,m;
	scanf("%lf%lf",&d,&h);
	d=d*(0.001);
	h=h*(0.001);
	v=0.25*3.14592653589*pow(d,2)*h;
	printf("%lf\n",v);
	p=(0.051)/v;
	printf("%lf",p);
	return 0;
}
