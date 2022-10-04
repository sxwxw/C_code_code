#include<stdio.h>
#include<string.h>

//typedef 重命名 typedef+类型+别名 
//如果想在定义结构体的时候定义变量就不能用typedef 
//将int重命名为abc 此时int ==abc 
//typedef int abc; 

/*常规定义结构体 */
typedef struct book{
	char title[10];
	char author[10];
}chongM;
//重命名了struct book为 chongM  book可删可不删 
int main(){
//	struct book类型的变量books 
	chongM books[10];
	strcpy(books[0].title,"'孙悟空'");
	strcpy(books[0].author,"'罗贯中'"); 
	int i;
	for(i=0;i<1;i++)
	{
		printf("%s%s",books[0].title,books[0].author);
	}
	/*
	abc s=10;
	printf("%d",s);
	*/
	/*结构体指针 
	chongM *b=&books[0];
	printf("%s",(*b).author);
	printf("%s",b->author);
	*/
	system("pause");
	return 0;
	return 0;
}
