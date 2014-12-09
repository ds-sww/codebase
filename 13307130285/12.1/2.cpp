#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int a[30000];
int sum=0;
int N,S;
int main()
{
    int j,x,y;
    cin>>N>>S;
    for(int i=0;i<N;i++)
       scanf("%d",a+i);
    sort(a,a+N);
    for(j=N-1;j>0;j--)
      if(a[j]+a[j-1]<=S)
    break;
    sum=j*(j+1)/2;
    y=j;
    for(x=j-1;x>=0;x--)
    {
        for(;y<N;y++)
        if(a[x]+a[y]>S)
        {
        sum+=y-j-1;
        break;
        }
        if(y==N)
        sum+=N-j-1;
    }
    cout << sum << endl;
    return 0;
}
