#include<stdio.h>
#include <time.h>
#include <stdlib.h> 
int A[30000];
int main(){
	int i;
	double start,finish;
	start=(double) clock();  //��ÿ�ʼ ʱ��
	for (i=0;i<10000;i++)
//	    printf("Hello,World");
	
	finish=(double)clock();  //��ý��� ʱ��
    // ��� ʱ��� ���� ����
    printf("%.4f ms",finish-start);
	system( "wmic process list MEMORY >>log.txt");
	//��system����ִ��wmic�������һ��log.txt�ļ���
	//��log.txt�������ĳ�������Ӧ����һ�У���¼  PeakVirtualSize ���� 
}

