#include<cstdio>
#include<iostream>
#include<cstring>
#define rep(i,a,b) for(int i=a;i<=b;++i)
using namespace std;

int ans,m,c[30][30];
char a[100],b[100];

void ask(char* a,char* b,int l){
    if (l<1) return;
    int k=0,p=0;
    while(p<l){
        int t=strchr(b,a[p])-b;
        ask(a+p+1,b+p,t-p);
        p=t+1;
        k++;
    }
    ans*=c[m][k];
}

int main(){
    rep(i,0,20) c[i][0]=1;
    rep(i,1,20) rep(j,1,i) c[i][j]=c[i-1][j-1]+c[i-1][j];

    while(scanf("%d",&m),m){
        scanf("%s%s",a,b);
        ans=1;
        ask(a+1,b,strlen(a)-1);
        printf("%d\n",ans);
    }
}