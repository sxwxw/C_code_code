#include <stdio.h>
// 定义main函数
int main()
{
    // 请在此添加代码
    /********** Begin *********/
    int a[11]={1,4,6,9,11,25,31,46,83,100};
    int i,j=0,n;
    scanf("%d",&n);
    for(i=0;i<10;i++)
    {
        if(a[i]>=n)
        {
            j=i;
        }
    }
    for(i=10;i>j;i--)
    {
        a[i+1]=a[i];
    }
    a[j]=n;
    for(i=0;i<11;i++)
    {
        printf("%d\n",a[i]);
    }
    /********** End **********/
    return 0;
}

