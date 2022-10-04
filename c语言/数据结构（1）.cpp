#include <stdio.h>
int main()
{
	int i, j;
	float a[4][4], sum = 0;
	
	/********** Begin *********/
	
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
		{
			scanf("%f",&a[i][j]);
			}	
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
		{
			if(i==j||i+j==3)
			{
				sum+=a[i][j];
			}
		}	
	/********** End **********/
	printf("sum=%f", sum );
	return 0;
}

