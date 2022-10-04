#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 50
typedef struct {
	int ch[maxsize];
	int len;
}string;

void pushChar(string*s,char t[]){
	int i;
	for(i=0;t[i]!='\0';i++)
	{
		s->ch[i]=t[i];
	}
	s->len=i;
}

void popChar(string*s){
	int i;
	for(i=0;i<s->len;i++)
	{
		printf("%c",s->ch[i]);
	}
	printf("\n");
}

int strIndex(string*s1,string s2,int pos){
	int i,j,start;
	if(s2.len==0)
	{
		return 0;
	}
	start=pos;
	i=start;
	j=0;
	while(i<s1->len&&j<s2.len)
	{
		if(s1->ch[i]==s2.ch[j])
		{
			i++;
			j++;
		}else{
			start++;
			i=start;
			j=0;
		}
	}
	if(j>=s2.len)
	{
		return start;
	}else {
		return -1;
	}
	
}
int main(){
	string s1,s2;
	char t[maxsize];
	int index;
	gets(t);
	pushChar(&s1,t);
	printf("主串"); 
	popChar(&s1);
	gets(t);
	pushChar(&s2,t);
	printf("子串"); 
	popChar(&s2);
	index = strIndex(&s1,s2,2);
	printf("初次下标:%d\n",index);
	system("pause");
	return 0;
}
