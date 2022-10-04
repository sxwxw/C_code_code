#include<iostream>
using namespace std;
void fun(char *s,char t){
	while(*s){
		if(*s==t){
			*s=t-'a'+'A';
			s++;
		}
	}
}
int main(){
	char str1[100]="abcddfeefdbd";
	char c='d';
	fun(str1,c);
	cout<<str1;
	return 0;
} 
