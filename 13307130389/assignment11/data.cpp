#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>

using namespace std ;

int range = 51 ;

int main()
{
    int r , c ;
    srand(time(NULL)) ;

        freopen("in.txt","w",stdout);
        r = 0 ; c = 0 ;
        while( r <= 0 ) r = rand() % range ;
        while( c <= 0 ) c = rand() % range ;
    
        printf("1\n%d %d\n",r,c);
        for(int i = 0 ; i < r ; i ++)
        {
             for(int j = 0 ; j < c ; j ++)
                     printf("%c",rand()%26+'A') ;
             printf("\n");
        }
        fclose(stdout) ;

    
    return 0;
}
