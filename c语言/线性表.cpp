#include <stdio.h>

struct student{
	char name;
	int num;
	float socre;
}stu[10];

void add(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%s %d %f",&stu[i].name,&stu[i].num,&stu[i].socre);
	}
	for(i=0;i<n;i++)
	{
		printf("%s %d %f",stu[i].name,stu[i].num,stu[i].socre);
		printf("\n");
	}
}
int main(){
	int m,i;
	scanf("%d",&m);
	add(m);
//	for(i=0;i<m;i++)
//	{
//		printf("%s %d %f",stu[i].name,stu[i].num,stu[i].socre);
//		printf("\n");
//	}
}
