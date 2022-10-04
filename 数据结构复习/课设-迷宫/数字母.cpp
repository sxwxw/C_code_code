#include <stdio.h> 
#include <string.h> 
int main(){
	int t=0,i=0,h=0;
	int base,he,m;
	scanf("%d",&t);
	int a[t][5];
	for(i=0;i<t;i++){
		for(h=0;h<5;h++){
			scanf("%d",&a[i][h]);
		}
	}
	for(i=0;i<t;i++){
		if(a[i][0]==1){
			base = a[i][2]*a[i][4];
			he = a[i][1]*(base/a[i][2])+(base/a[i][4])*a[i][3];
			m = base<he ?base:he;
			while(1){
				if(base%m==0&&he%m==0){
					break;
				}
				m--;
			}
			printf("%d",m);
			printf("%d/%d\n",he/m,base/m);
		}
		if(a[i][0]==0){
			base = a[i][2]*a[i][4];
			he = a[i][1]*(base/a[i][2])-(base/a[i][4])*a[i][3];
			if(he==0){
				printf("0/1\n");
				return 0;
			}else{
				m = base<he ?base:he;
				while(1){
					if(base%m==0&&he%m==0){
						break;
					}
					m--;
				}	
			}
			printf("%d/%d\n",he/m,base/m);
		}
	}
	return 0;
}
//#include<stdio.h>
//int lcm(int a,int b)
//{
//	int temp;
//	if(a<b)
//	{
//		temp=a;
//		a=b;
//		b=temp;
//	}
//	if(a%b==0)
//	return a;
//	else
//	return a*b;
//}
//int main()
//{
//	int y=0;
//	int T = 0;
//	int i = 0;
//    scanf("%d",&T);
//    int arr[T][5];
//    int j,k;
//    for(j=0;j<T;j++)
//    {
//    	for(k=0;k<5;k++)
//    	{
//    		scanf("%d",&arr[j][k]);
//		}
//	}
//	int x1,x2,x;
//	for(j=0;j<T;j++)
//	{
//		if(arr[j][0]==1)
// 		{
// 		    y=lcm(arr[j][2],arr[j][4]);
// 		    x1=arr[j][1]*(y/arr[j][2]);
// 		    x2=arr[j][3]*(y/arr[j][4]);
//			x=x1+x2;
////			printf("%d/%d",x,y);
//	     }
//   		 if(arr[j][0]==0)
// 		{
// 		    y=lcm(arr[j][2],arr[j][4]);
// 		    x1=arr[j][1]*(y/arr[j][2]);
// 		    x2=arr[j][3]*(y/arr[j][4]);
//			x=x1-x2;
//			if(x==0)
//			{
//				y=1;
//			}
//		 }
//
//			if(y<=x)
// 		    {
//				
//			}else{ 
//			  printf("%d/%d\n",x,y);
//			}
//				
//		 }
//	return 0;	
//}
