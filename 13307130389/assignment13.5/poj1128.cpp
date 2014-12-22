#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std ;

char mat[55][55] = {} ;
int n , m ;

int ind[256] = {} ;
bool e[256][256] = {} ;
int pos[256][4] = {} ;
bool valid[256] = {} ;
int tot = 0 ;
char s[30] = {} ;
int anscnt = 0;

bool ins[256] = {} ;
void Dfs( int cur , char u )
{
     s[cur] = u ;
     if( cur == tot - 1 )
     {
         printf("%s\n",s);
         return ;
     }
     for(char v = 'A' ; v <= 'Z' ; v ++) if( valid[v] )
              if( e[u][v] )
                  ind[v] -- ;
     for(char v = 'A' ; v <= 'Z' ; v ++) if( valid[v] && !ins[v] )
              if( ind[v] == 0 )
              {
                  ins[v] = true ;
                  Dfs(cur + 1 , v) ;
                  ins[v] = false ;
              }
     for(char v = 'A' ; v <= 'Z' ; v ++) if( valid[v] )
              if( e[u][v] )
                  ind[v] ++ ;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    while( scanf("%d\n%d\n",&n,&m) == 2 )
    {
    memset( ind , 0 , sizeof(ind) ) ;
    memset( e , 0 , sizeof(e)) ;
    memset(valid,false ,sizeof(valid));
    tot = 0 ;
    memset(s , 0 , sizeof(s)) ;
    anscnt = 0 ;
    
    for(int i = 1 ; i <= n ; i ++)
            scanf("%s\n",mat[i]+1) ;
    
    for(int i = 'A' ; i <= 'Z' ; i ++)
    {
            pos[i][0] = n+1 ; // top 
            pos[i][1] = m+1 ; // left
            pos[i][2] = 0;// bottom
            pos[i][3] = 0;// right
    }
    
    for(int i = 1 ; i <= n ; i ++)
            for(int j = 1 ; j <= m ; j ++)
            {
                    char c = mat[i][j] ;
                    if( c == '.' ) continue ;
                    pos[c][0] = min(pos[c][0],i) ;
                    pos[c][1] = min(pos[c][1],j) ;
                    pos[c][2] = max(pos[c][2],i) ;
                    pos[c][3] = max(pos[c][3],j) ;
                    valid[c] = true ;
            }
    
    for(char i = 'A' ; i <= 'Z' ; i ++) if( valid[i] )
    {
             tot ++ ;
            for(int j = pos[i][1] ; j <= pos[i][3] ; j ++)
            {
                    char v = mat[pos[i][0]][j] ;
                    if( v != '.' && v != i && !e[i][v])
                    {
                        e[i][v] = true ;
                        ind[v] ++ ;
                    }
                    v = mat[pos[i][2]][j] ;
                    if( v != '.' && v != i && !e[i][v])
                    {
                        e[i][v] = true ;
                        ind[v] ++ ;
                    }
            }
            for(int j = pos[i][0] ; j <= pos[i][2] ; j ++)
            {
                    char v = mat[j][pos[i][1]] ;
                    if( v != '.' && v != i && !e[i][v])
                    {
                        e[i][v] = true ;
                        ind[v] ++ ;
                    }
                    v = mat[j][pos[i][3]] ;
                    if( v != '.' && v != i && !e[i][v])
                    {
                        e[i][v] = true ;
                        ind[v] ++ ;
                    }
            }
    }
    
    for(char i = 'A' ; i <= 'Z' ; i ++) if( valid[i] )
    {
             if( ind[i] == 0 )
             {
                 ins[i] = true ;
                 Dfs( 0 , i ) ;
                 ins[i] = false ;
             }
    }
    }
    
    return 0;         
}
