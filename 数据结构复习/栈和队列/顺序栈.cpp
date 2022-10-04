#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#define maxsize 50
typedef int detatype; 
typedef struct {
	detatype data[maxsize];
	int top;
}SqStack;

//初始化栈  
void initstack(SqStack*st)
{
	st->top = -1;
}
//进栈
void  push(SqStack*st)
{
	int i;
	if(st->top==maxsize-1)
	{
		printf("栈满");
		return; 
	}
	for(i=1;i<=10;i++)
	{
		st->top++;
		st->data[st->top] = i;
	}
	return;
}
//出栈
void pop(SqStack*st)
{
	int num;
	if(st->top==-1)
	{
		printf("空栈");
		return; 
	}else {
		num = st->data[st->top];
		printf("%d",num);
		st->top--;
	}
}
//打印
void prints(SqStack*st){
	if(st->top==-1)
	{
		printf("空栈");
		return; 
	}
	int n;
	n=st->top;
	while(n!=0)
	{
		printf("%d",st->data[n]);
		n--;
	}
} 
int main(){
	SqStack S;//定义变量其实就是分配了内存空间，直接定义指针并没有分配内存空间
	/*SqStack*S;
	S = (SqStack *)malloc(sizeof(SqStack));
	*/
	initstack(&S);
	push(&S);
	pop(&S);
	prints(&S);//出栈后栈就空了，打印则是遍历栈 
	system("pause");
	return 0;
} 
