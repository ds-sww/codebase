#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
#include<cstring>
using namespace std;
int i,p,t;
struct A{
    int x,y,w;
}L[250010];
struct B{
    int y,w;
    B(int a,int b){y=a;w=b;}
};
vector<B> pre[10010];
int Dist[10010],used[10010];
long long result = 0;
void dfs(int now){//cout<<"^_^"<<endl;
    if(now==0||used[now]==1)return;
    used[now]=1;
    for(int j=0;j<pre[now].size();j++){
        result += pre[now][j].w;
        dfs(pre[now][j].y);
    }
}
int main(){
    cin>>p>>t;
    for(Dist[0]=0,i=1;i<p;i++){
        Dist[i]=-1;
        used[i]=0;
    }
    for(i=0;i<t;i++)
        scanf("%d%d%d",&L[i].x,&L[i].y,&L[i].w);
    stack< pair<int,int> > s;
    s.push(pair<int,int>(0,0));
    int now,ed;
    while(s.empty()==0){
        now=s.top().first;
        ed=s.top().second;
        s.pop();
        if(ed!=Dist[now])continue;
        for(i=0;i<t;i++){
            if(L[i].x==now){
                if(Dist[L[i].y]==-1){
                    Dist[L[i].y]=Dist[now]+L[i].w;
                    pre[L[i].y].clear();
                    pre[L[i].y].push_back(B(L[i].x,L[i].w));
                    s.push(pair<int ,int>(L[i].y,Dist[now]+L[i].w));
                }
                else{
                    if(Dist[L[i].y]>Dist[now]+L[i].w){
                        pre[L[i].y].clear();
                        Dist[L[i].y]=Dist[now]+L[i].w;
                        pre[L[i].y].push_back(B(L[i].x,L[i].w));
                        s.push(pair<int ,int>(L[i].y,Dist[now]+L[i].w));
                    }
                    else if(Dist[L[i].y]==Dist[now]+L[i].w){
                        pre[L[i].y].push_back(B(L[i].x,L[i].w));
                    }
                }
            }
            else if(L[i].y==now){
                if(Dist[L[i].x]==-1){
                    Dist[L[i].x]=Dist[now]+L[i].w;
                    pre[L[i].x].clear();
                    pre[L[i].x].push_back(B(L[i].y,L[i].w));
                    s.push(pair<int ,int>(L[i].x,Dist[now]+L[i].w));
                }
                else{
                    if(Dist[L[i].x]>Dist[now]+L[i].w){
                        pre[L[i].x].clear();
                        Dist[L[i].x]=Dist[now]+L[i].w;
                        pre[L[i].x].push_back(B(L[i].y,L[i].w));
                        s.push(pair<int ,int>(L[i].x,Dist[now]+L[i].w));
                    }
                    else if(Dist[L[i].x]==Dist[now]+L[i].w){
                        pre[L[i].x].push_back(B(L[i].y,L[i].w));
                    }
                }
            }
        }
    }
    now = p - 1;
    dfs(now);
    result*=2;
    cout<<result<<endl;
    return 0;
}
