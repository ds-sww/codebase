#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int D[505][2],f[505];
int i,j,k,n,s,p;
struct A{
    int x,y;
    double w;
}L[250010];
bool fin(A x,A y){
    return x.w<=y.w;
}
int find(int m){
    if(m==f[m])return m;
    return f[m]=find(f[m]);
}
void kru(){
    int done;
    double cnt[p];
    for(i=done=0;i<k;i++){
        int fx=find(L[i].x),fy=find(L[i].y);
        if(fx!=fy){
            f[fx]=fy;
            cnt[done]=L[i].w;
            done++;
        }
        if(done==p-1)break;
    }
    printf("%.2f\n",cnt[done-s]);
}
int main(){
    scanf("%d",&n);
    for(;n>0;n--){
        scanf("%d%d",&s,&p);
        for(i=0;i<p;i++){
            scanf("%d%d",&D[i][0],&D[i][1]);
            f[i]=i;
        }
        for(i=k=0;i<p;i++){
            for(j=0;j<i;j++){
                L[k].x=i;
                L[k].y=j;
                L[k].w = sqrt((D[i][0]-D[j][0])*(D[i][0]-D[j][0])+(D[i][1]-D[j][1])*(D[i][1]-D[j][1]));
                k++;
            }
        }
        sort(L,L+k,fin);
        kru();
    }
    return 0;
}