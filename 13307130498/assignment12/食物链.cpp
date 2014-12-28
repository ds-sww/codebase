#include<iostream>
#include<cstdio>
using namespace std;
int n,k,cnt;
int f[50005],ran[50005];
void inti(){
    for(int i=1;i<=n;i++){
        f[i]=i;
        ran[i]=0;
    }
}
int find(int m){
    if(f[m]==m)return m;
    int of = f[m];
    f[m] = find(f[m]);
    ran[m]=(ran[m]+ran[of])%3;
    return f[m];
}
void uni(int d,int x,int y){
    int fx=find(x),fy=find(y);
    if(fx==fy)return;
    f[fx]=fy;
    ran[fx]=(ran[y]+d-1-ran[x]+3)%3;
}
bool jud(int d,int x,int y){
    if(x>n||y>n||((x==y)&&(d==2)))return 0;
    int fx=find(x),fy=find(y);
    if(fx!=fy)return 1;
    if(ran[x]==(ran[y]+d-1)%3)return 1;
    else return 0;
}
int main(void){
    cin>>n>>k;
    int x,y,d;
    inti();
    for(cnt=0;k>0;k--){
        scanf("%d%d%d",&d,&x,&y);
        if(jud(d,x,y)==0)
            cnt++;
        else
            uni(d,x,y);
    }
    cout<<cnt<<endl;
    return 0;
}