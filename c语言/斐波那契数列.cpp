//================The sum of the loop structure========================== 

/*--------------------Round 5-----------
s=1+2+3+5+8+13+...+n
Write a function to calculate the sum S of the first n terms and return.
n is passed in by the main function

NOTE: No need to write main function!!!

Example:  n = 5, the calculation result is 19
 
TestCase:

5
5
Fibo=19

43
43
Fibo=1836311901


44
44
Fibo=2971215071

45
45
Fibo=4807526974


*/

#include <stdio.h>
#include <math.h>

//s=1+2+3+5+8+13+...+
double fiboSum(int n){

  /********** begin **********/
  int a[100],i;
  double he=0,sum=0;
  a[0]=1;
  a[1]=2;
  for(i=2;i<n;i++)
  {
  	a[i]=a[i-1]+a[i-2];
  	sum+=a[i];
  }
  he=sum+3;
  
  return he;
  /**********  end  **********/
}
int main(){
	int n;
	scanf("%d", &n);
	printf("%d\n", n);
   printf("Fibo=%.0lf\n", fiboSum(n));
	return 0;  
}     

