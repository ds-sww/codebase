#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>

using namespace std ;

int n , k ;
int fa[50005] = {} ;
int tag[50005] = {} ;

int Find(int x)
{
    if( fa[x] == x ) return x ;
    int fx = fa[x] ;
    fa[x] = Find(fa[x]) ;
    tag[x] = (tag[x] + tag[fx]) % 3 ;
    return fa[x] ;
}
void Union(int d , int x , int y)
{
     int fx = Find(x) , fy = Find(y) ;
     fa[fy] = fx ;
     tag[fy] = (tag[x]-tag[y]+d+2)%3 ;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int ans = 0 ;
    
    scanf("%d %d",&n,&k);
    for(int i = 1 ; i <= n ; i ++)
    {
            fa[i] = i ;
            tag[i] = 0 ;
    }
    for(int i = 1 ; i <= k ; i ++)
    {
            int d , x , y;
            scanf("%d %d %d",&d,&x,&y);
            
            if( x > n || y > n || (x==y&&d!=1) )
            {
                ans ++ ;
                continue ;
            }
            int fx = Find(x) ;
            int fy = Find(y) ;
            if( fx == fy )
            {
                if( (tag[y] - tag[x] + 3) % 3 != d - 1 )
                    ans ++ ;
            }
            else Union( d , x , y );
    }
    printf("%d",ans);
    return 0;
}
