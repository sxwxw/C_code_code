#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct string{
	char*ch;
	int len;
}string;

//���� 
void intChar(string*s){
	s->ch=(char*)malloc(s->len);
	scanf("%s",s->ch);
}
//��� 
void view(string*s){
	printf("%s\n",s->ch); 
}
//���� 
int pushChar(string*s1,string*s2,int pos){
	int i;
	char *temp;
	if(pos<0||s1->len<pos||s1->len==0)
	{
		printf("����λ�ô���");
		return 0; 
	}
	temp = (char*)malloc(s1->len+s2->len);
	if(temp==NULL)
	{
		return 0;
	}
	for(i=0;i<pos;i++)
	{
		temp[i]=s1->ch[i];
	}
	for(i=0;i<s2->len;i++)
	{
		temp[i+pos]=s2->ch[i];
	}
	for(i=pos;i<s1->len;i++)
	{
		temp[i+s2->len]=s1->ch[i];
	}
	s1->len+=s2->len;
	free(s1->ch);
	s1->ch=temp;
	int nums = strlen(s1->ch); 
	return nums;
}
//ɾ��
void deletChar(string*s1,int pos,int number){
	int i;
	char*temp;
	if(s1->ch==NULL)
	{
		printf("������ɾ��");
		return; 
	}
	temp = (char*)malloc(s1->len-number);
	for(i=0;i<pos-1;i++)
    {
        temp[i]=s1->ch[i];
    }
    for(i=0;i<s1->len-number;i++)
    {
        temp[i+pos-1]=s1->ch[i+pos+number-1];
    }
	free(s1->ch);
	s1->ch=temp;
} 
int main(){
	int num,number;
	int pos;
	string s1,s2;
	printf("��������:");
	scanf("%d\n",&num);
	s1.len=num;
	intChar(&s1);
	view(&s1);
	printf("�Ӵ�����:");
	scanf("%d",&num);
	s2.len=num;
	intChar(&s2);
	view(&s2);
	scanf("%d",&pos);
	pushChar(&s1,&s2,pos);
	view(&s1);
	printf("��ʼ���ɾ����:");
	scanf("%d %d",&pos,&number);
	deletChar(&s1,pos,number);
	printf("ɾ���������:"); 
	view(&s1);
	system("pause");
	return 0;
}
