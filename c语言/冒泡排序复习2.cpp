#include <stdio.h>
int main()
{
	
	void printArray(int array[],int length);
	int array[]={49,38,65,97,76,13,27,49};
	int i,j,temp,flag;
	int length=sizeof(array)/sizeof(int);
	printf("待排序的数组是：");
	printArray(array,length);
	printf("\n");
	for(i=0;i<length-1;i++)
	{
		flag=0;
		for(j=0;j<length-i-1;j++)
		{
			flag=1;
			if(array[j]>array[j+1])
			{
				temp=array[j];
				array[j]=array[j+1]; 
				array[j+1]=temp; 
			}
		}
		if(flag==0)
		{
			break;
		}
	}
	printf("第%d轮排序的结果：",i+1);
	printArray(array,length);
	return 0;
}  
void printArray(int array[],int length)
{
 	int i;
 	for(i=0;i<length;i++)
 	{
 		printf("%d",array[i]);
 		 printf(" ");
	}
	
}

