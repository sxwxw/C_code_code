
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#define N 2020


/*
Find the index of the maximum value in the array.
@param a:Data type is int [], get the first address of the array
@param size:Data type is int, Get array length
@return id:Data type is int, Returns the index of the maximum element
If there are multiple, return the last one
*/
int getIndexMax(int a[], int size){
	/********* begin ***********/
	int i;
	int Max=0;
	for(i=1;i<size;i++)
	{
		
		if(a[i]>a[Max])
		{
			Max=i;
		}
		
		
	 }
	 
	return Max;
	
	/********* end **********/
	
} 

/*
Get the average of the array
@param a:Data type is int [], get the first address of the array
@param size:Data type is int, Get array length
@return id:Data type is int, Returns the average of the array
*/
double getValueAver(int a[], int size){
	
	/********** begin **********/
	int sum=0,i;
	double aver;
	for(i=0;i<size;i++)
	{
		sum+=a[i];
	}
	aver=(double)sum/size;
	return aver;
	 
	/********* end *********/
} 

/* input array
@param a:Data type is int [], get the first address of the array
@param size:Data type is int, Get array length 
@return void
*/
 void inputArr(int a[], int size){
 	int i;
 	
 	//srand( time(NULL) ); 
 	//traverse
	for(i=0; i<size; i++){ //size´Î 
		scanf("%d", &a[i]);		
		
		//[13,31]=13+[0,18]= LOW + %(UP-LOW+1)=[LOW,UP]
		//a[i] = rand()%(UP-LOW+1) + LOW; 
	}  	
 }


int main(){
	int array[N];
	int length;
	
	printf("Please Input the number of array elements.\n");
	scanf("%d", &length);	
	//input
	inputArr(array, length);
	
	printf("MaxinumIndex=%d\n", getIndexMax(array, length) );
	
	printf("Average=%lf\n", getValueAver(array, length) );
	
}

