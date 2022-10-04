/*---------------------【程序设计】------------
功能：S = 1+1/2-1/3+1/4+1/5-1/6......+1/n (两正一负交替)
编写函数求表达式的和（n的值由主函数输入）

3
1.166667

7
1.592857


10
1.706746

-----------------------------*/
#include <stdio.h>
double fun(int n){

  /********** begin **********/
  int i;
  double sum=0,he=0;
  double x;
  for(i=1;i<=n;i++)
  {
      if(i%3==0)
	  {
	  	sum+=(-1.0)/i;
	   } 
  	  else
  	    he+=1.0/i;
  	
  }
  x=sum+he;
  return x;
  
  
  /********** end **********/
}
int main(){

    int n; int s=0;
    scanf("%d", &n);
    printf("%lf\n",fun(n));
	return 0;  
}     


