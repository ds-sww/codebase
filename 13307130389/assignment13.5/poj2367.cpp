#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<vector>

using namespace std ;

vector<int> e[105] ;
int n ;
int ind[105] = {} ;
int queue[105] = {} ;
int head = 1 , tail = 0 ;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i ++)
    {
            int v ;
            while( scanf("%d",&v) == 1 )
            {
                   if( v == 0 ) break ;
                   e[i].push_back(v) ;
                   ind[v] ++ ;
            }
    }
    
    for(int i = 1; i <= n ; i ++)
    {
            if( ind[i] == 0 )
            {
                queue[++ tail] = i ;
            }
    }
    while( head <= tail )
    {
           int u = queue[head ++] ;
           printf("%d ",u) ;
           for( vector<int>::iterator it=e[u].begin();it!=e[u].end();it++)
           {
                int v = *it ;
                ind[v] -- ;
                if( ind[v] == 0 )
                {
                    queue[++ tail] = v ;
                }
           }
    }
    
    return 0;
}
