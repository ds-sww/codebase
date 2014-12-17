#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
    string s,s1,s2,q[2000],a[1000][2];
    int n,i,j,now,top,k,len,p,tf;
    for (i=0;i<2000;i++) q[i]="";
	cin>>s;
    for (i=1;i<s.length()-1;i++)
        q[0]=q[0]+s[i];
    i=0;
    while (cin>>s)
    {
        j=1;s1="";s2="";
        while (s[j]!='"')
        {
            s1=s1+s[j];
            j++;
        }
        j=j+4;
        while (s[j]!='"')
        {
            s2=s2+s[j];
            j++;
        }
        a[i][0]=s1;
        a[i][1]=s2;
        i++;
    }
    n=i;now=0;top=0;
    while ((q[now]!="")&&(top<1000))
    {
        len=q[now].length();
        for (i=0;i<len;i++)
            for (j=0;j<len;j++)
            {
                s="";
                for (k=i;k<=j;k++)
                    s=s+q[now][k];
                for (p=0;p<n;p++)
                    if (a[p][0]==s)
                    {
                        s1="";
                        for (k=0;k<i;k++)
                            s1=s1+q[now][k];
                        s1=s1+a[p][1];
                        for (k=j+1;k<len;k++)
                            s1=s1+q[now][k];
                        if (s1.length()>80)
						{
							cout<<"Too many."<<endl; 
							return 0;
						}
                        tf=1;
                        for (k=0;k<=top;k++)
                            if (s1==q[k])
                            {
                                tf=0;break;
                            }
                        if (tf)
                        {
                            top++;
                            q[top]=s1;
                        }
                    }
            }
        now++;
    }
    if (top<1000) cout<<top+1<<endl;
    else cout<<"Too many."<<endl;
    return 0;
}