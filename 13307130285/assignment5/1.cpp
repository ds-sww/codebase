#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define Rehash(a,b,h) ((((h)-(a)*d)<<1)+(b))
int main()
{
    char x[1000],y[1000];
    int xx;
    while(cin>>y)
    {
    xx=0;
    cin>>x;
    int d,hx,hy,i,j,m,n;
    for(m=0;x[m]!='\0';m++);
    for(n=0;y[n]!='\0';n++);
    for(d=i=1;i<m;i++)
    d=d<<1;
    for(hy=hx=i=0;i<m;i++)
    {
    hx=(hx<<1)+x[i];
    hy=(hy<<1)+y[i];
    }
    for(j=0;j<=n-m;j++)
    {
    if((hx==hy)&&(memcmp(x,y+j,m)==0))
    {cout<<j<<" ";xx=1;}
    hy=Rehash(y[j],y[j+m],hy);
    }
    if(xx==0)
    cout<<"-1"<<endl;
    else cout<<endl;
    }
    return 0;
}

