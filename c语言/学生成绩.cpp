#include<Stdio.h>
#define M 10000 
struct student{
	int name;
	float score;
}stu;

int main(){
	int i,n;
	struct student stu[M];
	scanf("%d",&n);
	printf("±àºÅ   ³É¼¨\n");
	for(i=0;i<n;i++)
	{
		scanf("%d%f",&stu.name,&stu.score);
	}
	for(i=0;i<n;i++)
	{
		printf("%d%f",stu.name,stu.score);
	}
}
