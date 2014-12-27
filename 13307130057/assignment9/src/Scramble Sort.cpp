#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
    string s,ss[1000],st[1000];
    int len,a[1000],t[1000];
    cin>>s;
    while (s!=".")
    {
        len=s.length();
        if (s[len-1]=='.')
        {
            cout<<s<<endl;
            cin>>s;
        }
        else
        {
            int n=0;
            while (s[len-1]!='.')
            {
                n++;
                if ((s[len-2]>=48)&&(s[len-2]<=57))
                {
                    int x=0;
                    if (s[0]!='-') 
                        for (int i=0;i<len-1;i++) x=x*10+s[i]-48;
                    else 
                        for (int i=1;i<len-1;i++) x=x*10+s[i]-48;
                    if (s[0]!='-') a[n-1]=x;
                    else a[n-1]=-x;
                    t[n-1]=0;
                }
                else
                {
                    ss[n-1]="";st[n-1]="";
                    for (int i=0;i<len-1;i++)
                    {
                        if ((s[i]>=65)&&(s[i]<=90)) 
                            st[n-1]=st[n-1]+(char)(s[i]+32);
                        else st[n-1]=st[n-1]+s[i];
                        ss[n-1]=ss[n-1]+s[i];
                    }
                    t[n-1]=1;
                }
                cin>>s;
                len=s.length();
            }
            n++;
            if ((s[len-2]>=48)&&(s[len-2]<=57))
            {
                int x=0;
                if (s[0]!='-') 
                    for (int i=0;i<len-1;i++) x=x*10+s[i]-48;
                else 
                    for (int i=1;i<len-1;i++) x=x*10+s[i]-48;
                if (s[0]!='-') a[n-1]=x;
                else a[n-1]=-x;
                t[n-1]=0;
            }
            else
            {
                ss[n-1]="";st[n-1]="";
                for (int i=0;i<len-1;i++)
                {
                    if ((s[i]>=65)&&(s[i]<=90)) 
                        st[n-1]=st[n-1]+(char)(s[i]+32);
                    else st[n-1]=st[n-1]+s[i];
                    ss[n-1]=ss[n-1]+s[i];
                }
                t[n-1]=1;
            }
            for (int i=0;i<n-1;i++)
                for (int j=i+1;j<n;j++)
                    if (t[i]==t[j])
                    {
                        if (t[i])
                        {
                            if (st[i]>st[j])
                            {
                                string s0;
                                s0=st[i];st[i]=st[j];st[j]=s0;
                                s0=ss[i];ss[i]=ss[j];ss[j]=s0;
                            }
                        }
                        else
                        {
                            if (a[i]>a[j])
                            {
                                int temp;
                                temp=a[i];a[i]=a[j];a[j]=temp;
                            }
                        }
                    }
            for (int i=0;i<n-1;i++)
            {
                if (i) cout<<' ';
                if (t[i]) cout<<ss[i]<<',';
                else cout<<a[i]<<',';
            }
            if (t[n-1]) cout<<' '<<ss[n-1]<<'.'<<endl;
            else cout<<' '<<a[n-1]<<'.'<<endl;
            cin>>s;
        }
    }
    return 0;
}