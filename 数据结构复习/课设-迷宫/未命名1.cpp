#include<stdio.h>
struct sudent{
	int num;
}stu1,stu2,stu3;
int main(){
	
	stu1.num = 1;
	stu2.num = 2;
	stu3.num = 3;
	printf("%d\n%d\n%d\n",stu1.num,stu2.num,stu3.num);
	return 0;
}
