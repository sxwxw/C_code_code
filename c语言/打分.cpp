#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int a[n],t;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j]<=a[j+1]){
				t = a[j+1];
				a[j+1]=a[j];
				a[j]=t;
			}
		}
	}
	double sum =0;
	for(int i=0;i<n-1;i++){
		if(i!=0){
			sum+=a[i];
		}
	}
	printf("%.2lf",sum/(n-2));
	return 0;
} 
