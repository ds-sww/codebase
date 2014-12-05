#include <iostream>
#include <stdio.h>

using namespace std;

int p[101];
bool flag[101];

void make_set(){
    for (int i=0; i<101;++i){
        p[i]=i;
        flag[i]=false;
    }
}

int find_set(int x){
    return (p[x]==x)? x : (p[x]=find_set(p[x]));
}

void union_set(int x, int y){
    x=find_set(x);
    y=find_set(y);
    if(x==y)    return;
    p[y]=x;
}

int main(){
    int x, y ,first, t=1;
    while(scanf("%d%d",&x,&y)!=EOF){
        if(x==-1 && y==-1)  break;
        if(x==0 && y==0){
            printf("Case %d is a tree.\n",t++);
            continue;
        }
        make_set();
        first=x;
        bool isTree=true;
        flag[x]=flag[y]=true;
        if(x==y)
            isTree=false;
        else
            union_set(x,y);
        while(scanf("%d%d",&x,&y)&& x!=0){
            flag[x]=flag[y]=true;
            if(find_set(x)==find_set(y))
                isTree=false;

             union_set(x,y);
        }
        for(int i=1;i<101;i++){
            if(flag[i] &&find_set(i)!=find_set(first)){
                isTree=false;
                break;
		}
        }
        if(isTree)  printf("Case %d is a tree.\n",t++);
        else printf("Case %d is not a tree.\n",t++);
    }
    return 0;
}
