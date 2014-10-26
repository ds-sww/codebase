#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>

using namespace std ;

int stack[1005] = {} ;
int top = 0 ;
int n = 0 ;
int aim[1005] = {} , nowpos = 0 ;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int i = 0 ;
    bool first_case = true ;
    bool first_sub_case = true ;
    while( scanf("%d",&n) && n != 0 )
    {
           if( !first_case ) printf("\n\n");
           first_case = false ;
           first_sub_case = true ;
           while( scanf("%d",&aim[0]) && aim[0] != 0 )
           {
                  if( !first_sub_case ) printf("\n");
                  first_sub_case = false ;
                  for( i = 1 ; i < n ; i ++ ) scanf("%d",&aim[i]);
                  top = -1 ; nowpos = 0 ; i = 1 ;
                  while( nowpos < n )
                  {
                       if( i > n && stack[top] != aim[nowpos] ) break ;
                       while( top > -1 && stack[top] == aim[nowpos] ) { nowpos ++ ; top -- ; }
                       while( i != aim[nowpos] && i <= n ) { stack[++ top] = i ; i ++ ; }
                       if( i == aim[nowpos] ) { i ++ ; nowpos ++ ; }
                  }
                  if( nowpos == n ) printf("Yes");
                  else printf("No");
           }
    }
    return 0;
}
