#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<stack>
using namespace std;
stack<int> s;
int n,x;
int main()
{
 //   freopen("1.in","r",stdin);
   // freopen("1.out","w",stdout);
    scanf("%d",&n);
    while (n)
    {
        while (!s.empty()) s.pop();  
        int now=0;
        bool flag=0;
        int i=1;
        while (i<=n)
        {
            scanf("%d",&x);      
            if (flag) { i++; continue; }
            if (x==0) { scanf("%d",&n); if (n) printf("\n");continue; }
            if (x<now)
            {
                if (s.empty() || s.top()!=x) { flag=1; i++; continue; }      
                s.pop();
            }
            for (int j=now+1;j<x;j++) s.push(j);
            if (x>now) now=x;
            i++;
        }  
        if (!n) break;                   
        if (flag) printf("No\n"); else printf("Yes\n");        
    }
    return 0;
}
