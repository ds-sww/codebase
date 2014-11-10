# include <cstdio>
# include <cstring>
# include <algorithm>
# include <cstdlib>
# include <queue>
using namespace std;
typedef pair<int,int> pii;
int n,m;
int map[100][100],dep[100][100];
int mv[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

void bfs(int sx,int sy){
	memset(dep,0x7F,sizeof(dep));
	dep[sx][sy]=0;
	queue< pii > q;
	q.push(pii(sx,sy));
	while(!q.empty()){
		pii t=q.front();q.pop();
		int x=t.first,y=t.second;
		for(int i=0;i<4;i++){
			int ox=x+mv[i][0],oy=y+mv[i][1];
			if(map[ox][oy]&&dep[ox][oy]>10000){
				dep[ox][oy]=dep[x][y]+1;
				q.push(pii(ox,oy));
			}
		}
	}
}

int sx,sy,tx,ty,dx,dy,kx,ky,d,k;
int main(){
	scanf("%d %d",&n,&m);

	for(int i=1;i<=n;i++){
		char s[100];scanf("%s",s);
		for(int j=0;j<m;j++){
			map[i][j+1]=1;
			if(s[j]=='S'){
				sx=i;sy=j+1;
			}else if(s[j]=='T'){
				tx=i;ty=j+1;
			}else if(s[j]=='*'){
			}else if(s[j]=='D'){
				d=1;
				dx=i;dy=j+1;
				map[i][j+1]=0;
			}else if(s[j]=='K'){
				k=1;
				kx=i;ky=j+1;
			}else{
				map[i][j+1]=0;
			}
		}
	}
	bfs(sx,sy);
	if(d&&k){
		int ans=dep[tx][ty];
		int a=dep[kx][ky];
		map[dx][dy]=1;
		bfs(kx,ky);
		int b=dep[tx][ty];
		ans=min(ans,a+b);
		if(ans>10000){
			printf("-1\n");
		}else{
			printf("%d\n",ans);
		}
	}else{
		if(dep[tx][ty]>10000){
			printf("-1\n");
		}else{
			printf("%d\n",dep[tx][ty]);
		}
	}
	return 0;
}
