#include <stdio.h>
int main(){
	int L,N,M;
	scanf("%d%d%d",&L,&N,&M);
	int a[50001];
	a[0] = 0;
	a[N+1]=L;
	for(int i =1;i<=N;i++){
		scanf("%d\n",&a[i]);
	}
	int l=0,r=L,c=0;
	while(l<r){
		int mind = (l+r)/2+1;
		int m=0,c=0;
		for(int i=1;i<=N+1;i++){
			if(a[i]-a[m]<mind){
				c++;
			}else{
				m = i;
			}
		}
		if(c>M){
			r = mind-1;
		}else{
			l = mind;
		}
	}
	printf("%d",r);
	return 0;
}
