#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>

#define NUMBER 1
#define OPERATOR 2

using namespace std ;

char origin[102] = {} ;

class Expression
{
public :
        struct Node
        {
                int type ;
                int value ;
        };

        Node exp[102] ;
        int length ;

        int power( int a , int b )
        {
                if( b == 0 ) return 1 ;
                if( b == 1 ) return a ;
                int temp = power( a , b / 2 ) ;
                if( b % 2 ) return temp*temp*a ;
                else return temp*temp ;
        }

        int getValue( const char c )
        {
                int v ;
                switch( c )
                {
                        case '+' : v = 1 ; break ;
                        case '-' : v = 2 ; break ;
                        case '*' : v = 3 ; break ;
                        case '/' : v = 4 ; break ;
                        case '^' : v = 5 ; break ;
                        case '(' : v = 6 ; break ;
                        case ')' : v = 7 ; break ;
                        default : v = 0 ;
                }
                return v ;
        }

        int getPriority( int op , bool inExp )
        {
                int prio ;
                switch( op )
                {
                        case 1 : case 2 :
                                prio = 1 ; break ;
                        case 3 : case 4 :
                                prio = 2 ; break ;
                        case 5 :
                                if( inExp ) prio = 4 ;
                                else prio = 3 ;
                                break ;
                        default : prio = 0 ;
                }
                return prio ;
        }

        Expression( const char* origin )
        {
                length = 0 ;
                int i = 0 ;
                int num = 0 ;
                int sta = 1 ;
                int len = strlen(origin) ;
                bool minus = false ;
                while( i <= len )
                {
                        if( origin[i] == '-' && (i == 0 || origin[i-1] == '(' ) )
                                minus = true ;
                        if( origin[i] >= '0' && origin[i] <= '9' )
                        {
                                sta = 0 ;
                                num = num * 10 + origin[i] - '0' ;
                        }
                        else
                        {
                                if( sta == 0 )
                                {
                                        exp[length].type = NUMBER ;
                                        if( minus ) exp[length].value = -num ;
                                        else exp[length].value = num ;
                                        num = 0 ;
                                        length ++ ;
                                        sta = 1 ;
                                }
                                if( i < len )
                                {
                                    exp[length].value = getValue( origin[i] ) ;
                                    exp[length].type = OPERATOR ;
                                    length ++ ;
                                    sta = 1 ;
                                }
                        }
                        i ++ ;
                }
        }

        int calculate()
        {
                Node stack[102] ; int top = -1 ;
                Node aim[102] ; int cnt = -1 ;
                int i = 0 ;
                while( i < length )
                {
                        if( exp[i].type == NUMBER )
                                aim[ ++ cnt ] = exp[i] ;
                        else
                        {
                                if( top < 0 ) stack[ ++ top] = exp[i] ;
                                else if( exp[i].value == 6 ) stack[++top] = exp[i] ;
                                else if( getPriority( exp[i].value , true ) > getPriority( stack[top].value , false ) )
                                {
                                        stack[++ top] = exp[i] ;
                                }
                                else if( exp[i].value == 7 )
                                {
                                        while( stack[top].value != 6 )
                                                aim[ ++ cnt ] = stack[top --] ;
                                        top -- ;
                                }
                                else
                                {
                                    while( top >= 0 && getPriority( exp[i].value , true ) <= getPriority( stack[top].value , false ) && stack[top].value != 6 )
                                    {
                                        aim[ ++ cnt ] = stack[top --];
                                    }
                                    stack[ ++ top ] = exp[i] ;
                                }
                        }
                        i ++ ;
                }

                while( top >= 0 ) aim[ ++ cnt ] = stack[ top -- ] ;

                i = 0 ;
                while( i <= cnt )
                {
                        if( aim[i].type == NUMBER )
                                stack[ ++ top] = aim[i] ;
                        else
                        {
                                switch( aim[i].value )
                                {
                                        case 1 : stack[top-1].value = stack[top-1].value + stack[top].value ; break ;
                                        case 2 : stack[top-1].value = stack[top-1].value - stack[top].value ; break ;
                                        case 3 : stack[top-1].value = stack[top-1].value * stack[top].value ; break ;
                                        case 4 : stack[top-1].value = stack[top-1].value / stack[top].value ; break ;
                                        case 5 : stack[top-1].value = power( stack[top-1].value , stack[top].value ) ; break ;
                                }
                                top -- ;
                        }
                        i ++ ;
                }
                return stack[0].value;
        }
};

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
        while( scanf("%s", origin ) == 1)
        {
                Expression expression( origin ) ;
                printf("%d\n", expression.calculate() ) ;
        }
        return 0;
}
