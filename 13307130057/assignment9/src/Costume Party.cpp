#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n,s,l,r,mid,temp,sum,a[20000];
    cin>>n>>s;
    for (int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);sum=0;
    for (int i=0;i<n-1;i++)
    {
        if (a[i]>=s) break;
        temp=s-a[i];
        l=i+1;r=n-1;
        while (l<=r)
        {
            mid=(l+r)/2;
            if (a[mid]==temp) break;
            else if (a[mid]<temp) l=mid+1;
            else r=mid-1;
        }
        while (a[mid]>temp) mid--;
        while ((mid<n-1)&&(a[mid+1]<=temp)) mid++;
        if (mid>i) sum=sum+mid-i;
    }
    cout<<sum<<endl;
    return 0;
}