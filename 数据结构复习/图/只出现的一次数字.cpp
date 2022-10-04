#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int singleNumber(int* nums, int len){
    int index = nums[i];
    for(int i = 0;i < len;i++)
    {
    	index = index ^ nums[i];
	}
	return index;
}
int main(){
	int a[]={1,3,1,3,3};
	int j = singleNumber(a,5);
	printf("%d",j);
	return 0; 
} 

//这里用到异或运算 
