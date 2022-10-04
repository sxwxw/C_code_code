#include <stdio.h>
#define N 10 


/* 数组输出 
形如[11,22,33,...99]
每行输出元素的个数为 cols 
 
@param a,类型为int [], 数组名作为参数,获取的是数组的首地址,不能获取长度
@param size,类型为int, 获取数组的长度 
@param cols,类型为int, 每行输出元素的个数
*/
 void outputArr(int a[], int size, int cols){
	/*******begin********/
	int i;
	printf("[")
	
	 
	 
	/****** end ********/
		
 }


int main(){
	int arr[N]={11,22,33,44,55,66,77,88,99,10};//初始化时值的个数<=长度
	int cols;

	scanf("%d", &cols);
	
	//output
	outputArr(arr, N, cols); 
	
	printf("Numbers of Line: %d\n", cols);
	return 0;
	
}


