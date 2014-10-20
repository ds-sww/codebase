#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<stack>
#define maxn 111111
using namespace std;
int n,x,l[maxn],r[maxn],a[maxn];
struct rec
{
   int l,key;
   rec(int u,int v):l(u),key(v){}
   rec(){}
};
stack<rec> s;
long long res,ans;
int main()
{
//    freopen("rect.in","r",stdin);
//    freopen("rect.out","w",stdout);
    scanf("%d",&n);
    while (n)
    {
       ans=0;
       for (int i=0;i<n;i++) scanf("%d",&a[i]);
       for (int i=0;i<n;i++) { l[i]=r[i]=i; }
       for (int i=0;i<n;i++)
       {
           while (!s.empty() && s.top().key>=a[i])
           {
                 l[i]=s.top().l;
                 if (s.top().key==a[i]) break;
                 s.pop();
           }
           if (s.empty() || a[i]>s.top().key) s.push(rec(l[i],a[i]));   
       }
       while (!s.empty()) s.pop();   
       for (int i=n-1;i>=0;i--)
       {
           while (!s.empty() && s.top().key>=a[i])
           {
                 r[i]=s.top().l;
                 if (s.top().key==a[i]) break;                 
                 s.pop();
           }  
           if (s.empty() || a[i]>s.top().key) s.push(rec(r[i],a[i]));   
       }
       while (!s.empty()) s.pop();
       for (int i=0;i<n;i++)
       {
           res=(long long)(r[i]-l[i]+1)*a[i];
           if (res>ans) ans=res;
       }       
       cout<<ans<<"\n";
       scanf("%d",&n);
    }
    return 0;
}
