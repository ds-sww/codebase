#include <iostream>
#include <algorithm>
#include <cstring>
#include <stdio.h>

using namespace std;
long long a[30000];
int b[30000];
char s[30];
int n,m;

int CharToInt(char c)
{
    switch(c)
    {
        case 'A':return 0;
        case 'C':return 1;
        case 'G':return 2;
        case 'T':return 3;
    }
}

long long GetInt(char*s)
{
    int i;
    long long ans;
    ans = 0;
    for(i=0;i<m;i++) ans = ans * 4 + CharToInt(s[i]);
    return ans;

}
int main()
{
    int i,ans,j;
    scanf("%d %d",&n,&m);
    while(n!=0 && m!=0)
    {
        for(i=0;i<n;i++)
        {
            scanf("%s",s);
            a[i] = GetInt(s);
        }

    sort(a,a+n);
    memset(b,0,sizeof(b));
    ans = j= 0;
    for(i=0;i<n-1;i++)
    {
        if(a[i] == a[i+1])
        {
            j++;
        }else{
            b[j]++;
            j=0;
        }
    }
    b[j]++;
    for(i=0;i<n;i++) printf("%d\n",b[i]);
    scanf("%d %d",&n,&m);
    }
    return 0;
}
