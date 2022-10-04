#include <stdio.h>
struct people{
	int num;
	int same;
}; 
void jiao(struct people a2[],int l,int r){
	if(l>=r){
		return;
	}
	int left = l;
	int right = r;
	struct people index ;
	index.num = a2[(l+r)/2].num;
	int temp;
	while(left<=right){
		while(a2[left].num<index.num){
			left++;
		}
		while(a2[right].num>index.num){
			right--;
		}
		if(left<=right){
			temp = a2[left].num;
			a2[left].num= a2[right].num;
			a2[right].num=temp;
			left++;
			right--;
		}
	}
	if(l<right){
		jiao(a2,l,right);
	} 
	if(l<r){
		jiao(a2,left,r);	
	} 
}
int main(){
	int n,m,i,j,t;
	scanf("%d%d\n",&n,&m);
	struct people a1[n];
	struct people a2[m];
	for(i=0;i<n;i++){
		scanf("%d",&a1[i].num);
	}
	for(i=0;i<m;i++){
		scanf("%d",&a2[i].num);
	}
	jiao(a2,0,m-1);
	for(i=0;i<n;i++){
		int l = 0;
		int r = m-1;
		while(l<=r){
			int mid = (l+r)/2;
			if(a2[mid].num==a1[i].num){
				printf("%d ",a1[i].num);
				break;
			}
			else if(a2[mid].num<a1[i].num){
				l = mid+1;
			}else{
				r = mid -1;
			}
		}
	}
	return 0;
} 
