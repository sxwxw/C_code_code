#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#define N 2020

#define COLS 7 
#define LOW 13
#define UP 31

/*
Find the smallest even number in an array,
Assumed value range of array elements is [LOW, UP]
@param a:Data type is int [], get the first address of the array
@param size:Data type is int, Get array length
@return id:Data type is int, Returns the maximum value in the array
*/
int getValuePeek(int a[], int size ){
	/********** begin **********/
	int i,peek=32;
	for(i=0;i<size;i++)
	{
		if(a[i]<peek&&a[i]%2==0)
		{
			peek=a[i];
		}
	}
	
   return peek;

	/********** end **********/
} 

/* input array
@param a:Data type is int [], get the first address of the array
@param size:Data type is int, Get array length 
@return void
*/
 void inputArr(int a[], int size){
 	int i;
 	
 	//traverse
	for(i=0; i<size; i++){ //size´Î 
		scanf("%d", &a[i]);		
	
	}  	
 }


int main(){
	int array[N];
	int length;
	
	printf("Please Input the number of array elements.\n");
	scanf("%d", &length);	
	//input
	inputArr(array, length);
	
	printf("SmallestEven=%d\n", getValuePeek(array, length) );
	
}


