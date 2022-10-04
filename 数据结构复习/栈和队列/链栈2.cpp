#include <stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct node{
	int data;
	struct node* next;
}node;

node*creatTop(){
	node*s= (node*)malloc(sizeof(node));
	s->next = NULL;
	return s;
} 

void push(node*s,int v)
{
	if(s!=NULL)
	{
		node*p=(node*)malloc(sizeof(node));
		p->data = v;
		p->next = s->next;
		s->next = p;
	}
	else {
		printf("不为空栈"); 
	} 
}

void pop(node*s,int&e)
{
	if(s!=NULL)
	{
		node*m;
		m = s->next;
		s->next = m->next;
		e = m->data;
		free(m);
	}
} 

void ergodic(node*s){
	if(s!=NULL)
	{	
		node*h;
		h=s->next;
		while(h)
		{
			printf("遍历元素:%d\n",h->data);
			h=h->next;
		}	
	}else{
		printf("栈空"); 
	}
	
}

void getTop(node*s){
	if(s!=NULL)
	{
		printf("栈顶元素:%d\n",s->next->data);
	}
}
int main(){
	int a;
	node*s=creatTop();
	push(s,1);
	push(s,3);
	push(s,4);
	ergodic(s);
	getTop(s);
	printf("****\n");
	pop(s,a);//弹出一次 
	printf("%d\n",a);
	getTop(s);
	system("pause");
	return 0;
}
