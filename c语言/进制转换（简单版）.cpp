#include<stdio.h>
#include<string.h>
int main(){
	int n;
	char s[5000];
	scanf("%d%s",&n,s);
	for(int i=0;i<strlen(s);i++) {
		if(s[i]=='0'){
			continue;
		}
		if(i!=0 && s[i]!='0'){
			printf("+");
		}
		printf("%c*%d^%d",s[i],n,strlen(s)-1-i);
	}
} 
