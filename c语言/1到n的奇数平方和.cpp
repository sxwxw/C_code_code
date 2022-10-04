#include<stdio.h>
#include<string.h>
int main()
{
	char a[80],b[80],c[80],d[80];
	int i,j,index=0;
	scanf("%s%s",&a,&b);
	int l = strlen(a);
	int n = strlen(b);
	for(i=0;i<l;i++){
		for(j=1;j<l;j++){
			if(a[i]==a[j+i]){
				a[j+i]='*';
			}
		}
	}
	for(i=0;i<l;i++){
		if(a[i]!='*'){
			c[index]=a[i];
			++index;
		}
	}
	int m = strlen(c);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(b[i]==c[j]){
				c[j]='*';
			}
		}
	}
	index = 0;
	for(i=0;i<m;i++){
		if(c[i]!='*'){
			d[index]=c[i];
			++index;
		}
	}
	int dl = strlen(d);
	for(i=0;i<dl;i++){
		if(d[i]>=97 && d[i]!=95){
			d[i]=d[i]-32;
		}
		if(d[i]>=48||d[i]<=57){
			d[i]=d[i];	
		}
		
	}
	printf("%s",d);
	return 0;
}    

