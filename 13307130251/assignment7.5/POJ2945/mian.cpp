#include <iostream>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>

using namespace std;
int change(string &s,int i)
{
    if(s[i]=='A')return 0;
    if(s[i]=='T')return 1;
    if(s[i]=='G')return 2;
    if(s[i]=='C')return 3;
}
int range(string &s,int m)
{
    int sum,n;
    sum=0;
    n=1;
    for(int i=0; i<m; i++,n*=4)
        sum+=change(s,i)*n;
    return sum;
}
int a[100000];
int b[100000];
int main()
{
    while(true)
    {
        int n,m;
        cin>>n>>m;
        if(m==0&&n==0)break;
        string s;
        for(int i=0; i<n; i++)
        {
            cin>>s;
            a[i]=range(s,m);
            //cout<<a[i]<<endl;
            b[i]=0;
        }
        sort(a,a+n);
        for(int i=0; i<n; i++)
        {
            int key=1;
            while(a[i]==a[i+1])
            {
                key++;
                i++;
            }
            b[key-1]++;
        }
        for(int i=0; i<n; i++)cout<<b[i]<<endl;
    }
}
