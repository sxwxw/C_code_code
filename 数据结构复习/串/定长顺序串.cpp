#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 255

typedef struct{
	char ch[maxsize];
	int len;
}string;

//串的赋值 
void pushChars(string*s1,char t[]){
	int i=0;
	for(i=0;t[i]!='\0';i++)
	{
		s1->ch[i]=t[i]; 
	}
	s1->len =i;
}

//串的插入 
int stringPush(string *s1,int post,string s2){
	int i;
	if(post<0||post-1>s1->len)
	{
		printf("插入位置不对");
		return 0;
	}
	if(s1->len+s2.len<=maxsize)
	{
		for(i=s1->len+s2.len;i>=post+s2.len-1;i--)
		{
			s1->ch[i]=s1->ch[i-s2.len];
		}
		for(i=0;i<s2.len;i++)
		{
			s1->ch[post+i-1]=s2.ch[i];
		}
		s1->len = s1->len+s2.len;
		return 1;
	}else if(post+s2.len<=maxsize){
		for(i=maxsize-1;i>s2.len+post-1;i--)
		{
			s1->ch[i]=s1->ch[i-s2.len];
		}
		for(i=0;i<s2.len;i++)
		{
			s1->ch[i+post]=s2.ch[i];
		}
		s1->len = maxsize;
		return 0;
	}else {
		for(i=0;i<maxsize-post;i++)
		{
			s1->ch[i+post]=s2.ch[i];
		}
		s1->len = maxsize;
		return 0;
	}
}
//串的删除
int deleString(string*s1,int pos,int delet){
	int i;
	if(pos<0||(pos+delet-1)>s1->len||delet<0)
	{
		printf("删除位置不对\n");
		return 0; 
	}
	else {
		for(i=pos+delet;i<=s1->len-1;i++)
		{
			s1->ch[i-delet]=s1->ch[i];	
		} 
		s1->len = s1->len-delet;
		return 1;
	}

}
//串的比较
int  strCompare(string*s1,string*s2){
	int i;
	for(i=0;i<s1->len&&i<s2->len;i++)
	{
		if(s1->ch[i]!=s2->ch[i])
		{
			return s1->ch[i]-s2->ch[i];
		}
		return s1->len-s2->len;
	}
}
//查找子串 
int strIndex(string*s1,int post,string s2){
	int i,j;
	if(s2.len==0)
	{
		return 0;
	}
	i=post;
	j=0;
	while(i<s1->len&&j<s2.len)
	{
		if(s1->ch[i]==s2.ch[j])
		{
			i++;
			j++;
		}else{
			i=i-j+1;
			j=0;
		}
	}
	if(j>=s2.len)
	{
		return i-j+1;
	}else{
		return 0;
	}
} 
//串的输出
void popChars(string*s1){
	int i=0;
	printf("串为:");
	for(i=0;i<s1->len;i++)
	{
		printf("%c",s1->ch[i]);
	}
	printf("\n");
} 
int main(){
	string s1,s2;
	char t[maxsize];
	gets(t);//子串1 
	pushChars(&s1,t);
	popChars(&s1);
	gets(t);//子串2 
	pushChars(&s2,t);
	popChars(&s2);
	int a = strCompare(&s1,&s2);//比较 
	printf("比较结果:%d\n",a);
	int b = strIndex(&s1,2,s2);//查找 
	printf("比较结果:%d\n",b);
	stringPush(&s1,2,s2);//插入 
	popChars(&s1);
	deleString(&s1,3,4);//删除 
	popChars(&s1);
	system("pause");
	return 0;
} 
