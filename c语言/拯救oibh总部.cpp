#include <stdio.h>
int main(){
	int x,y,i,j;
	scanf("%d%d\n",&x,&y);
	int a[x][y];
	for(i=0;i<x;i++){
		scanf("%s\n",&a[i]);
	} 
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			if(a[i][j]=="*"){
				
			}
		}
	}
	printf("_______________________\n");
	for(i=0;i<x;i++){
		printf("%s\n",a[i]);
	} 
	return 0;
}
