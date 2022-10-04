#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
typedef struct node{
	int data; 
	struct node *next;
}node;

int main(){
	int arr[]={1,2,3,4};
//	通过总内存量与单个内存量的比值，得出数组元素个数 
	int n =sizeof(arr)/sizeof(int);
//	定义头指针和辅助指针 
	node*head=NULL,*p;
	for(int i=0;i<n;i++)
	{
//		给p指针动态分配空间 
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
