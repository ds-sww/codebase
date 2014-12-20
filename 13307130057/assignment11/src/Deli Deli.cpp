#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;
int main()
{
    int l,n,i,j,len;
    map<string,string> f;
    string s,s1,s2;
    cin>>l>>n;
    for (i=0;i<l;i++)
    {
        cin>>s1>>s2;
        f[s1]=s2;
    }
    for (i=0;i<n;i++)
    {
        cin>>s;
        if (f.count(s)) cout<<f[s]<<endl;
        else
        {
            len=s.length();
            if (len==1)
            {
                if ((s[0]=='o')||(s[0]=='s')||(s[0]=='x')) cout<<s<<"es"<<endl;
                else cout<<s<<'s'<<endl;
            }
            else
            {
                if ((s[len-1]=='h')&&((s[len-2]=='c')||(s[len-2]=='s'))) cout<<s<<"es"<<endl;
                else if ((s[len-1]=='o')||(s[len-1]=='s')||(s[len-1]=='x')) cout<<s<<"es"<<endl;
                else if ((s[len-1]=='y')&& !((s[len-2]=='a')||(s[len-2]=='o')||(s[len-2]=='i')||(s[len-2]=='e')||(s[len-2]=='u')))
                {
                    for (j=0;j<len-1;j++) cout<<s[j];
                    cout<<"ies"<<endl;
                }
                else cout<<s<<'s'<<endl;
            }
        }
    }
    return 0;
}