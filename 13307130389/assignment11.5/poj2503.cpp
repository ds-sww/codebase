#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>

using namespace std ;

map<string , string> mp ;
map<string,string>::iterator itr;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    char buff1[20],buff2[20] ;
    char buff[100] ;
    gets(buff);
    while( sscanf(buff,"%s %s\n",buff1,buff2) == 2)
    {
           mp.insert( make_pair(string(buff2),string(buff1)) ) ;
           gets(buff);
    }
    
    while( scanf("%s\n",buff1) == 1 )
    {
           itr = mp.find(string(buff1)) ;
           if(itr != mp.end() )
                  cout << itr->second << endl;
           else cout << "eh" << endl ;
    }
    return 0;
}
