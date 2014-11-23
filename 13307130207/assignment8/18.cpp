#include<cstdio>
#include<iostream>
#define rep(i,a,b) for(int i=a;i<=b;++i)
using namespace std;

int n;

void dfs(int p){
    if (p>n) return;
    if (p>1) printf(" ");
    printf("%d",p);
    dfs(p*2); dfs(p*2+1);
}

int main(){
    while (scanf("%d",&n),n){
        dfs(1);
        puts("");
    }
}