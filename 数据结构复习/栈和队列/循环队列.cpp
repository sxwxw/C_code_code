#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 5

//创建一个空队列 
typedef struct {
	int element[maxsize];
	int front;
	int rear;
}seqQue;

//初始化循环队列
void InitQue(seqQue* s){
	s->front = s->rear = 0; 
} 

//入队
void CreatQue(seqQue* s,int v){
	if((s->rear+1)%maxsize==s->front)
	{
		return; 
	}
	s->element[s->rear]=v;
	s->rear = (s->rear+1)%maxsize;
	return;
} 

//出队 
void popQue(seqQue*s,int &a){
	if(s->front==s->rear)
	{
		return; 
	}
	a=s->element[s->front];
	s->front = (s->front+1)%maxsize;
	return;
} 

//长度
int lengQue(seqQue*s){
	return s->rear-s->front;
} 
/*这是以浪费一个空间的代价实现的循环队列*/
int main(){
	int e,a,l;
	seqQue *s = (seqQue*)malloc(sizeof(seqQue));
	InitQue(s);
	for(int i=5;i>=1;i--)
	{
		CreatQue(s,i);
	}
	printf("长度:%d\n",lengQue(s));
	for(int i=0;i<4;i++)
	{
		popQue(s,a);
		printf("%d\n",a);
	}
	
	system("pause");
	return 0;
} 
