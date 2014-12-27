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

int n ;
string s[11] ;
int cnt = 0 ;
bool vis[27] = {} ;
vector<char> ls ;
long long ans = 0 ;
int a[11] = {} ;
int mp[256] = {} ;
bool isfirst[256] ={} ;

void Dfs( int cur )
{
        if( cur >= cnt )
        {
                memset( a , 0 , sizeof(a)) ;
                for( int i = 1 ; i <= n ; i ++)
                        if( mp[s[i][0]] == 0 ) 
                                return  ;
                for( int i = 1 ; i <= n ; i ++)
                        for(int j = 0 ; j < s[i].size() ; j ++)
                                a[i] = a[i] * 10 + mp[s[i][j]] ;
                for( int i = 2 ; i <= n-1 ; i ++)
                        a[i] += a[i-1] ;
                if( a[n] == a[n-1] )
                {   
                        ans ++ ;
                }
                
                return ;
        }
        for( int i = 0 ; i < 10 ; i ++) if( !vis[i] )
        {
                mp[ls[cur]] = i ;
                vis[i] = true ;
                Dfs(cur + 1) ;
                vis[i] = false ;
        }
}

int main()
{
        cin >> n ;
        for( int i = 1 ; i <= n ; i ++)
        {
                cin >> s[i] ;
                for(int j = 0 ; j < s[i].size() ; j ++)
                        vis[ s[i][j] - 'A' ] = true ;
        }
        for( int i = 0 ; i < 26 ; i ++) if( vis[i] )
        {
                ls.push_back((char)(i + 'A')) ;
                cnt ++ ;
        }
        
        memset(vis,0,sizeof(vis)) ;
        Dfs( 0 ) ;
        
        cout << ans ;
        
        return 0;
}

