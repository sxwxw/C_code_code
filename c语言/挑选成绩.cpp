#include<stdio.h>
	int w1[1000],w2[1000],s[1000];
void read(int zw[],int l,int r)
{
	if(l>=r){
		return;
	}
	int left=l;
	int right=r;
	int mid=(left+right)/2;
	int temp;
	while(left<=right)
	{
		while(zw[left]<zw[mid])
		left++;	
		while(zw[right]>zw[mid])
		right--;
		if(left<=right)
		{
			temp=zw[left];
			zw[left]=zw[right];
			zw[right]=temp;
			left++;
			right--;
		}
		
	}
	if(l<right) read(zw,l,right);
	if(l<r) read(zw,left,r);
}
void show(int w1[],int w2[],int l,int n,int r)
{
	int x,y;
	for(x=0;x<n;x++)
	{
		int left=0;
		int right=r-1;
		while(left<=right){
			int mid=(left+right)/2;
			if(w1[x]==w2[mid]){
				printf("%d ",w1[x]);
				break;
			}
			else if(w1[x]<w2[mid]){
				right=mid-1;
			}else{
				left=mid+1;
			}	
		}
	}
}
int main()
{
	int i,j;
	int n,m;
	int a=0;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&w1[i]);
	}
	for(j=0;j<m;j++)
	{
		scanf("%lld",&w2[j]);
	}
	read(w2,0,m-1);
	show(w1,w2,0,n,m-1);
	return 0;
}

