#include<stdio.h>
#include<string.h>

//typedef ������ typedef+����+���� 
//������ڶ���ṹ���ʱ��������Ͳ�����typedef 
//��int������Ϊabc ��ʱint ==abc 
//typedef int abc; 

/*���涨��ṹ�� */
typedef struct book{
	char title[10];
	char author[10];
}chongM;
//��������struct bookΪ chongM  book��ɾ�ɲ�ɾ 
int main(){
//	struct book���͵ı���books 
	chongM books[10];
	strcpy(books[0].title,"'�����'");
	strcpy(books[0].author,"'�޹���'"); 
	int i;
	for(i=0;i<1;i++)
	{
		printf("%s%s",books[0].title,books[0].author);
	}
	/*
	abc s=10;
	printf("%d",s);
	*/
	/*�ṹ��ָ�� 
	chongM *b=&books[0];
	printf("%s",(*b).author);
	printf("%s",b->author);
	*/
	system("pause");
	return 0;
	return 0;
}
