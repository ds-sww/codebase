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
int m , n ;
map<string,string> mp ;

bool isCons(char c)
{
        return !((c=='a')||(c=='e')||(c=='i')||(c=='o')||(c=='u'));
}

int main()
{
        cin >> n >> m ;
        
        for( int i = 1 ; i <= n ; i ++)
        {
                string a , b ;
                cin >> a >> b ;
                mp.insert( make_pair(a,b) ) ;
        }
        for( int j = 1 ; j <= m ; j ++)
        {
                string str ;
                cin >> str ;
                map<string,string>::iterator itr ;
                if( (itr = mp.find(str) ) != mp.end() )
                {
                        cout << itr->second << endl ;
                }
                else if( str[str.size()-1]=='y' &&  isCons(str[str.size()-2]) )
                {
                        cout << str.substr(0,str.size()-1) + "ies" << endl ;
                }
                else if( str[str.size()-1]=='o'||str[str.size()-1]=='s'||str.substr(str.size()-2)=="ch"||str.substr(str.size()-2)=="sh"||str[str.size()-1]=='x')
                {
                        cout << str + "es" << endl ;
                }
                else
                        cout << str + "s" << endl ;
         }
        return 0;
}

