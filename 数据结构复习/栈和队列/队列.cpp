#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

//�����ڵ� 
typedef struct node {
	int data;
	struct node*next;
}node;

//�������� 
typedef struct queue{
	node*front;
	node*rear;
}quLink;

//��ʼ������ 
void intLink(quLink*s){
	s->front=(node*)malloc(sizeof(node));
	if(s->front!=NULL)
	{
		s->rear = s->front;
		s->front->next=NULL;
	}
}

//���
void creatLink(quLink*s,int v){
	node*p = (node*)malloc(sizeof(node));
	if(s->front!=NULL)
	{
		p->data = v;
		p->next = NULL;
		s->rear->next = p;
		s->rear= p;	
	}
} 
//���� 
void bian(quLink*s){
	if(s->front!=NULL||s->front!=s->rear)
	{
		node*m;
		m=s->front->next;
		while(m){
			printf("����Ԫ��:%d",m->data);
			m=m->next;
			printf("\n");
		}
	}
}
//����
void pop(quLink*s,int &e){
	if(s->front!=NULL||s->front!=s->rear)
	{
		node*t;
		t=s->front->next;
		s->front->next = t->next;
		e=t->data;
		free(t);
	} 
} 
int main(){
	quLink s;
	intLink(&s);
	int v,e;
	creatLink(&s,3);
	creatLink(&s,5);
	creatLink(&s,8);
	bi
	for(int i=0;i<3;i++)
	{
		pop(&s,e);
		printf("����Ԫ��:%d\n",e);
	}
	system("pause");
	return 0;
} 
