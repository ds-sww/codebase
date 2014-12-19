#include<cstring>
#include<cstdlib>
#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>

using namespace std ;

map<string,string> mp ;

bool isConsonant(char c)
{
     return !((c=='a')||(c=='e')||(c=='i')||(c=='o')||(c=='u')) ;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int n , m ;
    
    cin >> n >> m ;
    
    for( int i = 1 ; i <= n ; i ++)
    {
         string a , b ;
         cin >> a >> b ;
         mp.insert( make_pair(a,b)) ;
    }
    
    for( int j = 1 ; j <= m ; j ++)
    {
         string x ;
         cin >> x ;
         map<string,string>::iterator itr ;
         itr = mp.find(x) ;
         if( itr != mp.end() )
         {
             cout << itr->second << endl ;
         }
         else if( isConsonant(x[x.size()-2]) && x[x.size()-1] == 'y' )
         {
              cout << x.substr( 0 , x.size() - 1 ) + "ies" << endl ;
         }
         else if( x[x.size()-1]=='o'||x[x.size()-1]=='s'||x[x.size()-1]=='x'||x.substr(x.size()-2)=="ch"||x.substr(x.size()-2)=="sh" )
              cout << x + "es" << endl ;
         else
             cout << x + "s" << endl ;
    }
    
    return 0;
}
