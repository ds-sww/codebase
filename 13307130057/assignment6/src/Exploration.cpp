#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
void qs(int a[],int l,int r)
{
    int i,j,x,t;
    i=l;j=r;x=abs(a[(i+j)/2]);
    do
    {
        while ((abs(a[i])<x)&&(i<r)) i++;
        while ((abs(a[j])>x)&&(j>l)) j--;
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
    int a[100000],n,i,t,s,temp;
    cin>>t>>n;
    for (i=0;i<n;i++) cin>>a[i];
    qs(a,0,n-1);
    s=0;temp=0;
    while ((t>0)&&(s<n))
        if (t>=abs(a[s]-temp))
        {
            t=t-abs(a[s]-temp);
            temp=a[s];
            s++;
        }
        else break;
    cout<<s<<endl;
    return 0;
}