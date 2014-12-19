#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<set>
#include<map>
#include<vector>
#include<cmath>

#define LL long long

using namespace std ;

int T ;
int son[10005][2] = {} ;
int queue[10005] = {} ;
int head , tail ;
int stack[10005] = {} ;
int fa[10005] ={} ;
int top ;
string s ;

bool isUpper(char c)
{
        return (c>='A'&&c<='Z') ;
}

int main()
{
        cin >> T ;
        while( T -- )
        {
                cin >> s ;
                top = 0 ;
                memset(fa,-1,sizeof(fa)) ;
                memset(son,-1,sizeof(son));
                for( int i = 0 ; i < s.size() ; i ++)
                {
                        if( isUpper(s[i]) )
                        {
                                int x , y ;
                                y = stack[top --] ;
                                x = stack[top --] ;
                                son[i][0] = x ;
                                son[i][1] = y ;
                                fa[x] = fa[y] = i ;
                        }
                        stack[++top] = i ;
                }
                
                head = 1 ; tail = 0 ;
                int root ;
                for( int i = 0 ; i < s.size() ; i ++)
                        if( fa[i] == -1 )
                        {
                                root = i ;
                                break ;
                        }
                queue[++ tail] = root ;
                while( head <= tail )
                {
                        int now = queue[head ++] ;
                        if( son[now][0] != -1 )
                                queue[++ tail] = son[now][0] ;
                        if( son[now][1] != -1 )
                                queue[++ tail] = son[now][1] ;
                }
                for( int i = tail ; i >= 1 ; i -- )
                        cout << s[queue[i]] ;
                cout << endl ;
        }
        return 0;
}

