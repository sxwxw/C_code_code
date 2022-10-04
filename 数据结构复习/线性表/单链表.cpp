//动态创建链表： 动态内存申请 + 模块化开发 
#include <stdio.h>
#include <stdlib.h>
#include <string>

//定义节点 
typedef struct node {
	int data;//数据域 
	struct node*next;//指针域 
}node;

/*node*createList()中*表示名为createList的函数的返回值是一个指针
，而这个指针指向的类型就是node型。
也就是说返回值的类型是指向node型数据的指针。
*/
//创建头指针并初始化 
node*createList(){
	node*headNode = (node*)malloc(sizeof(node));
//	headNode由结构体指针变为结构体变量 
	headNode->next =NULL; 
	return headNode;
}

//创建节点 
node*creatNode(int data){
	node*p=(node*)malloc(sizeof(node));
	p->data=data;
	p->next= NULL;
	return p;
} 

//头插法 
void creatHead(node*headNode,int data){
	node*newNode = creatNode(data);
	newNode->next = headNode->next;
	headNode->next = newNode;
}
//删除节点
void deledNode(node*headNode,int postData)
{
	node*postNode = headNode->next;
	node*postFront = headNode;
	if(postNode==NULL)
	{
		printf("无法删除链表为空\n");
	}
	else {
		while (postNode->data!=postData)
		{
			postFront = postNode;
			postNode = postNode->next;
			if(postNode->next==NULL)
			{
				printf("未找到信息\n");
				return;
			}
		}
		postFront->next = postNode->next;
		free(postNode);
	}
	
}

//查找结点
void Locate(node*headNode,int key){
	int i=0;
	node*search = headNode->next;
	while(search!=NULL)
	{
		if(search->data!=key)
		{
			search =search->next;
			i++;
		}
		else {
			break;
		}
	}
	printf("位置：%d\n",i);
} 
//长度 {
void nodeLength(node*headNode)
{
	node*h = headNode->next;
	int j = 0;
	while(h!=NULL)
	{
		h = h->next;
		j++;
	}
	printf("长度：%d\n",j);
 } 
// 输入数据 
void inputNode(node*L,int n)
{
	int i;
	for(i=1;i<n;i++)
	{
		creatHead(L,i);
	}
}
//插入节点
void inlist(node*headNode,int i,int e) 
{
	int k=0;
	node*searchNode = headNode->next;
	while(searchNode!=NULL&&k<i-1)
	{
		searchNode =searchNode->next;
		k=k+1;
	}
	if(searchNode==NULL)
	{
		printf("未找到信息\n");
		return;
	}
	node*s;
	s=(node*)malloc(sizeof(node));
	s->next = searchNode->next;
	s->data = e;
	searchNode->next = s;
	return;
}
//打印 
void printfList(node*headNode){
	node*pMove = headNode->next;
	printf("链表："); 
	while(pMove)
	{
		printf("%d",pMove->data);
		pMove=pMove->next;
		
	}
	printf("\n");
} 
int main(){
	int n,i,e;
	scanf("%d",&n); 
	node *list = createList();//这是调用创建链表函数，返回表头指针 给list
	inputNode(list,n);//输入数据 
	Locate(list,1);//查找元素 
	nodeLength(list);//长度 
	printfList(list);//输出 
	deledNode(list,2);//删除节点 
	inlist(list,2,4);//插入节点 
	printfList(list);//输出 
	system("pause");
	return 0;
}


