#include <stdio.h>
#include <math.h>
#include <string.h> 
#define N 100
/*
------
循环从1到某个数的平方的和 
------
int main()
{
	int k,i,sum=0;
	scanf("%d",&k);
	for(i=1;i<=k;i++)
	{
		sum+=pow(i,2);
	}
	printf("%d",sum);
 }
------
两百以内被3整除且个位数为6的数
------
int main()
{
	int i;
	
	for(i=1;i<=200;i++)
	{
		if(i%10==6&&i%3==0)
		{
			printf("%d\n",i);
		}
	}
    
 }
------
 100以内的整数和 
------
 int main()
{ 
   int i,sum=0;
   for(i=0;i<=100;i++)
   {
   	sum+=i;
	}   	
	printf("%d",sum); 
}	 
------
1到200 以被3除余2，且被5除余3.
------	 
int main()
{
	int i,k=0;
	for(i=1;i<=200;i++)
	{
		if(i%3==2&&i%5==3)
		{
			printf("%d\n",i);
			k++;
		}
	}
	printf("个数为：%d",k);
}	 	 
------
鸡兔同笼
------	 
int main()
{
	int x,y;
	for(x=0;x<100;x++)
	{
		y=100-x;
		
		if(x*4+y*2==274)
		{
			printf("兔为：%d鸡为：%d",x,y); 
		}	
		 
	}	
	
 } 
------
Π的近似值
------	 
int main()
{
	double sum=0,pi,c;
	int n;
	for(n=1;n<=100000;n++)
	{
		c=pow(-1.0,n+1)/(2*n-1);//公式 
		sum+=c;
	}
	pi=4*sum;
	printf("pi=%lf\n",pi);
	 }	 
------
水仙花数
------ 
int main()
{
	int i,g,s,b;
	
	for(i=100;i<=999;i++)
	{
	  g=i%10;
	  s=i/10%10;
	  b=i/100;
	  if(i==g*g*g+s*s*s+b*b*b)
	  {
	  	printf("%d\n",i);
	  }
	
	
	}
}	 	 
------
打印斐波拉契数列前20项及和
------ 
int main()
{
  int i,a[N]={0},sum=0,he=0;
  a[0]=1;
  a[1]=2;
  printf("%-6d%-6d",a[0],a[1]);
  for(i=2;i<20;i++)
  {
  	a[i]=a[i-2]+a[i-1];
  	sum+=a[i];
  	printf("%-6d",a[i]);
  	if(i%3==0)
  	printf("\n");
  	
  }
  he=1+2+sum;
  printf("前20项和为：%d",he);	 
}	 
------
while的1到100的和
------	 
int main()
{
	int i=1,sum=0;
	while(i<=100)
	{
		sum+=i;
		i=i+1;
	}
	printf("%d",sum);
}	 	 
------
年龄计算题
------ 
int main()
{
	int x=12,y=42,m;
	while(y!=2*x)
	{
		x++;
		y++;
	}
	m=x-12;
	printf("%d\n%d\n%d",x,m,y);
}	 	 
------
根据精度来计算圆周率的近似值
------	 
int main()
{
   double sum=0,pi,c=1,s=1;
   int n=1;
   while(fabs(c)>=1e-6)
   {
   	sum+=c;
   	s=-s;
   	n++;
   	c=s/(2*n-1);
   	
	}   	
	pi=4*sum;
	printf("pi=%lf\n",pi);
}
------
公鸡，母鸡，小鸡
------ 
int main()
{
   int g,m,x;
   for(g=0;g<20;g++)
   {
   	   for(m=0;m<33;m++)
   	   {
   	   	    x=100-g-m;
   	   	 
   	   	 	if(g*5+m*3+x/3==100&&x%3==0)
   	   	 	{
   	   	 		printf("公鸡%2d母鸡%2d小鸡%2d\n",g,m,x);
   	   	 		
				   
			}   
		}  
	}   	
}  
------
穷举法个，十，百位找水仙花数 
------
int main()
{
   int g,s,b,m;
   for(b=1;b<10;b++)
   {
   	for(s=0;s<10;s++)
   	{
   		for(g=0;g<10;g++)
   		{
   			m=b*100+s*10+g;
   			if(m==b*b*b+s*s*s+g*g*g)
   			{
   				printf("%4d\n",m);
   				
			   }
		   }
	   }
	   }	
}  
------
1到n的阶乘
------ 
int main()
{
	int i,n,p=1,sum=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		p*=i;
		sum+=p; 
	}
	printf("%d\n",sum);
 } 
------
左下角三角形
------ 
int main()
{
  int i,j,n;
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
  	for(j=1;j<=i;j++)
  	{
  		printf("*");
  		
	  }printf("\n");
	}  
}  
------
左上角三角形
------ 
int main()
{
	int i,j,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=n;j>=i;j--)
		{
			printf("*");
		}
		printf("\n");
	}
 } 
------
右上角三角形
------ 
int main()
{
	int i,j,n,m;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf(" ");
			
		}
		for(m=n;m>=i;m--)
		{
			printf("*");
		}
		printf("\n");
	}
 } 
------
右下角三角形
------ 
int main()
{
	int i,j,n,m;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=n;j>=i;j--)
		{
			printf(" ");
			
		}
		for(m=1;m<=i;m++)
		{
			printf("*");
		}
		printf("\n");
	}
 } 
------
猜数游戏
------ 
int main()
{
	int a,b,i,n;
	for(a=1;a<=9;a++)
	{
		for(b=0;b<=9;b++)
		{
			n=a*1000+a*100+b*10+b;
			for(i=1;i<1000;i++)
			{
				if(n==i*i)
				{
					printf("%d\n%d",n,i);
				}
			}
		}
	}
}
------
输入k个值并计算其正负数的个数
------ 
int main()
{
	int i=0,j=0,n=0,a[N],m,k;
	scanf("%d",&k);
	for(m=0;m<k;m++)
	{
		scanf("%d",&a[m]);
    }
    for(m=0;m<k;m++)
    {
	
		if(a[m]>0)
		{
			i++;
		}
		else if(a[m]<0)
		{
			j++;
		}
		else 
		{
			n++;
		}
	}
	
	printf("%d%d%d\n",i,j,n);
}
-------
一正一负计算分数和
------ 
int main()
{
	int i,m=1;
	double sum=0;
	for(i=1;i<=100;i++)
	{
		sum+=1.0*m/i;
		m=-m;
	}
	printf("%lf",sum);
 } 
------
求无理数e
------ 
int main()
{
	int i,j,n;
	double sum=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		j*=i;
		sum+=1.0*1/j;
		 
	}
	printf("%lf",sum+1);
 } 
------
求无理数最后一项小于1e-5(10的5次方)
------ 
int main()
{
    int i=1;
    double s=1,e=1;
    while(1/s>=1e-5)
    {
    	s*=i;
    	e+=1/s;
    	i++;
	}
	printf("%lf",e);
} 
------
最大公约数
------ 
int main()
{
	int i,m,n,k=0;
	scanf("%d%d",&m,&n);
	for(i=m;i>=1;i--)
	{
		if(m%i==0&&n%i==0)
		{
			k=i;
			break;
		}
	}
	printf("最公约数为：%d",k);
}
------
最小公倍数
------ 
int main()
{
    int i,m,n,k=0;
    int g;
	scanf("%d%d",&m,&n);
	for(i=m;i>=1;i--)
	{
		if(m%i==0&&n%i==0)
		{
			k=i;
			break;
		}
	}
	g=m*n/k;
	printf("%d",g);	
} 
------
循环次数未知求最高成绩
------ 
int main()
{
    int i=0,score,max=0;
	do{
		printf("请输入第%d个学生的成绩：",i+1);
		scanf("%d",&score);
		if(score>max)
		{
			max=score;
		}
		i++;
		
	}while(score>=0);
	printf("%d",max);	
} 
------
方程式求解
------ 
int main()
{
	int x,y;
	for(x=0;x<80;x++)
	{
		for(y=0;y<80;y++)
		{
			if(x*x+y*y==1989)
			{
				printf("%d %d\n",x,y);
			}
		}
	}
	
} 
------
判断素数
------ 
int main()
{
	int i,j,k=1;
	printf("请输入判断数:");
	scanf("%d",&j);
	for(i=2;i<=j-1;i++)
	{
		if(j%i==0)
		{
			k=0;
			break;
		}
	}	
	if(k=1)
	{
		printf("该数是素数"); 
	}
	else
	{
		printf("该数不是素数");
	 } 
	 
}
*/
int main()
{
	int i,sum=0,n,j,k,h=1;
    printf("请输入整数n:");
    scanf("%d",&n);
    for(j=2;j<=n;j++)
    {
    	k=sqrt((double)j);
    	for(i=2;i<=k;i++)
    	{
    		if(i%j==0)
    		{
    			h=0;
			    break;
			}
			if(h==1)
		{
			sum+=j;
		}
		
    	}	
			
			
			
		
	}
	printf("%d",sum);
 } 



























 	 	
