#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#define Rep(i,n) for(int i=0,_n=(n);i<_n;i++)
#define For(i,l,r) for(int i=(l),_r=(r);i<=_r;i++)
#define rFor(i,r,l) for(int i=(r),_l=(l);i>=_l;i--)
using namespace std;

const int N=1005;
int a[N];
stack<int> st;

int main()
{
    //freopen("1.in","r",stdin);
    int n;
    while (scanf("%d",&n),n)
    {
        while (scanf("%d",a),a[0])
        {
            For(i,1,n-1)
                scanf("%d",a+i);
            while (!st.empty())
                st.pop();
            int now=1;
            Rep(i,n)
            {
                while (st.empty() || now<=n && st.top()!=a[i])
                    st.push(now++);
                if (st.top()==a[i])
                st.pop();
            }
            if (st.empty()) printf("Yes\n");
            else printf("No\n");
        }
        printf("\n");
    }
	return 0;
}
