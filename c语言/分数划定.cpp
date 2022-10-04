#include<stdio.h>
#include<math.h>
struct people{
	int num;
	int score;
};
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	m = floor(m*1.5);
	printf("%d",m);
	people stu[n];
	for(int i=0;i<n;i++){
		scanf("%d%d",&stu[i].num,&stu[i].score);
	} 
	people min = stu[0];
	people temp;
	for(int i=1;i<n;i++){
		if(stu[i].score>min.score){
			temp = stu[i];
			stu[i]=min;
			min = temp;
		}
	}
	printf("*******");
	for(int i=0;i<n;i++){
		printf("%d %d\n",stu[i].num,stu[i].score);
	} 
	return 0;
}
