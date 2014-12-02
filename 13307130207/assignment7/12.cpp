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

int cas,n,m,ans,a[100000];

int main(){
    cin>>cas;
    rep(ca,1,cas){
        scanf("%d%d",&m,&n);
        rep(i,1,n) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        per(i,n,0){
            if (m<=0){
                ans=n-i;
                break;
            }
            m-=a[i];
        }
        printf("Scenario #%d:\n",ca);
        if (m>0) printf("impossible\n");
        else printf("%d\n",ans);
        printf("\n");
    }
}