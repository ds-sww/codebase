#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

string doit(string pre, string in)
{
    int n = pre.length();
    string rt = pre.substr(0,1);
    if (n <= 1) return rt;

    string leftin, leftpre, rightin, rightpre;


    for (int i = 0; i < n; i++)
    if (in[i] == rt[0])
    {
        leftin = in.substr(0, i);
        rightin = in.substr(i + 1, n - i -1);
        leftpre = pre.substr(1, leftin.length());
        rightpre = pre.substr(leftin.length() + 1, n - leftin.length() - 1);
        //cout<<leftin<<" "<<rightin<<" "<<leftpre<<" "<<rightpre<<endl;
        break;

    }
    string ret;
    ret = doit(leftpre, leftin);
    ret += doit(rightpre, rightin);
    ret += rt;
    return ret;
}



int main()
{
   // freopen("a.in", "r", stdin);

    string preord,inord;
    while (cin>>preord>>inord) cout<<doit(preord, inord)<<endl;



    return 0;
}