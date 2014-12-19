#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<sstream>

using namespace std ;

vector< pair<string,string> > trans ;
set<string> st ;
int ans = 1 ;

bool Dfs( string str , int pos)
{
        for( vector< pair<string,string> >::iterator itr = trans.begin() ; 
                        itr != trans.end() ; itr ++ )
        {
                string x , y ;
                x = itr->first ; y = itr->second ;
                for( int i = pos ; i + x.size() <= str.size() ; i ++)
                {
                        if( strncmp( str.c_str()+i , x.c_str() , x.size() ) == 0 )
                        {
                                string a , b , newstr;
                                a = str.substr(0,i);
                                b = str.substr(i+x.size()) ;
                                newstr = a + y + b ;
                                if( st.insert(newstr).second )
                                {
                                        ans ++ ;
                                        if( ans >= 1001 )
                                                return false ;
                                        if( !Dfs(newstr,i) )
                                                return false ;
                                }
                        }
                 }
         }
         return true ;
}


int main()
{
        string str ;
        cin >> str ;

        str = str.substr(1,str.size()-2) ;
        st.insert(str);
        
        for( string t ; cin >> t ; )
        {
                replace( t.begin() , t.end() , '-' , ' ') ;
                replace( t.begin() , t.end() , '>' , ' ') ;
                replace( t.begin() , t.end() , '\"', ' ') ;
                
                istringstream iss(t) ;
                string a , b ;
                iss >> a >> b ;
                trans.push_back( make_pair(a,b) ) ;
        }
        ans = 1 ;
        if( !Dfs(str,0) )
                printf("Too many.\n");
        else
                printf("%d\n",ans);       
        
        return 0;
}
