#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#define For(i,l,r) for(int i=(l),_r=(r);i<=_r;i++)
#define Rep(i,n) for(int i=0,_n=(n);i<_n;i++)
using namespace std;

int power(int a,int x)
{
    int ans=1;
    while (x>0)
    {
        if (x&1) ans*=a;
        a*=a;
        x>>=1;
    }
    return ans;
}

string s;
stack<char> op_st;
stack<int> num_st;
int speed[300];

int main()
{
    //freopen("1.in","r",stdin);
    speed['(']=-1;
    speed['+']=1;
    speed['-']=1;
    speed['*']=2;
    speed['/']=2;
    speed['^']=3;
    speed[')']=0;
    while (cin >> s)
    {
        while (!op_st.empty()) op_st.pop();
        while (!num_st.empty()) num_st.pop();
        s.push_back(')');
        op_st.push('(');
        int now=0;
        bool renewed=false;
        Rep(i,s.length())
        {
            //cout << 'i' << i << endl;
            if (isdigit(s[i]))
            {
                now=now*10+s[i]-'0';
                renewed=true;
            }
            else if (s[i]=='(')
                op_st.push('(');
            else
            {
                if (renewed)
                {
                    renewed=false;
                    num_st.push(now);
                    now=0;
                }
                while (!op_st.empty() && speed[s[i]]<=speed[op_st.top()] && (s[i]!='^'||op_st.top()!='^'))
                {
                    int num2 = num_st.top();
                    num_st.pop();
                    int num1 = num_st.top();
                    num_st.pop();
                    //cout << num1 << ' '<< num2 << endl;
                    if (op_st.top()=='+')
                        num_st.push(num1+num2);
                    else if (op_st.top()=='-')
                        num_st.push(num1-num2);
                    else if (op_st.top()=='*')
                        num_st.push(num1*num2);
                    else if (op_st.top()=='/')
                        num_st.push(num1/num2);
                    else
                        num_st.push(power(num1,num2));
                    op_st.pop();
                }
                if (s[i]==')')
                    op_st.pop();
                else op_st.push(s[i]);
            }
        }
        cout << num_st.top() << endl;
    }
    return 0;
}
