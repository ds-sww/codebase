#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<sstream>

using namespace std ;

int n , k ;
int fa[50005] = {} , tag[50005] = {} ;

int find( int x )
{
        if( fa[x] == x ) return x ;
        int t = fa[x] ;
        fa[x] = find(fa[x]) ;
        tag[x] = (tag[x] + tag[t])%3 ;
        return fa[x];
}

void merge(int d , int x ,int y )
{
        int fx = find(x) ;
        int fy = find(y) ;
        fa[fy] = fx ;
        tag[fy] = (tag[x]-tag[y]+d-1+3)%3 ;
}

int main()
{
        int ans = 0 ;
        scanf("%d %d",&n,&k);
        for(int i = 1 ; i <= n ; i ++)
        {
                tag[i] = 0 ;
                fa[i] = i ;
        }
        
        for(int i = 1 ; i <= k ; i ++)
        {
                int d , x , y ;
                scanf("%d %d %d",&d,&x,&y) ;
                if( x > n || y > n || (x==y&&d!=1) )
                {
                        ans ++ ;
                        continue ;
                }
                int fx = find(x) , fy = find(y) ;
                if( fx == fy )
                {
                        if( (tag[y]-tag[x]+3)%3 != d - 1 ) ans ++ ;
                }
                else merge(d,x,y);
        }
        printf("%d",ans);
        return 0;
}

