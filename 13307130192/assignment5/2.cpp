#include <bits/stdc++.h>
#define For(i,l,r) for(int r__=r,i=(l);i<=r__;i++)
using namespace std;
const int mN=1e5+100;
char a[mN];
int lv[129];
//#define ms(x) //cout<<x<<endl
int la;
stack<int> shu;
stack<char> zf;
int doo(char ope,int a,int b)
{
    if (ope=='+')
    {
        return a+b;
    }
    if (ope=='-')
    {
        return a-b;
    }
    if (ope=='*')
    {
        return a*b;
    }
    if (ope=='/')
    {
        return a/b;
    }
    if (ope=='^')
    {
        int now=1;
        For(i,1,b)
            now*=a;
        return now;
    }
}
template<typename T>
void clear(T& a)
{
    while (!a.empty())
        a.pop();
}
int main()
{
 
    lv['#']=0;
    lv['(']=1;
    lv[')']=2;
    lv['+']=lv['-']=3;
    lv['*']=lv['/']=4;
    lv['^']=5;
    while(1)
    {
        clear(shu);
        clear(zf);
        int k=scanf("%s",a+1);
        if (!(k>0))
            break;
//        ms(a+1);
//        ms("scanf="<<k);
        la=strlen(a+1);
        la++;
        a[la]='#';
        int num=0;
        For(i,1,la)
        {
            if (isdigit(a[i]))
            {
                num=num*10+a[i]-'0';
                if (i==la || !isdigit(a[i+1]))
                {
                    shu.push(num);
                    num=0;
                }
            } else
            if (a[i]=='(')
            {
                zf.push(a[i]);
            }
            else
            {
                while (zf.size()>0 && lv[a[i]]<lv[zf.top()] )
                {
                    int a=shu.top();shu.pop();
                    int b=shu.top();shu.pop();
                    shu.push(doo(zf.top(),b,a));
                    zf.pop();
                }
                if (a[i]!='^')
                {
                    while (zf.size()>0 && lv[a[i]]==lv[zf.top()] )
                    {
                        int a=shu.top();shu.pop();
                        int b=shu.top();shu.pop();
                        shu.push(doo(zf.top(),b,a));
                        zf.pop();
                    }
                }
                if (a[i]==')')
                    zf.pop();
                else
                    zf.push(a[i]);
            }
//            ms("i,zf.size(),shu.size()="<<i<<' '<<zf.size()<<' '<<shu.size());

        }
        cout<<shu.top()<<endl;
    }
}
