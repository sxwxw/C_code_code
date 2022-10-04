#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

//创建节点 
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
	printf("前序遍历:");
	preOder(t);
	printf("\n");
	printf("中序遍历:");
	intra(t);
	printf("\n");
	printf("后序遍历:");
	post(t);
	printf("\n");
	printf("前序遍历输出叶子节点:");
	preOderChild(t);
	printf("\n");
	printf("树的最大深度:");
	int deap = postDeap(t);
	return 0;
}

