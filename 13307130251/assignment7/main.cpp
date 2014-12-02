#include <iostream>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>

using namespace std;
int a[100000];
int b[100000];
int main()
{
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
    cin>>a[i];
    b[i]=0;
    }
    for(int i=N-2;i>=0;i--)
    {
        for(int j=i+1;j<=N-1;)
        {
                if(a[i]<=a[j])
                break;
                else
                {
                    b[i]+=b[j]+1;
                    j=j+b[j]+1;
                }

        }
    }
    long long sum;
    sum=0;
    for(int i=0;i<N;i++)sum+=b[i];
    cout<<sum<<endl;
}
