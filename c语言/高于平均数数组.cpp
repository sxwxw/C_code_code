#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#define N 2020
#define COLS 7
/*
Get the subscript of the element that is not lower than the average of the array
@param a:Data type is int [], get the first address of the array
@param size:Data type is int, Get array length
@param mt:Data type is int [], save the indexes
@return id:Data type is int, Returns  the length of  array mt
*/
double getIndexMTAver(int a[], int size,int mt[]){
	/********** begin **********/
    int sum=0,i,n=0;
	double aver;
	for(i=0;i<size;i++)
	{
		sum+=a[i];
	}
	aver=(double)sum/size;
    for(i=0;i<size;i++)
    {
    	if(a[i]>=aver)
    	{
    	
    	mt[n]=i;
		n++;
    		
    		
    	}
	}
    return n;
	/********** end **********/
} 

/* input array
@param a:Data type is int [], get the first address of the array
@param size:Data type is int, Get array length 
@return void
*/
 void inputArr(int a[], int size){
 	int i;
 	
 	srand( time(NULL) ); 
 	//traverse
	for(i=0; i<size; i++){ //sizetimes 
		scanf("%d", &a[i]);		
		
	}  	
 }


/* input array
@param a:Data type is int [], get the first address of the array
@param size:Data type is int, Get array length
 
*/
void outputArr(int a[], int size){
 	int i;
 	//output
 	putchar('['); 
	for(i=0; i<size; i++){ //size times 
		printf("%d", a[i]);
	
		//Question mark expression,print ',' or ']'
		(i != size-1) ? putchar(' '): putchar(']');
		
		//print newline
		if( ! ((i+1)%COLS) || (i+1) == size) {
			putchar('\n'); 
		}	
	}
	
 }

int main(){
	int array[N], mt[N];
	int length;
	
	printf("Please Input the number of array elements.\n");
	scanf("%d", &length);	
	//input
	inputArr(array, length);
	
	length = getIndexMTAver(array, length, mt); 
	printf("MoreThanAver Numbers = %d\n", length);
	
	outputArr(mt, length);
	
	
}

	
    	    	
		

