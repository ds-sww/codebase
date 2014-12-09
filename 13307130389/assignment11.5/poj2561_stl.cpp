#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>

using namespace std ;

set<string> st ;
vector<pair<string, string> > trans ;
int ans = 0;

bool Dfs( string str )
{
     vector<pair<string,string> >::iterator itr = trans.begin() ;
     for( ; itr != trans.end() ; itr ++ )
     {
          string x = itr->first ;
          string y = itr->second ;
          for( int i = 0 ; i + x.size() <= str.size() ; i ++)
          {
               if( strncmp( x.c_str() , str.c_str() + i , x.size() ) == 0 )
               {
                   string a = str.substr( 0 , i ) ;
                   string b = str.substr(i + x.size() ) ;
                   string newstr = a + y + b ;
                   if( st.insert(newstr).second )
                   {
                       ans ++ ;
                       if( ans >= 1001 )
                           return false ;
                       if( !Dfs(newstr) )
                           return false ;
                   }
               }    
          }
     }
     return true ;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    string str ;
    cin >> str ;
    str = str.substr(1,str.size()-2);
    st.insert( str ) ;
    
    for(string tstr ; cin >> tstr ; )
    {
         replace(tstr.begin() , tstr.end() , '-' , ' ') ;
         replace(tstr.begin() , tstr.end() , '>' , ' ') ;
         replace(tstr.begin() , tstr.end() , '\"', ' ') ;
         istringstream iss(tstr) ;
         string x , y ;
         iss >> x >> y ;
         trans.push_back( make_pair( x , y ) ) ;
    }
    
    ans ++ ;
    if( Dfs(str) )
        cout << ans ;
    else
        cout << "Too many." ;
    
    return 0;
}
