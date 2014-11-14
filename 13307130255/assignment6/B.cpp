#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;
int a[100000];
int n,t;

void qsort(int l,int r)
{
    int x=a[l],i=l,j=r;
    while(i<j)
    {
        while(i<j&&abs(a[j])>abs(x)) j--;
        if(i<j) a[i] = a[j];
        while(i<j&&abs(a[i])<abs(x)) i++;
        if(i<j) a[j] = a[i];
    }
    a[i] = x;
    if(i-1>l) qsort(l,i-1);
    if(i+1<r) qsort(i+1,r);
}
int main()
{
    scanf("%d %d",&t,&n);
    int i,sum=0,js=0;
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    qsort(0,n-1);
    sum = abs(a[0]);
    i=0;
    while(sum<=t)
    {
        js++;
        if(i+1==n) break;
        sum += abs(a[++i] - a[i-1]);
    }
    printf("%d\n",js);
    return 0;
}
