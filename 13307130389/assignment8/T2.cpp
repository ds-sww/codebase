#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>

using namespace std ;

char pre[27] = {} , in[27] = {} ;

void postOrder( int pre_start , int in_start , int len )
{     
        if( len == 0 ) return ;
        if( len == 1 )
        {
                printf("%c",pre[pre_start]) ;
                return ;
        }
        int i ;
        for( i = in_start ; i < in_start + len ; i ++)
                if( in[i] == pre[pre_start] )
                        break ;
        postOrder( pre_start + 1 , in_start , i - in_start );
        postOrder( pre_start + i - in_start + 1, i + 1 , len - i + in_start - 1 );
        
        printf("%c",pre[pre_start]);
}

int main()
{
        
        while( scanf("%s %s\n",pre , in ) == 2 )
        {
                int len = strlen( pre ) ;
                postOrder( 0 , 0 , len ) ;
                printf("\n");
        }
        return 0;
}

