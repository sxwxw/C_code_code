//��̬�������� ��̬�ڴ����� + ģ�黯���� 
#include <stdio.h>
#include <stdlib.h>
#include <string>

//����ڵ� 
typedef struct node {
	int data;//������ 
	struct node*next;//ָ���� 
}node;

/*node*createList()��*��ʾ��ΪcreateList�ĺ����ķ���ֵ��һ��ָ��
�������ָ��ָ������;���node�͡�
Ҳ����˵����ֵ��������ָ��node�����ݵ�ָ�롣
*/
//����ͷָ�벢��ʼ�� 
node*createList(){
	node*headNode = (node*)malloc(sizeof(node));
//	headNode�ɽṹ��ָ���Ϊ�ṹ����� 
	headNode->next =NULL; 
	return headNode;
}

//�����ڵ� 
node*creatNode(int data){
	node*p=(node*)malloc(sizeof(node));
	p->data=data;
	p->next= NULL;
	return p;
} 

//ͷ�巨 
void creatHead(node*headNode,int data){
	node*newNode = creatNode(data);
	newNode->next = headNode->next;
	headNode->next = newNode;
}
//ɾ���ڵ�
void deledNode(node*headNode,int postData)
{
	node*postNode = headNode->next;
	node*postFront = headNode;
	if(postNode==NULL)
	{
		printf("�޷�ɾ������Ϊ��\n");
	}
	else {
		while (postNode->data!=postData)
		{
			postFront = postNode;
			postNode = postNode->next;
			if(postNode->next==NULL)
			{
				printf("δ�ҵ���Ϣ\n");
				return;
			}
		}
		postFront->next = postNode->next;
		free(postNode);
	}
	
}

//���ҽ��
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
	printf("λ�ã�%d\n",i);
} 
//���� {
void nodeLength(node*headNode)
{
	node*h = headNode->next;
	int j = 0;
	while(h!=NULL)
	{
		h = h->next;
		j++;
	}
	printf("���ȣ�%d\n",j);
 } 
// �������� 
void inputNode(node*L,int n)
{
	int i;
	for(i=1;i<n;i++)
	{
		creatHead(L,i);
	}
}
//����ڵ�
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
		printf("δ�ҵ���Ϣ\n");
		return;
	}
	node*s;
	s=(node*)malloc(sizeof(node));
	s->next = searchNode->next;
	s->data = e;
	searchNode->next = s;
	return;
}
//��ӡ 
void printfList(node*headNode){
	node*pMove = headNode->next;
	printf("����"); 
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
	node *list = createList();//���ǵ��ô��������������ر�ͷָ�� ��list
	inputNode(list,n);//�������� 
	Locate(list,1);//����Ԫ�� 
	nodeLength(list);//���� 
	printfList(list);//��� 
	deledNode(list,2);//ɾ���ڵ� 
	inlist(list,2,4);//����ڵ� 
	printfList(list);//��� 
	system("pause");
	return 0;
}


