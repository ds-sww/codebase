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

int noderef[1005] = {} ;
int root ;
int n = 0 ;
int nowpos = 1 ;
int fa[1005] = {} ;
int son[1005][1005] = {} ;
bool isleaf[1005]= {} ;
bool vis[1005] = {} ;

void Dfs( int rt )
{
        int soncnt = son[rt][0] ;
        if( root == rt ) printf("(%d",rt) ;
        else printf(" (%d",rt) ;
        for( int i = 1; i <= soncnt ; i ++ )
        {
                int tson = son[rt][i];
                Dfs(tson) ;      
        }
        printf(")");
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
        char ch[1005] = {} ;
        while( gets(ch) )
        {
                memset( fa , 0 , sizeof(fa)) ;
                memset( son, 0 , sizeof(son)) ;
                memset( isleaf , false ,sizeof(isleaf)) ;
                memset( vis , false , sizeof(vis)) ;
                n = 0 ; nowpos = 1 ;
                
                int j = 0;
                int num = 0 ;
                int len = strlen(ch) ;
                for( j = 0 ; j < len ; j ++)
                {
                        if( ch[j] == ' ')
                        {
                                noderef[n++] = num ;
                                num = 0 ;
                        }
                        else
                        {
                                num = num*10 + ch[j] - '0' ;
                        }
                }
                noderef[n++] = num ;
                for( int i = 0 ; i < n ; i ++)
                {
                        int nd = noderef[i] ;
                        for( j = 1 ; j <= n + 1 ; j ++)
                                if( !vis[j] )
                        {
                                int k ;
                                for( k = i ; k < n ; k ++)
                                        if( noderef[k] == j )
                                                break ;
                                if( k == n )
                                {
                                        isleaf[j] = true ;
                                }       
                        }
                        for( nowpos = 1 ; nowpos <= n + 1 ; nowpos ++)
                                if( isleaf[nowpos] && !vis[nowpos] )
                                {
                                        vis[nowpos] = true ;
                                        break ;
                                }
                        fa[nowpos] = nd ;
                        son[nd][ ++ son[nd][0]] = nowpos ;
                }
                for( int i = 1 ; i <= n + 1; i ++)
                        if( fa[i] == 0 )
                        {
                                root = i ;
                                break ;
                        }
                Dfs( root );
                printf("\n");
        }
                        
        return 0;
}
