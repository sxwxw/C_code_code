#include<stdio.h>
//void push(int a2,d){
//	sum += (a2+d);
//}
void add(int a1,int a2,int n){
	int d = a2 - a1;
	int a[n]={0},sum=0;
	a[0]=a1,a[1]=a2;
	for(int i=2;i<n;i++){
		a[i]=a[i-1]+d;
	} 
	for(int i=0;i<n;i++){
//		sum+=a[i];
		printf("%d\n",a[i]);
	}
//	printf("%d",sum);
}
int main(){
	int n,d,i,a1,a2;
	scanf("%d%d%d",&a1,&a2,&n);
	add(a1,a2,n);
//	printf("%d",sum);
	return 0;
}
