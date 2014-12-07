#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define For(i,a) for(int i=0;i<a;++i)
using namespace std;
typedef long long ll;

const ll oo=100000000000;
int cas,ca,n;
ll l,r,ans,num;

inline int check(ll m){
    int j=1,k=n;
    ll cnt=0;
    rep(i,1,n){
        while (j<=n && 1ll*i*i+100000ll*(i-j)+1ll*j*j+1ll*i*j>m) j++;
        while (k && 1ll*i*i+100000ll*(i-k)+1ll*k*k+1ll*i*k>m) k--;
        if (k<j) break;
        cnt=cnt+k-j+1;
    }
    return cnt>=num;
}

int main(){
    scanf("%d",&cas);
    rep(ca,1,cas){
        scanf("%d%lld",&n,&num);
        l=-oo; r=oo;
        while (l<=r){
            ll m=(l+r)/2;
            if (m==r && m>l) m=l;
            if (check(m)){
                ans=m;
                r=m-1;
            }
            else l=m+1;
        }
        printf("%lld\n",ans);
    }
}