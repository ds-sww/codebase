#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;
int a[200000];
void qsort(int l,int r)
{
    int x=a[l],i=l,j=r;
    while(i<j)
    {
        while(i<j&&a[j]>=x) j--;
        if(i<j) a[i] = a[j];
        while(i<j&&a[i]<=x) i++;
        if(i<j) a[j] = a[i];
    }
    a[i] = x;
    if(i-1>l) qsort(l,i-1);
    if(i+1<r) qsort(i+1,r);
}
int main()
{
    string str;
    int i =0,k,t;
    int n;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    getline(cin,str);
    getline(cin,str);
    qsort(0,n-1);
    cin>>k;
    for(i=0;i<k;i++)
    {
        cin>>t;
        cout<<a[t-1]<<endl;
    }
    return 0;
}
