#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <algorithm>


using namespace std;

set<string> s;
vector<pair<string,string> >rules;
struct too_many {};

void dfs(const string& t)
{
  for(vector<pair<string,string> >::const_iterator it=rules.begin();it!=rules.end();it++)
  {
    const string& x=it->first;
    const string& y=it->second;
    for(int i=0;i+x.size()<=t.size();i++)
    {
      if(strncmp(t.c_str()+i,x.c_str(),x.size())==0)
      {
        const string u=t.substr(0,i)+y+t.substr(i+x.size());
        if(s.insert(u).second){
        if(s.size()>1000){
        throw too_many();

        }
        dfs(u);

        }

      }

    }
    }
    }

int main(void)
{
   string init;
   cin>>init;
   init=init.substr(1,init.size()-2);
   s.insert(init);
   for(string t;cin>>t;)
   {
   replace(t.begin(),t.end(),'-',' ');
    replace(t.begin(),t.end(),'>',' ');
    replace(t.begin(),t.end(),'"',' ');
   istringstream iss(t);
   string x,y;
   iss>>x>>y;
   rules.push_back(make_pair(x,y));
   }
   try{
   dfs(init);
   }catch(const too_many&){};
   if(s.size()>1000)
      cout<<"Too many."<<endl;
   else
    cout<<s.size()<<endl;
    return 0;
}
