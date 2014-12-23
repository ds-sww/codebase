#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<queue>

using namespace std ;

typedef pair<int,int> Edge ;

vector<Edge> e[10005] ;

const int oo = 99999999 ;

int dis[10005] = {} ;

int n , m ;
int ans = 0 ;
void SPFA()
{
	for(int i = 0 ; i < n ; i ++)
		dis[i] = oo ;
	queue<int> q ;
	q.push(0) ;
	dis[0] = 0 ;
	while( !q.empty() )
	{
		int u = q.front() ; q.pop() ;
		for(vector<Edge>::iterator it = e[u].begin() ; it != e[u].end() ; it ++)
		{
			int v = it->second , w = it->first ;
			if( dis[v] > dis[u] + w )
			{
				dis[v] = dis[u] + w ;
				q.push(v) ;
			}
		}
	}
	
}

void Bfs()
{
	bool inq[10005] = {} ;
	queue<int> q ;
	q.push(n-1);
	while(!q.empty() )
	{
		int v = q.front() ; q.pop() ;
		for(vector<Edge>::iterator it = e[v].begin() ; it != e[v].end() ; it ++)
		{
			int u = it->second , w = it->first ;
			if( dis[u] + w == dis[v] )
			{
				ans += w ;
				if(!inq[u])
				{
					q.push(u);
					inq[u] = true ;
				}
			}
		}
	}
}

void addedge(int u , int v , int w )
{
	e[u].push_back(make_pair(w,v)) ;
	e[v].push_back(make_pair(w,u)) ;
}

int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	
	scanf("%d %d",&n,&m);
	
	for(int i = 1 ; i <= m ; i ++)
	{
		int u , v , w ;
		scanf("%d %d %d",&u,&v,&w);
		addedge(u,v,w) ;
	}
	
	SPFA() ;
	Bfs() ;
	
	printf("%d",ans<<1);
	
	return 0;
}
