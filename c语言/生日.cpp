#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char s[24];
    int n,y,r;
}a[120],b[1];//b数值用来交换
int main()
{
    int i,j,n,m,k;
    scanf("%d",&n);
    for (i=0;i<n;i++) scanf("%s %d %d %d",a[i].s,&a[i].n,&a[i].y,&a[i].r);
    for (i=0;i<n-1;i++)
         for (j=i+1;j<n;j++)
         {
             if ((a[i].n>a[j].n) || (a[i].n==a[j].n && a[i].y>a[j].y) || (a[i].n==a[j].n && a[i].y==a[j].y && a[i].r>=a[j].r))    //岁数大就交换到前面去，注意是a[i].r>=a[j].r而不是a[i].r>a[j].r，因为题目上说年龄相等，后输入的先输出
            {
                b[0]=a[i];
                a[i]=a[j];
                a[j]=b[0];//交换
            }
        }
    for (i=0;i<n;i++) printf("%s\n",a[i].s);
    return 0;
}
