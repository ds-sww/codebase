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

string s[100000];
char ss[100];
int n,m,x,cnt[100000];

int main(){
    while(cin>>n>>m,n&&m){
        getchar();
        rep(i,1,n){
            gets(ss);
            s[i]=ss;
            cnt[i]=0;
        }
        sort(s+1,s+n+1);
        int x=0;
        rep(i,1,n){
            if (s[i]!=s[i-1]){
                cnt[x]++;
                x=1;
            }
            else x++;
        }
        cnt[x]++;
        rep(i,1,n) printf("%d\n",cnt[i]);
    }
}