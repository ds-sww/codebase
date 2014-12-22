#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>

using namespace std ;
const int oo = 99999999 ;

int f[305][305] = {} ;
int n , m , t ;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    scanf("%d %d %d",&n,&m,&t);
    for(int i = 1 ; i <= n ; i ++)
            for(int j = 1 ; j <= n ; j ++)
            {
                    f[i][j] = oo ;
            }
    for(int i = 0 ; i < m ; i ++)
    {
            int u , v , w ;
            scanf("%d %d %d",&u,&v,&w);
            if( f[u][v] > w )
                f[u][v] = w ;
    }
    
    for(int k = 1 ; k <= n ; k ++)
            for(int i = 1 ; i <= n ; i ++)
                    for(int j = 1 ; j <= n ; j ++)
                            if( f[i][j] > max(f[i][k],f[k][j]) )
                                f[i][j] = max(f[i][k],f[k][j]) ;
    
    for(int i = 1 ; i <= t ; i ++)
    {
            int u , v ;
            scanf("%d %d",&u,&v);
            if( f[u][v] < oo )
                printf("%d\n",f[u][v]) ;
            else printf("-1\n");
    }
    
    return 0;
}
