#include <stdio.h>

char fun(int s)
{        
	char grade;     // 存储分数对应的等级
	/********** Begin **********/
    if(s<=59)
	grade='E';
	else if(s<=69)
	grade='D';
	else if(s<=79)
	grade='C';
	else if(s<=89)
	grade='B';
	else if(s<=100)
	grade='A';
    return grade;
	
    
    
	/**********  End  **********/
}

int main (void)
{
        int  score;
        scanf ("%d", &score);
        printf("The grade is: %c\n", fun(score));
        return 0;
}

