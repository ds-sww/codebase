#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>

using namespace std ;

int ch[10005][2] = {} ;
int fa[10005] = {} ;
char s[10005] = {} ;
int stack[10005] = {} , top = 0 ;
int queue[10005] = {} ;
int root = 0 , len = 0 ;
int head = 1 , tail = 0 ;

inline bool isUpper(char c)
{
     return (c>='A')&&(c<='Z');
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int T ;
    scanf("%d",&T);
    int x , y ;
    while( T -- )
    {
           scanf("%s",s);
           len = strlen(s) ;
           for(int i = 0 ; i <= len ; i ++) ch[i][0] = ch[i][1] = fa[i] = -1 ;
           
           top = 0 ;
           for( int i = 0 ; i < len ; i ++)
           {
                if( isUpper(s[i]))
                {
                    y = stack[top--];
                    x = stack[top--];
                    ch[i][0] = x ; ch[i][1] = y ;
                    fa[x] = fa[y] = i ;
                }
                stack[++top] = i;
           }
           for( int i = 0 ; i < len ; i ++)
                if( fa[i] == -1 )
                {
                    root = i ;
                    break ;
                }
           
           head = 1 , tail = 0 ;
           queue[++ tail] = root ;
           while( head <= tail )
           {
                  int u = queue[head ++] ;
                  if( ch[u][0] != -1 ) queue[++ tail] = ch[u][0] ;
                  if( ch[u][1] != -1 ) queue[++ tail] = ch[u][1] ;
           }
           
           for( int i = tail ; i >= 1 ; i -- )
                printf("%c",s[queue[i]]);
           printf("\n");
    }
    
    return 0;
}
