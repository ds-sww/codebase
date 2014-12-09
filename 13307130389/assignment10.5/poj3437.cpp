#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>

#define maxn 10005

using namespace std ;

int bfs_seq[maxn] = {} ;
int bfs_index[maxn] = {} ;
int bfs_dep[maxn] = {} ;
int cnt = 0 ;
int root = 0 ;
int T = 0 ;
vector<int> child[maxn] ;
int pa[maxn] = {} ;
char seq[maxn*3] = {} ;
/*
int dfs( int k )
{
    int ld = 0, rd = 0 ;
    if( child[k][0] > 0 )
        ld = dfs( child[k][1] ) ;
    if( pa[k] == pa[ bfs_seq[bfs_index[k] + 1 ]] )
        rd = dfs( bfs_seq[bfs_index[k] + 1] ) ;
    if( ld > rd )
        return ld + 1 ;
    else
        return rd + 1 ;
}
*/

int calBinDeep(int tail)
{
    int ind = tail ;
    int sum[maxn] = {} ;
    while( ind > 0 )
    {
           int ld = 0 , rd = 0 ;
           int nd = bfs_seq[ind] ;
           if( child[nd][0] > 0 )
               ld = sum[ child[nd][1] ] ;
           if( ind + 1 <= tail && pa[nd] == pa[bfs_seq[ind+1]] )
               rd = sum[ bfs_seq[ind+1] ] ;
           if( ld > rd )
               sum[ nd ] = ld + 1 ;
           else
               sum[ nd ] = rd + 1 ;
           ind -- ;
    }
    return sum[1] - 1;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    while( scanf("%s",seq) == 1 )
    {
           T ++ ;
           cnt = 1 ; root = 1 ;
           
           if( seq[0] == '#' ) break ;
           int ans1 = 0 , ans2 = 0 ;
           
           for( int i = 0 ; i < maxn ; i ++)
           {
                child[i] = vector<int>() ;
                child[i].push_back(0) ;
           }
           
           stack<int> s ;
           s.push(1) ;
           int troot = 1;
           int lenseq = strlen(seq) ;
           for( int i = 0 ; i < lenseq ; i ++ )
           {
                if( seq[i] == 'd' )
                {
                    troot = s.top() ;
                    child[troot][0] ++ ;
                    child[troot].push_back(++cnt) ;
                    s.push( cnt ) ;
                }
                else
                {
                    s.pop() ;
                }
           }
           
           int head = 1 , tail = 0 ;
           bfs_seq[ ++ tail ] = root ;
           bfs_dep[ tail ] = 0 ;
           bfs_index[root] = 1 ;
           while( head <= tail )
           {
                  int u = bfs_seq[head] , d = bfs_dep[head] ;
                  head ++ ;
                  for( int i = 1 ; i <= child[u][0] ; i ++ )
                  {
                       bfs_seq[ ++ tail ] = child[u][i] ;
                       bfs_dep[ tail ] = d + 1 ;
                       bfs_index[child[u][i]] = tail ;
                       pa[ child[u][i] ] = u ;
                  }
           }
           
           ans1 = bfs_dep[tail] ;
           // ans2 = dfs( root ) - 1;
           ans2 = calBinDeep(tail) ;
           
           printf("Tree %d: %d => %d\n",T , ans1 , ans2 ) ;
    }
    
    return 0;
}
