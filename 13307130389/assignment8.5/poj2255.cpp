#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>

using namespace std ;

char preorder[30] , inorder[30] ;

void postOrderSearch( int pre , int in , int len )
{
     if( len <= 0 ) return  ;
     if( len == 1 )
     {
         putchar(preorder[pre]) ;
         return ;
     }
     int root ;
     for( root = in ; root < in + len ; root ++ )
          if( inorder[root] == preorder[pre] )
              break ;
     postOrderSearch( pre + 1 , in , root - in ) ;
     postOrderSearch( pre + 1 + (root - in) , root + 1 , in + len - 1 - root ) ;
     putchar(preorder[pre]) ;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    while( scanf("%s %s\n",preorder,inorder) == 2 )
    {
           postOrderSearch(0 , 0 , strlen(preorder) ) ;
           putchar('\n');
    }
    
    return 0;
}
