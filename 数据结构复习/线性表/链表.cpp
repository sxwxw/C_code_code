#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
typedef struct node{
	int data; 
	struct node *next;
}node;

int main(){
	int arr[]={1,2,3,4};
//	ͨ�����ڴ����뵥���ڴ����ı�ֵ���ó�����Ԫ�ظ��� 
	int n =sizeof(arr)/sizeof(int);
//	����ͷָ��͸���ָ�� 
	node*head=NULL,*p;
	for(int i=0;i<n;i++)
	{
//		��pָ�붯̬����ռ� 
		p=(node*)malloc(sizeof(node));
		p->data = arr[i];
		p->next = head;
		head = p;
	}
	p=head;
	while(p)
	{
		printf("%s",p->data);
		p=p->next;
	}
}
