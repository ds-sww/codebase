#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<stack>
using namespace std;
#define Rep(i,n) for (int n__=(n),i=0;i<n__;i++)
#define For(i,l,r) for (int r__=(r),i=(l);i<=r__;i++)
stack<int> stk_num;
stack<char> stk_sig;
char s[20000];
int n,tp,a,b;
char c;
int calc(int u,int v,char c)
{
    if (c=='+') return v+u;
    if (c=='-') return v-u;
    if (c=='*') return v*u;
    if (c=='/') return v/u;
    int tp=1;
    Rep(i,u) tp*=v;
    return tp;
}

int pr(char u)
{
    if (u=='^') return 3;
    if (u=='*'||u=='/') return 2;
    if (u=='+'||u=='-') return 1;
    if (u=='(') return 0;
}

int main()
{
    freopen("1.in","r",stdin);
    while (scanf("%s",s)==1)
    {
        while (!stk_num.empty()) stk_num.pop();
        while (!stk_sig.empty()) stk_sig.pop();
        tp=0;
        stk_sig.push('(');
        int n=strlen(s);
        s[n]=')';
        Rep(i,n+1)
        {
            if (s[i]<='9'&&s[i]>='0')
            {
                if (tp==-1) tp=s[i]-'0';
                    else tp=tp*10+s[i]-'0';
            }
            else
            {
                if (s[i]=='(') stk_sig.push(s[i]);
                else
                if (s[i]==')')
                {
                    if (tp!=-1) stk_num.push(tp);
                    while (stk_sig.top()!='(')
                    {
                        a=stk_num.top(); stk_num.pop();
                        b=stk_num.top(); stk_num.pop();
                        c=stk_sig.top(); stk_sig.pop();
                        stk_num.push(calc(a,b,c));
                    }
                    stk_sig.pop();
                } else
                {
                    if (s[i]=='+'||s[i]=='-')
                    {
                        if (tp>-1) stk_num.push(tp);
                        while (pr(stk_sig.top())>=1)
                        {
                            a=stk_num.top(); stk_num.pop();
                            b=stk_num.top(); stk_num.pop();
                            c=stk_sig.top(); stk_sig.pop();
                            stk_num.push(calc(a,b,c));
                        }
                        stk_sig.push(s[i]);
                    } else
                    if (s[i]=='*'||s[i]=='/')
                    {
                        if (tp>-1) stk_num.push(tp);
                        while (pr(stk_sig.top())>=2)
                        {
                            a=stk_num.top(); stk_num.pop();
                            b=stk_num.top(); stk_num.pop();
                            c=stk_sig.top(); stk_sig.pop();
                            stk_num.push(calc(a,b,c));
                        }
                        stk_sig.push(s[i]);
                    } else
                    if (s[i]=='^')
                    {
                         stk_sig.push(s[i]);
                        if (tp>-1) stk_num.push(tp);
                    }
                }
                tp=-1;
            }
        }

        printf("%d\n",stk_num.top());
    }
    return 0;
}
