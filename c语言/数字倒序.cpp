#include<stdio.h>
/*int reverse(int x[],int n)//�β�xΪָ������
{
	int temp,i,j,m;
	m=(n-1)/2;
	for(i=0;i<=m;i++)
    {
    	j=n-1-i;
    	temp=x[i];
    	x[i]=x[j];
    	x[j]=temp;
	}
}
*/
int max,min;
void reverse(int *x,int n)//�β�x��Ϊָ����� 
{
	int temp,*i,*j,m,*p;
	m=(n-1)/2;
	i=x;                 //iָ������ĵ�һ��Ԫ�� 
	j=x+n-1;             //jָ�������������һ��Ԫ�� 
	p=x+m;               //ָ���м䣬��� 
	for(;i<=p;i++,j--)
	{
		temp=*i;
		*i=*j;
		*j=temp;
	}
	
}
int math(int *x,int n)
{
	int *p,*i;
	i=x;
	p=x+n-1;
	min=max=*i;
	for(;i<=p;i++)
	{
		if(*i<min)
		{
			min=*i;
		}
		if(*i>max)
		{
			max=*i;
		}
	}
	
}
int main()
{
	int i,a[10]={1,2,3,4,5,6,7,8,9,0};
	for(i=0;i<10;i++)
	{
		printf("%d",a[i]);
	}
	printf("\n");
	reverse(a,10);
	for(i=0;i<10;i++)
	{
		printf("%d",a[i]);
	}
	math(a,10);
	printf("\n");
	printf("min=%dmax=%d",min,max);
} 	
	

	
	
 
