#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 typedef struct node {
 	int num;
 	struct node*next;
 }node;
 
int main()
{
	int arr[]={1,2,3};
	int i;
	int n =sizeof(arr)/sizeof(int);
//	����ͷָ����������ָ���βָ�� 
	node *head,*p,*tail;
//	����ͷ��㲢��ʼ�� 
	head=(node*)malloc(sizeof(node));
	head -> next = NULL;
	tail = head;
	for(i=0;i<n;i++)
	{
		p=(node*)malloc(sizeof(node));
		p->num= arr[i];
		p->next = NULL;
		tail->next=p;
		tail = p;
	}
	tail->next = NULL;
	p = head->next;
	while(p)
	{
		printf("%d\n",p->num);
		p=p->next;
	}
 } 
