

#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;
long long ans;
stack<int> num,js;
int main(int argc, char **argv)
{
	int n,i,cur,t;
    long long sum;
    scanf("%d",&n);
    while(n)
    {
        ans = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&cur);
            if(num.empty()||cur>num.top())
            {
                num.push(cur);
                js.push(0);
            }else
            {
                t=0;
                while(!num.empty()&&cur<=num.top())
                {
                    t++;
                    sum = (long long)num.top() * (js.top() + t);
                    t+=js.top();
                    if(ans<sum) ans = sum;
                    num.pop();
                    js.pop();
                }
                num.push(cur);
                js.push(t);
            }
        }
        t=0;
        while(!num.empty())
        {
            t++;
            sum = (long long)num.top() * (js.top() + t);
            t+=js.top();
            if(ans<sum) ans = sum;
            num.pop();
            js.pop();
        }
        cout<<ans<<endl;
        scanf("%d",&n);
    }
	return 0;
}

