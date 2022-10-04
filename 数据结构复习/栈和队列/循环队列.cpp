#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 5

//����һ���ն��� 
typedef struct {
	int element[maxsize];
	int front;
	int rear;
}seqQue;

//��ʼ��ѭ������
void InitQue(seqQue* s){
	s->front = s->rear = 0; 
} 

//���
void CreatQue(seqQue* s,int v){
	if((s->rear+1)%maxsize==s->front)
	{
		return; 
	}
	s->element[s->rear]=v;
	s->rear = (s->rear+1)%maxsize;
	return;
} 

//���� 
void popQue(seqQue*s,int &a){
	if(s->front==s->rear)
	{
		return; 
	}
	a=s->element[s->front];
	s->front = (s->front+1)%maxsize;
	return;
} 

//����
int lengQue(seqQue*s){
	return s->rear-s->front;
} 
/*�������˷�һ���ռ�Ĵ���ʵ�ֵ�ѭ������*/
int main(){
	int e,a,l;
	seqQue *s = (seqQue*)malloc(sizeof(seqQue));
	InitQue(s);
	for(int i=5;i>=1;i--)
	{
		CreatQue(s,i);
	}
	printf("����:%d\n",lengQue(s));
	for(int i=0;i<4;i++)
	{
		popQue(s,a);
		printf("%d\n",a);
	}
	
	system("pause");
	return 0;
} 
