#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>

using namespace std ;

int next[100002] = {} ;
char pattern[100002] = {} , text[100002] = {} ;

void getNext()
{
        int patt_len = strlen( pattern ) ;
        int i = 1 , j = 0 ;
        next[0] = 0 ; next[1] = 0 ;
        
        for( i ; i < patt_len ; i ++)
        {
                while( j != 0 && pattern[i] != pattern[j] ) j = next[j] ;
                if( pattern[i] == pattern[j] )
                {
                        next[i + 1] = ++ j ;
                }
                else next[i + 1] = 0 ;
        }
        
}

bool KMP()
{
        int patt_len = strlen( pattern ) , text_len = strlen( text ) ;
        bool found = false ;
        int i = 0 , j = 0 ;
        for( i ; i < text_len ; i ++)
        {
                while( j != 0 && pattern[j] != text[i] ) j = next[j] ;
                if( pattern[j] == text[i] )
                {
                        j ++ ;
                        if( j == patt_len )
                        {
                                found = true ;
                                printf("%d ",i - patt_len + 1) ;
                                j = next[j] ;
                        }
                }
        }
        return found ;
}

int main()
{

        while( scanf("%s %s",text , pattern ) == 2 )
        {
                getNext() ;
                if( !KMP() ) printf("-1") ;
                putchar('\n');
        }
        
        return 0;
}
