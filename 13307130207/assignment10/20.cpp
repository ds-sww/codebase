#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#define rep(i,a,b) for(int i=a;i<=b;++i)
using namespace std;

int n,m,j,ans,a[200000];

int main(){
    cin>>n>>m;
    rep(i,1,n) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    j=n;
    rep(i,1,n){
        while (j && a[i]+a[j]>m) j--;
        if (j<=i) break;
        ans+=j-i;
    }
    cout<<ans<<endl;
}