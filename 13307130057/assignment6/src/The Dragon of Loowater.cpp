#include <iostream>
#include <cstdio>
using namespace std;
void qs(int q[],int l,int r)
{
    int i,j,x,t;
    i=l;j=r;x=q[(i+j)/2];
    do
    {
        while ((q[i]<x)&&(i<r)) i++;
        while ((q[j]>x)&&(j>l)) j--;
        if (i<=j)
        {
            t=q[i];q[i]=q[j];q[j]=t;
            i++;j--;
        }
    }while (i<=j);
    if (j>l) qs(q,l,j);
    if (i>r) qs(q,i,r);
}
int main()
{
    int a[50000],b[50000],n,m,i,t,j;
    long long s;
    cin>>n>>m;
    while ((n)||(m))
    {
        if (n>m) cout<<"Loowater is doomed!"<<endl;
        else
        {
            for (i=0;i<50000;i++)
            {
                a[i]=0;b[i]=0;
            }
            for (i=0;i<n;i++) cin>>a[i];
            for (i=0;i<m;i++) cin>>b[i];
            qs(a,0,n-1);
            qs(b,0,m-1);
            t=1;s=0;j=0;
            for (i=0;i<n;i++)
            {
                while ((j<m)&&(a[i]>b[j])) j++;
                if (j>=m)
                {
                    t=0;break;
                }
                s=s+b[j];j++;
            }
            if (t) cout<<s<<endl;
            else cout<<"Loowater is doomed!"<<endl;
        }
        cin>>n>>m;
    }
    return 0;
}