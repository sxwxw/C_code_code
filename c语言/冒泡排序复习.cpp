#include <stdio.h>
int main()
{
	void printArray(int array[],int length);
	int array[]={49,38,65,97,76,13,27,49};
	int i,j,temp;
	int length=sizeof(array)/sizeof(int);
	printf("待排序的数组是：");
	printArray(array,length);
	for(i=0;i<length-1;i++)
	{
		for(j=0;j<length-i;j++)
		{
			if(array[j]>array[j+1])
			{
				temp=array[j];
				array[j]=array[j+1]; 
				array[j+1]=temp; 
			}
		}
	}
	printf("第%d轮排序的结果：",i+1);
	printArray(array,length);
	return 0;
  
void printArray(int array[],int length);
{
 	int i;
 	for(i=0;i<length;i++)
 	{
 		printf("%d",array[i]);
 		
	}
	 printf("\n");
}
}
