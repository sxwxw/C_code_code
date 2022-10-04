#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#define maxsize 50
typedef int detatype; 
typedef struct {
	detatype data[maxsize];
	int top;
}SqStack;

//��ʼ��ջ  
void initstack(SqStack*st)
{
	st->top = -1;
}
//��ջ
void  push(SqStack*st)
{
	int i;
	if(st->top==maxsize-1)
	{
		printf("ջ��");
		return; 
	}
	for(i=1;i<=10;i++)
	{
		st->top++;
		st->data[st->top] = i;
	}
	return;
}
//��ջ
void pop(SqStack*st)
{
	int num;
	if(st->top==-1)
	{
		printf("��ջ");
		return; 
	}else {
		num = st->data[st->top];
		printf("%d",num);
		st->top--;
	}
}
//��ӡ
void prints(SqStack*st){
	if(st->top==-1)
	{
		printf("��ջ");
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
	SqStack S;//���������ʵ���Ƿ������ڴ�ռ䣬ֱ�Ӷ���ָ�벢û�з����ڴ�ռ�
	/*SqStack*S;
	S = (SqStack *)malloc(sizeof(SqStack));
	*/
	initstack(&S);
	push(&S);
	pop(&S);
	prints(&S);//��ջ��ջ�Ϳ��ˣ���ӡ���Ǳ���ջ 
	system("pause");
	return 0;
} 
