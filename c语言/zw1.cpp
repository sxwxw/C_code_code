#include<stdio.h>
void read(int zw[50000],int l,int r)
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
int main()
{
	int i,t,j,l;
	
	scanf("%d",&t);
	double b[t];	
	for(i=0;i<t;i++)
	{
		long long int sum=0;
		long long int n=0;
		long long int k=0;
		scanf("%lld%lld",&n,&k);
		int a[n];
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[j]);
		}
		read(a,0,n-1);
		for(l=n-k;l<n;l++)
		{
			sum+=a[l];
		}
		printf("%d ",sum);
		b[i]=sum*1.0/k*1.0;
	}
	for(i=0;i<t;i++)
	{
		printf("%.6lf",b[i]);
		if(i<t-1)
		printf("\n");
	}
	return 0;
}

