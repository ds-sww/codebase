#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<stack>
#define maxn 1111111
using namespace std;
int pri0[257],pri1[257];
stack<char> stk;
stack<int> stk2;
char c,s[maxn];
int len,cnt,a[maxn],b[maxn];
void pre()
{
    for (int i=0;i<257;i++) pri0[i]=pri1[i]=-1;
    pri0['^']=3; pri0['*']=2; pri0['/']=2; pri0['+']=1; pri0['-']=1; pri0['(']=0;
    pri1['^']=4; pri1['*']=2; pri1['/']=2; pri1['+']=1; pri1['-']=1;
}
int main()
{
    c=getchar();
    pre();
    while (c!=EOF)
    {
        len=0; s[len++]=c;
        for (c=getchar();c!='\n';c=getchar()) s[len++]=c;
        while (!stk.empty()) stk.pop();
        cnt=0;
        int i=0;
        while (i<len)
        {
            if (s[i]=='(')
            {
                stk.push('(');
            }
            else if (pri1[s[i]]!=-1)
                 {
                    while (!stk.empty() && pri1[s[i]]<=pri0[stk.top()])
                    {
                        a[cnt]=stk.top();
                        b[cnt++]=0;
                        stk.pop();
                    }
                    stk.push(s[i]);
                 }
                 else if (s[i]==')')
                      {
                          while (!stk.empty())
                          {
                              char s1=stk.top();
                              if (s1=='(') { stk.pop(); break; }
                              a[cnt]=s1;
                              b[cnt++]=0;
                              stk.pop();
                          }
                      }
                      else
                      {
                          int num=s[i]-'0';
                          while (i+1<len && s[i+1]>='0' && s[i+1]<='9') { num=num*10+s[i+1]-'0'; i++; }
                          a[cnt]=num;
                          b[cnt++]=1; //number;
                      }
            i++;
        }
        while (!stk.empty())
        {
            char s1=stk.top();
            if (s1=='(') { stk.pop(); break; }
            a[cnt]=s1;
            b[cnt++]=0;
            stk.pop();
        }
        int ans=0;
        for (int i=0;i<cnt;i++)
        {
            if (b[i]==1) stk2.push(a[i]);
                else {
                        int y=stk2.top();
                        stk2.pop();
                        int x=stk2.top();
                        stk2.pop();
                        int res;
                        if (a[i]=='+') res=x+y;
                            else if (a[i]=='-') res=x-y;
                                    else if (a[i]=='*') res=x*y;
                                            else if (a[i]=='/') res=x/y;
                                                    else res=pow(x,y);
                        stk2.push(res);

                     }
        }
        printf("%d\n",stk2.top());
        stk2.pop();
        c=getchar();
    }
    return 0;
}