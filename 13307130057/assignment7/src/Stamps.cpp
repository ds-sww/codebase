#include <iostream>
#include <cstdio>
using namespace std;
void qs(int a[],int l,int r)
{
    int i,j,x,t;
    i=l;j=r;x=a[(i+j)/2];
    do
    {
        while ((a[i]>x)&&(i<r)) i++;
        while ((a[j]<x)&&(j>l)) j--;
        if (i<=j)
        {
            t=a[i];a[i]=a[j];a[j]=t;
            i++;j--;
        }
    }while (i<j);
    if (l<j) qs(a,l,j);
    if (i<r) qs(a,i,r);
}
int main()
{
    int n,m,s,sum,i,j,a[10000];
    cin>>n;
    for (i=0;i<n;i++)
    {
        cin>>s>>m;
        for (j=0;j<m;j++) cin>>a[j];
        qs(a,0,m-1);
        sum=0;
        while ((s>0)&&(sum<m)) s=s-a[sum++];
        cout<<"Scenario #"<<i+1<<':'<<endl;
        if (s<=0) cout<<sum<<endl;
        else cout<<"impossible"<<endl;
        cout<<endl;
    }
    return 0;
}