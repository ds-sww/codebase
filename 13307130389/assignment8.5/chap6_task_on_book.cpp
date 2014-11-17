/*
Task 6 on page 141:
     From root do BFS
     Renumber each node by BFS visit order
     A binary tree is a complete binary tree if and only if
       any two nodes in parent-son relationship( eg. x = parent[y] )
       there must be index[y] = index[x] / 2
Task 4 on page 140:
     Following code will do this job.
     input n-1 edges.
     No checker for validity of input data.
     root must be node 1
     ***************Sample Input***************
     1 2 1
     1 4 2
     2 3 2
     4 5 1
     4 6 2
     6 7 1
     6 9 2
     7 8 2
     ***************Sample Output**************
     3 2 5 8 7 9 6 4 1 

by xiaoguai0992/13307130389
*/

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>

#define FILE_IN

using namespace std ;

int lch[1005] = {} , rch[1005] = {} ;
int stack[1005] = {} , top = 0 ;
bool vis[1005] = {} ;

void visit( int k )
{
     printf("%d ",k);
}

int main()
{
#ifdef FILE_IN
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    
    int u , v , type ; //type = 1 : lch , type = 2 : rch 
    int root = 1 ;
    while( scanf("%d %d %d",&u,&v,&type) == 3 )
    {
           if( type == 1 ) lch[u] = v ;
           else rch[u] = v ;
    }
    
    stack[++ top] = root ;
    while( top > 0 )
    {
           root = stack[top] ;
           if( lch[root] && !vis[lch[root]] )
           {
               stack[++ top] = lch[root] ;
           }
           else if( rch[root] && !vis[rch[root]] )
           {
                stack[++ top] = rch[root];
           }
           else
           {
               visit( stack[top] ) ;
               vis[ stack[top] ] = true ;
               top -- ;
           }
    }
    
    return 0;
}
