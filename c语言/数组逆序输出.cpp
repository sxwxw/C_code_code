#include <stdio.h>
#define N 10

void  fun(int arr[],int n)
{
  	/********** Begin **********/
  int k,j=0,b[n],m;
  for(m=0;m<n;m++)
  {
  	b[m]=arr[m];
  }
  for(k=n-1;k>=0;k--)
  {
  	arr[k]=b[j];
  	j++;
  }
  
     
   
    
    
	/**********  End  **********/
}

int main()
{
	int a[N],i;
	for(i=0;i<N;i++)
	 scanf("%d",&a[i]);
	fun(a,10);
	for(i=0;i<N;i++)
	 printf("%d ",a[i]);
	return 0;
}

