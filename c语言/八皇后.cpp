#include <stdio.h>
int ns,consts = 0;
int chess[14][14]={0};
int check(int row,int col){
	int i ,k;
	for(i=0;i<ns;i++){
		if(chess[i][col]==1){
			return 0;
		}
	}
	for(i=row,k=col;i>=0&&k>=0;i--,k--){
		if(chess[i][k]==1){
			return 0;
		}
	}
	for(i=row,k=col;i>=0&&k<ns;i--,k++){
		if(chess[i][k]==1){
			return 0;
		}
	}
	return 1;
}
void out(){
	int row,col;
	if(consts<3){
		for(row=0;row<ns;row++){
		for(col=0;col<ns;col++){
			if(chess[row][col]==1){
				printf("%d",col+1);
			}
		}
		row!=ns-1?printf(" "):printf("");
		}
		printf("\n");
	}
	
}
void find_queen(int row){
	int col;
	if(row>ns-1){
		out();
		consts++;
		return;
	}
	for(col=0;col<ns;col++){
		if(check(row,col)){
			chess[row][col]=1;
			find_queen(row+1);
			chess[row][col]=0;
		}
	}
}
int main(){
	scanf("%d",&ns);
	find_queen(0);
	printf("%d\n",consts);
	return 0;
} 
