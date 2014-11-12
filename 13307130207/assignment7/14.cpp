#include<iostream>
#include<cstdio>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
using namespace std;

int n,t,a[100000],q[100000];
long long ans;

int main(){
    cin>>n;
    rep(i,1,n) scanf("%d",&a[n+1-i]);
    ans=t=0;
    rep(i,1,n){
        while (t && a[q[t]]<a[i]) t--;
        ans=ans+i-q[t]-1;
        q[++t]=i;
    }
    cout<<ans<<endl;
}