#include<cstdio>
#include<cstring>
#include<cstdlib>

#define oo 2147483647

using namespace std ;

int ans_s_to_key = 0 , ans_key_to_door = 0 , ans_door_to_t = 0;
int ans_s_to_t = 0 ;
char map[30][30] = {} ;
bool vis[30][30] = {} ;
int n ,m ;
int q[500][3] = {} ;
int startx = 0 , starty = 0 , endx = 0 , endy = 0 , keyx = 0 , keyy = 0 ;
int doorx = 0 , doory = 0 ;
void init()
{
     scanf("%d %d\n",&n,&m);
     for( int i = 1 ; i <= n ; i ++)
     {
          for( int j = 1 ; j <= m ; j ++)
          {
               scanf("%c",&map[i][j]);
               if( map[i][j] == 'K' )
               {   keyx = i ; keyy = j ; }
               else if( map[i][j] == 'S')
               {   startx = i ; starty = j ; }
               else if( map[i][j] == 'T')
               {   endx = i ; endy = j ; }
               else if( map[i][j] == 'D')
               {   doorx = i ; doory = j ;}
          }
          getchar();
     }
}

bool check( int x , int y , bool usekey )
{
     if( vis[x][y] == true ) return false ;
     if( !usekey && map[x][y] == 'D' ) return false ;
     if( x <= 0 || x > n || y <= 0 || y > n ) return false ;
     if( map[x][y] == '#' ) return false ;
     return true ;
}

int Bfs( int sx , int sy , int ex , int ey , bool usekey)
{
    memset( q , 0 , sizeof(q)) ;
    memset( vis , false , sizeof(vis)) ;
    int head = 0 , tail = 0 ;
    q[++tail][0] = sx ; q[tail][1] = sy ;q[tail][2] = 0 ;
    
    while( head < tail )
    {
           head ++ ;
           int tx , ty , tval ;
           tx = q[head][0] ; ty = q[head][1] ; tval = q[head][2] ;
           vis[tx][ty] = true ;
           if( tx == ex && ty == ey ) return q[head][2] ;
           if( check( tx - 1 , ty , usekey) )
           {
               q[++tail][0] = tx - 1 ;
               q[tail][1] = ty ;
               q[tail][2] = tval + 1 ;
           }
           if( check( tx + 1 , ty , usekey) )
           {
               q[++tail][0] = tx + 1 ;
               q[tail][1] = ty ;
               q[tail][2] = tval + 1 ;
           }
           if( check( tx , ty - 1 , usekey) )
           {
               q[++tail][0] = tx ;
               q[tail][1] = ty - 1 ;
               q[tail][2] = tval + 1 ;
           }
           if( check( tx , ty + 1 , usekey) )
           {
               q[++tail][0] = tx ;
               q[tail][1] = ty + 1;
               q[tail][2] = tval + 1 ;
           }
    }
    return oo ;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    init() ;
    
    if( keyx != 0 && keyy != 0 && doorx != 0 && doory != 0)
    {
        ans_s_to_key = Bfs( startx , starty , keyx , keyy , false );
        ans_key_to_door = Bfs( keyx , keyy , doorx , doory, true );
        ans_door_to_t = Bfs( doorx , doory , endx , endy ,true );
        ans_s_to_t = Bfs( startx , starty , endx , endy , false );
        if( ans_s_to_key < oo && ans_s_to_t > ans_s_to_key + ans_key_to_door + ans_door_to_t && ans_s_to_key + ans_key_to_door + ans_door_to_t<oo)
            printf("%d",ans_s_to_key + ans_key_to_door + ans_door_to_t);
        else if( ans_s_to_t < oo )
            printf("%d",ans_s_to_t) ;
        else printf("-1");
    }
    else
    {
        ans_s_to_t = Bfs( startx , starty , endx ,endy , false);
        if( ans_s_to_t < oo ) printf("%d",ans_s_to_t);
        else printf("-1");
    }
    
    return 0;
}
