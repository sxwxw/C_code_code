#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�����ڵ�
typedef struct node {
	int data;
	struct node* next;
} node;

//����ջ
node*creatStack() {
	node*s = (node*)malloc(sizeof(node));
	if(s==NULL) {
		printf("��ջ");
	}
	s->next = NULL;
	return s;
}
//��ջ
void push(node*s,int e) {
	if(s!=NULL) {
		node*p = (node*)malloc(sizeof(node));
		p->data = e;
		p->next = s->next;
		s->next = p;
		/*
		*/
	} else {
		printf("��ջ");
	}
}
//����ջ
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
//��ջ
int pop(node*s,int &a) {
	if(s!=NULL) {
		node*h;
		h= s->next;
		s->next = h->next;
		a=h->data;
		free(h);
	} else {
		printf("��ջ");
	}
}
//ȡջ��Ԫ��
int getTop(node*s) {
	if(s!=NULL) {
		return s->next->data;
	}
}
//������
int main() {
	int sum=3,n;
	node * s= creatStack();
	printf("��ջԪ��");
	for(int i=1; i<=3; i++) {
		push(s,i);
		printf("%d",sum--);
	}
	printf("\n");
	printf("����Ԫ���ǣ�");
	TraveStack(s);
	printf("\n");
	printf("ջ��Ԫ���ǣ�%d\n",getTop(s));
	printf("***********************************************\n");
	printf("��ջԪ��");
	for(int i=0; i<2; i++) {
		int a;
		pop(s,a);
		printf("%d",a);
	}
	printf("\n");
	printf("����Ԫ���ǣ�");
	TraveStack(s);
	printf("\n");
	printf("ջ��Ԫ���ǣ�%d\n",getTop(s));
	system("pause");
	return 0;
}
