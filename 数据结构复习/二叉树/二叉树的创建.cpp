#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

//�����ڵ� 
typedef struct node{
	char data;
	struct node*left;
	struct node*right;
}node,*tree;

void createTree(tree&t)
{
	char a;
	scanf("%c",&a);
	if(a=='#')
	{
		return;
	}else{
		t = (node*)malloc(sizeof(node));
		t->data = a;
		t->left = NULL;
		t->right = NULL;
	}
	createTree(t->left);
	createTree(t->right);
}

void preOder(tree t)
{
	if(t)
	{
		printf("%c",t->data);
		preOder(t->left);
		preOder(t->right);
	}
}
void preOderChild(tree t)
{
	if(t)
	{
		if(t->left==NULL&&t->right==NULL)
		{
			printf("%c",t->data);
		}
		preOder(t->left);
		preOder(t->right);
	}
}
void intra(tree t)
{
	if(t)
	{
		preOder(t->left);
		printf("%c",t->data);
		preOder(t->right);
	}
}

void post(tree t)
{
	if(t)
	{
		preOder(t->right);
		preOder(t->left);
		printf("%c",t->data);
	}
}
int postDeap(tree t)
{
	int hl,hr,max;
	if(t)
	{
		hl = postDeap(t->left);
		hr = postDeap(t->right);
		max = hl>hr?hl:hr;
		return (max+1);
	}else {
		return 0;
	}
}
int main(){
	node *t;
	createTree(t);
	printf("ǰ�����:");
	preOder(t);
	printf("\n");
	printf("�������:");
	intra(t);
	printf("\n");
	printf("�������:");
	post(t);
	printf("\n");
	printf("ǰ��������Ҷ�ӽڵ�:");
	preOderChild(t);
	printf("\n");
	printf("����������:");
	int deap = postDeap(t);
	return 0;
}

