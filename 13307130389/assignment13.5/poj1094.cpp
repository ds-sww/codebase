#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std ;

int n , m ;
int id[255] = {} ;
vector<char> e[255] ;
char ans[27] = {} ;
bool vis[255] = {} ;

const int SUC = 2 ;
const int FAIL = 1 ;
const int ELSE = 0 ;

int head = 1 , tail = 0 ;
bool inq[255] = {} ;
int Toposort(int maxn)
{
    bool zerod = false ;
    memset(inq, false ,sizeof(inq)) ;
    head = 1 ; tail = 0 ;
    char u ;
    int cnt = 0 ;
    int tid[255] = {} ;
    for(char i = 'A' ; i <= 'Z' ; i ++) if( vis[i] )
    {
             tid[i] = id[i] ;
             if( id[i] == 0 )
             {
                 cnt ++ ;
                 u = i ;
                 ans[++ tail] = u ;
                 inq[u] = true ;
             }
    }
    if( cnt == 0 ) return FAIL ;
    if( cnt > 1 ) { zerod = true ; }
    while( head <= tail )
    {
           u = ans[head ++] ;
           for( vector<char>::iterator it = e[u].begin() ; it != e[u].end() ; it ++)
           {
                tid[*it] -- ;
                if( inq[*it] )
                    return FAIL ;
           }
           cnt = 0 ;
           for( char i = 'A' ; i <= 'Z' ; i ++) if( vis[i] )
                if( !inq[i] && tid[i] == 0)
                {
                    u = i ;
                    ans[++ tail] = u ;
                    inq[u] = true ;
                    cnt ++ ;
                }
           if( cnt > 1 ) { zerod = true ; }
    }
    if( tail < maxn ) return FAIL ;
    if( zerod > 0 ) return ELSE ;
    if( tail == n ) return SUC ;
    return ELSE ;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    while( scanf("%d %d",&n,&m) == 2 )
    {
           if( n == 0 && m == 0 ) break ;
           char s[5] = {} ;
           bool flag = false ;
           memset( vis , false , sizeof(vis) ) ;
           int maxn = 0 ;
           for(char i = 'A' ; i <= 'Z' ; i ++)
           {
                    e[i].clear() ;
                    id[i] = 0 ;
           }
           for(int i = 1 ; i <= m ; i ++ )
           {
                   scanf("%s",s);
                   if(flag) continue ;
                   
                   id[s[2]] ++ ;
                   e[s[0]].push_back(s[2]);
                   if( !vis[s[0]] ) {vis[s[0]] = true ; maxn ++ ;}
                   if( !vis[s[2]] ) {vis[s[2]] = true ; maxn ++ ;}
                   
                   if( i == 6 )
                   {
                       int temp = 0 ;
                   }
                   int status = Toposort(maxn) ;
                   if( status == SUC )
                   {
                       flag = true ;
                       printf("Sorted sequence determined after %d relations: ",i);
                       for(int j = 1 ; j <= n ; j ++)
                               printf("%c",ans[j]) ;
                       printf(".\n");
                   }
                   else if( status == FAIL )
                   {
                        printf("Inconsistency found after %d relations.\n",i);
                        flag = true ;
                   }
           }
           if( flag == false )
               printf("Sorted sequence cannot be determined.\n");
    }
    return 0;
}
