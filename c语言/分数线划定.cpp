#include <stdio.h>
#include <math.h>
struct stu{
	int num;
	int scroe;
};
void pai(struct stu*a,int n,int m){
	int i,j;
	struct stu t;
	struct stu s[n];
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(a[j].scroe<a[j+1].scroe){
				t = a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(a[j].scroe==a[j+1].scroe && a[j].num>a[j+1].num){
				t = a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	for(i=m-1;i<n;i++){
		if(a[i].scroe!=a[i+1].scroe){
			break;
		}else{
			m++;
		}
	}
	printf("%d %d\n",a[m-1].scroe,m);
	for(i=0;i<m;i++){
		printf("%d %d\n",a[i].num,a[i].scroe);
	}
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	m = floor( (double) m * 1.5);
	struct stu a[n];
	for(int i = 0;i < n;i++){
		scanf("%d%d",&a[i].num,&a[i].scroe);
	}
    pai(a,n,m); 
    return 0;
}
