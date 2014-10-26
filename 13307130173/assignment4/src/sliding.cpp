#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<deque>
#define maxn 1111111
using namespace std;
deque<int> q1;
deque<int> q2;
int n,k,a[maxn],fmin[maxn],fmax[maxn];
int main()
{
//    freopen("1.in","r",stdin);
//    freopen("1.out","w",stdout);
    scanf("%d %d",&n,&k);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    for (int i=0;i<n;i++)
    {
        while (q1.size() && q1.front()<=i-k) q1.pop_front();
        while (q1.size() && a[q1.back()]>=a[i]) q1.pop_back();
        q1.push_back(i);
        if (i>=k-1) fmin[i]=a[q1.front()];
    }
    for (int i=k-1;i<n-1;i++) printf("%d ",fmin[i]);
    printf("%d\n",fmin[n-1]);
    for (int i=0;i<n;i++)
    {
        while (q2.size() && q2.front()<=i-k) q2.pop_front();
        while (q2.size() && a[q2.back()]<=a[i]) q2.pop_back();
        q2.push_back(i);
        if (i>=k-1) fmax[i]=a[q2.front()];
    }
    for (int i=k-1;i<n-1;i++) printf("%d ",fmax[i]);
    printf("%d\n",fmax[n-1]);    
    return 0;
}
