#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char s[24];
    int n,y,r;
}a[120],b[1];//b��ֵ��������
int main()
{
    int i,j,n,m,k;
    scanf("%d",&n);
    for (i=0;i<n;i++) scanf("%s %d %d %d",a[i].s,&a[i].n,&a[i].y,&a[i].r);
    for (i=0;i<n-1;i++)
         for (j=i+1;j<n;j++)
         {
             if ((a[i].n>a[j].n) || (a[i].n==a[j].n && a[i].y>a[j].y) || (a[i].n==a[j].n && a[i].y==a[j].y && a[i].r>=a[j].r))    //������ͽ�����ǰ��ȥ��ע����a[i].r>=a[j].r������a[i].r>a[j].r����Ϊ��Ŀ��˵������ȣ�������������
            {
                b[0]=a[i];
                a[i]=a[j];
                a[j]=b[0];//����
            }
        }
    for (i=0;i<n;i++) printf("%s\n",a[i].s);
    return 0;
}
