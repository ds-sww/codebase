#include <iostream>
#include <cstdio>
using namespace std;
int n,m;
void work(int x)
{
    m++;
    if (m==n)
    {
        cout<<x<<endl;
        return;
    }
    cout<<x<<' ';
    if (x*2<=n) work(x*2);
    if (x*2+1<=n) work(x*2+1);
}
int main()
{
    while ((cin>>n)&&(n))
    {
        m=0;
        work(1);
    }
    return 0;
}