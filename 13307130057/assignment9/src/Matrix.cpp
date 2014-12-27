#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for (int k=0;k<t;k++)
    {
        long long n,m,left,right,ans;
        cin>>n>>m;
        left=-n*100000;right=n*n*3+100000*n;
        while (left<=right)
        {
            long long middle,sum;
            middle=(left+right)>>1;
            sum=0;
            for (long long j=1;j<=n;j++)
            {
                int l,r,s;
                l=1;r=n;s=0;
                while (l<=r)
                {
                    long long x,mid;
                    mid=(l+r)>>1;
                    x=mid*mid+j*j+mid*j+100000*(mid-j);
                    if (x<=middle)
                    {
                        s=mid;
                        if (x==middle) break;
                        else l=mid+1;
                    }
                    else r=mid-1;
                }
                sum=sum+s;
            }
            if (sum>=m) 
            {
                ans=middle;
                right=middle-1;
            }
            else left=middle+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}