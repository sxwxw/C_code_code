/*---------------------【程序设计】------------
功能：S = 3!+6!+9!+..+n!
n由主函数中输入.
n=6，则求解   3!+6!.

6
726

10
363606

20
6403681859461206

------------------------------*/
#include <stdio.h>
double fun(int n){

  /********** begin **********/
  int i;
  double he,sum=1;
  for(i=1;i<=n;i++)
  {
    sum*=i;	
  	if(i%3==0)
  	{
  	  he+=sum;
	}  
  	
  }
  return he;
  
  /********** end **********/
}
int main(){
   int n; 
  	
	scanf("%d", &n);
   printf("%.0lf\n",fun(n));

 	return 0;
  
}

