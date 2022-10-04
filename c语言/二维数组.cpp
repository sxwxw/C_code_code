#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define M 3
#define N 4
void fun(int tt[M][N],int pp[N])
{
	int a,b,max;
	for(a=0;a<N;a++)
	{
	    max=tt[0][a];
	    for(b=1;b<M;b++)
		{
			if(tt[b][a]>max)
			{
				
				max=tt[b][a];
			}	
		}
	   pp[a]=max;		
	}		
			
	    
	
	
	
	
}

main()
{
	int t[M][N]={{68,32,54,12},{14,24,88,58},{42,22,44,56}};
	int p[N],i,j,k;
	printf("the orginal data is:\n");
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		   printf("%6d",t[i][j]);
		printf("\n");    
	}
	fun(t,p);
	printf("\n the result is:\n");
	for(k=0;k<N;k++)
           printf("%4d",p[k]);
		printf("\n");
	system("pause");	
}
