#include<stdio.h>
#include <math.h> 
int main(){
	int i,j,n,x,y,k=1;
	scanf("%d",&n);
	int a[n][n];
	int t = ceil(1.0 *n/2);
	for(i=0;i<t;i++){
		for(int j=i;j<n-i;j++){
			a[i][j]=k++;
		}
		for(int j=i+1;j<n-i-1;j++){
			a[j][n-i-1] = k++;
		}
		for(int j=n-i-1;j>i;j--){
			a[n-i-1][j] = k++;
		}
		for(int j=n-i-1; j>i;j--){
			a[j][i] = k++;
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%3d",a[i][j]);
		}
		printf("\n");
	}
	return 0;
} 
