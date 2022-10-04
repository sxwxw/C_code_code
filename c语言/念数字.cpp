#include <stdio.h>
int main(){
	char c[10][5]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	int i=0;
	char a[10];
	scanf("%s",&a);
	if(a[i]=='-'){
		printf("fu");
		i++; 
		printf(" ");
	}
	for(i;a[i] != '\0';i++)
	{ 
		if(a[i]=='1'){
			printf("%s",c[1]);
		}
		else if(a[i]=='2'){
			printf("%s",c[2]);	
		} 
		else if(a[i]=='3'){
			printf("%s",c[3]);	
		} 
		else if(a[i]=='4'){
			printf("%s",c[4]);
		} 
		else if(a[i]=='5'){
			printf("%s",c[5]);
		} 
		else if(a[i]=='6'){
			printf("%s",c[6]);	
		} 
		else if(a[i]=='7'){
			printf("%s",c[7]);
		}
		else if(a[i]=='8'){
			printf("%s",c[8]);	
		} 
		else if(a[i]=='9'){
			printf("%s",c[9]);	
		} 
		if(a[i+1]!='\0'){
			printf("*");
		}
	} 
	return 0;
}
