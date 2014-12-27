#include<iostream>
#include<cstdio>
#include<string>
#include<string.h>
using namespace std;

struct node{
    int fa,de;
    int n;
    int a[400];
}nodes[400];
int m,k,a[400];
int ord[400],sum;
bool f[400];
string s,num;

void dfs(int x){
    printf("(%d",x);
    for(int i=0;i<nodes[x].n;i++){
        printf(" ");
        dfs(nodes[x].a[i]);
    }
    printf(")");
}

int main(){
    while(getline(cin,s))
    if(s=="") printf("(1)\n");
    else{
        m=sum=0;
        memset(a,0,sizeof(a));
        memset(nodes,0,sizeof(nodes));
        memset(f,1,sizeof(f));
        for(int i=0;i<s.size();i++)
        if(s[i]>='0'&&s[i]<='9'&&f[i]){
            num="";
            int j=i;
            while(s[j]>='0'&&s[j]<='9'){
                f[j]=0;
                num+=s[j++];
            }
            k=0;
            for(int j=0;j<=num.size()-1;j++){
                k = k*10 + (num[j]-'0');
            }
            a[k]++;
            ord[sum++]=k;
            if(m<k) m=k;
        }
        memset(f,1,sizeof(f));
        for(int i=0;i<sum;i++){
            for(int j=1;j<=m;j++){
                if(a[j]==0&&f[j]){
                    k=j;
                    f[j]=0;
                    break;
                }
            }
            nodes[k].fa=ord[i];
            nodes[k].de=1;
            a[ord[i]]--;
            nodes[ord[i]].a[nodes[ord[i]].n++]=k;
        }
        for(int i=1;i<=m;i++){
            if(nodes[i].de==0){
                k=i;
                break;
            }
        }
        dfs(k);
        printf("\n");
    }
    return 0;
}