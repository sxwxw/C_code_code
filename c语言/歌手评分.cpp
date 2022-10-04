#include <stdio.h>
// 定义main函数
int main()
{
    // 请在此添加代码
    /********** Begin *********/
    /*int i,j,t;
    
    float a[7];
	float scorce=0,sum=0;
    for(i=0;i<7;i++)
    {
    	scanf("%f",&a[i]);
	}
	for(i=1;i<7;i++)
	{
		for(j=0;j<7-i;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j+1];
				a[j+1]=a[j];
				a[j]=t;
			}
		}
	}
	for(i=1;i<6;i++)
	{
		sum=sum+a[i];
	}	
	scorce=sum/5;	
	printf("%f",scorce);
	*/
	float a[7];
	int i,j;
	float max,min,sum=0,score=0;
	for(i=0;i<7;i++)
	{
		scanf("%f",&a[i]);
	}
	min=a[0];
	max=min;
	for(i=0;i<7;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
		if(a[i]<min)
		{
			min=a[i]; 
		}
	}
	for(i=0;i<7;i++)
	{
		sum+=a[i]; 
	}
	score=(sum-min-max)/5;
	printf("score=%.2f",score);
	
    /********** End **********/
    return 0;
}





































