#include<cstdio>
#include<iostream>
#include<cstring>
#define rep(i,a,b) for(int i=a;i<=b;++i)
using namespace std;

char a[100],b[100];

void dfs(char* a,char* b,int l){
    if (l<1) return;
    int m=strchr(b,a[0])-b;
    dfs(a+1,b,m);
    dfs(a+1+m,b+1+m,l-m-1);
    printf("%c",a[0]);
}

int main(){
    while (scanf("%s%s",a,b)!=EOF){
        dfs(a,b,strlen(a));
        puts("");
    }
}