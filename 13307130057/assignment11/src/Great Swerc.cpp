#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
struct node
{
    char name;
    int num,head;
}a[10];
int t[10],sum,n,m;
string s[10];
void work(int x)
{
    if (x==0)
    {
        long long tot,number;
        tot=0;
        for (int i=0;i<n;i++)
        {
            number=0;
            for (int j=0;j<s[i].length();j++)
                for (int k=0;k<m;k++)
                    if (s[i][j]==a[k].name)
                    {
                        number=number*10+a[k].num;
                        break;
                    }
            if (i<n-1) tot=tot+number;
        }
        if (tot==number) sum++;
        return;
    }
    for (int i=0;i<10;i++)
    {
        if ((t[i]==0)&& !((i==0)&&(a[x-1].head==0)))
        {
            a[x-1].num=i;
            t[i]=1;
            work(x-1);
            t[i]=0;
        }
    }
}
int main()
{
    cin>>n;m=0;
    for (int i=0;i<n;i++)
    {
        cin>>s[i];
        for (int j=0;j<s[i].length();j++)
        {
            int tf=1;
            for (int k=0;k<m;k++)
                if (a[k].name==s[i][j])
                {
                    tf=0;
                    break;
                }
            if (tf)
            {
                a[m].name=s[i][j];
                a[m].num=0;
                a[m].head=j;
                m++;
            }
        }
    }
    sum=0;
    work(m);
    cout<<sum<<endl;
    return 0;
}