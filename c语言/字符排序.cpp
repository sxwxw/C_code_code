#include<stdio.h>

void  fun(char s[],int num)
{
	/********** Begin **********/
    int i,j,k;
    for(i=1;i<num;i++)
    {
    	for(j=0;j<=num-i;j++)
    	{
    		if(s[j]>s[j-1])
    		{
    			k=s[j-1];
    			s[j-1]=s[j];
    			s[j]=k;
			}
		}
	}
	/**********  End  **********/
}

int main()
{
	char s[10];
	printf("����8���ַ����ַ���:");
	gets(s);
	fun(s,8);
	printf("%s\n",s);
	return 0;
}
