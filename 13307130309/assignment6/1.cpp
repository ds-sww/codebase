#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n,m;
int a[1000001];
char ch[10];
void qs(int l,int r)
{
    int i,j,step=a[l];
    i=l,j=r;
    while(i<=j)
    {
        while(i<=j&&a[i]<step) i++;
        while(i<=j&&step<a[j]) j--;
        if(i<=j)
        {
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i++,j--;
        }
    }
    if(l<j)
        qs(l,j);
    if(i<r)
        qs(i,r);
}
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    qs(0,n-1);
    scanf("%s",ch);
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        int q;
        scanf("%d",&q);
        printf("%d\n",a[q-1]);
    }
    return 0;
}

