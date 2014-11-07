#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
void qs(int a[],int l,int r)
{
    int i,j,x,t;
    i=l;j=r;x=a[(i+j)/2];
    do
    {
        while ((a[i]<x)&&(i<r)) i++;
        while ((a[j]>x)&&(j>l)) j--;
        if (i<=j)
        {
            t=a[i];a[i]=a[j];a[j]=t;
            i++;j--;
        }
    }while (i<=j);
    if (l<j) qs(a,l,j);
    if (i<r) qs(a,i,r);
}
int main()
{
    int a[100000],n,i,x;
    string s;
    cin>>n;
    for (i=0;i<n;i++) cin>>a[i];
    qs(a,0,n-1);
    cin>>s;
	cin>>n;
    for (i=0;i<n;i++)
    {
        cin>>x;
        cout<<a[x-1]<<endl;
    }
    return 0;
}