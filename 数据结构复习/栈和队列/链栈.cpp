#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//创建节点
typedef struct node {
	int data;
	struct node* next;
} node;

//创建栈
node*creatStack() {
	node*s = (node*)malloc(sizeof(node));
	if(s==NULL) {
		printf("空栈");
	}
	s->next = NULL;
	return s;
}
//进栈
void push(node*s,int e) {
	if(s!=NULL) {
		node*p = (node*)malloc(sizeof(node));
		p->data = e;
		p->next = s->next;
		s->next = p;
		/*
		*/
	} else {
		printf("空栈");
	}
}
//遍历栈
void TraveStack(node*s) {
	if(s!=NULL) {
		node*m;
		m=s->next;
		while(m) {
			printf("%d",m->data);
			m=m->next;
		}
	}
}
//出栈
int pop(node*s,int &a) {
	if(s!=NULL) {
		node*h;
		h= s->next;
		s->next = h->next;
		a=h->data;
		free(h);
	} else {
		printf("空栈");
	}
}
//取栈顶元素
int getTop(node*s) {
	if(s!=NULL) {
		return s->next->data;
	}
}
//主函数
int main() {
	int sum=3,n;
	node * s= creatStack();
	printf("入栈元素");
	for(int i=1; i<=3; i++) {
		push(s,i);
		printf("%d",sum--);
	}
	printf("\n");
	printf("遍历元素是：");
	TraveStack(s);
	printf("\n");
	printf("栈顶元素是：%d\n",getTop(s));
	printf("***********************************************\n");
	printf("出栈元素");
	for(int i=0; i<2; i++) {
		int a;
		pop(s,a);
		printf("%d",a);
	}
	printf("\n");
	printf("遍历元素是：");
	TraveStack(s);
	printf("\n");
	printf("栈顶元素是：%d\n",getTop(s));
	system("pause");
	return 0;
}
