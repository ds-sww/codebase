#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<vector>

const int MAXN = 100001;
const int END = 0 ;
const int OK = 1 ;
const int FAIL = 2 ;


using namespace std ;

int parent[MAXN] = {} ;
bool vis[MAXN] = {} ;
bool inqueue[MAXN] = {} ;
int fanin[MAXN] = {} ;
vector<int> *edge ;
int n , usedn ;
int root = 0 ;
int queue[MAXN] = {} , head = 1 , tail = 0 ;

int init()
{
    int tag = OK , fanin0cnt = 0 ;
    head = 1 ; tail = 0 ;
    n = 0 ; usedn = 0 ;
    root = 0 ;
    memset( vis , 0 , sizeof(vis)) ;
    memset( parent , 0 , sizeof(parent)) ;
    memset( inqueue , false , sizeof(inqueue) ) ;
    memset( fanin , 0 , sizeof(fanin)  ) ;
    
    delete [] edge ;
    edge = new vector<int>[MAXN];
    
    int x , y ;
    while( scanf("%d %d",&x,&y) == 2 )
    {
           if( x < 0 && y < 0 )
               return END ;
           if( x == 0 && y == 0 )
               break ;
           vis[x] = vis[y] = true ;
           edge[x].push_back(y) ;
           if( parent[y] || x == y ) tag = FAIL ;
           parent[y] = x ;
           fanin[y] ++ ;
           if( n < x ) n = x ;
           if( n < y ) n = y ;
    }
    if( tag == FAIL ) return FAIL ;
    for( int i = 1 ; i <= n ; i ++) if( vis[i] )
    {
         usedn ++ ;
         if( fanin[i] == 0 )
         {
             root = i ;
             fanin0cnt ++ ;
         }
    }
    if( fanin0cnt != 1 ) return FAIL ;
    return OK ;
}

int Bfs()
{
     int reached = 0 ,x , y ;
     queue[++ tail] = root ;
     inqueue[root] = true ;
     while( head <= tail )
     {
            x = queue[ head ] ;
            reached ++ ;
            for( int i = 0 ; i < edge[x].size() ; i ++ )
            {
                 y = edge[x][i] ;
                 if( inqueue[y] ) return -1 ;
                 queue[++ tail] = y ;
                 inqueue[y] = true ;
            }
            head ++ ;
     }
     return reached ;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int status , cas = 0 ;
    while( 1 )
    {
           status = init() ;
           if( status == END ) break ;
           cas ++ ;
           if( n == 0 )
           {
               printf("Case %d is a tree.\n",cas);
               continue;
           }
           if( status == FAIL )
           {
               printf("Case %d is not a tree.\n",cas);
               continue ;
           }
           if( Bfs() == usedn )
               printf("Case %d is a tree.\n",cas);
           else
               printf("Case %d is not a tree.\n",cas);
    }
    return 0;
}
