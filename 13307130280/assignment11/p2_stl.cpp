#include<iostream>
#include<vector>
#include<sstream>
#include<cstring>
#include<algorithm>
#include<set>
#include<fstream>
using namespace std;
set <string> st;
vector <pair<string,string> > trans;
string init;
int ans;
bool dfs(string s)
{
	for (vector<pair<string,string> > :: const_iterator itr = trans.begin(); itr != trans.end(); itr++)
	{
		const string &x = itr -> first;
		const string &y = itr -> second;
		for (int i = 0; i + x.size() <= s.size(); i++)
		{
			if (strncmp(s.c_str() + i,x.c_str(),x.size() ) == 0)
			{
				string u = s.substr(0,i) + y + s.substr(i + x.size());
				if (st.insert(u).second)
				{
					ans++;
					if (ans > 1000)
					return false;
					if (!dfs(u)) return false;
				}
				
			}
		}
	}
	return true;
}
int main()
{
	cin >> init;
	init = init.substr(1,init.size() - 2);
	st.insert(init);
	for (string t; cin>>t;)
	{
		replace(t.begin(),t.end(),'-',' ');
		replace(t.begin(),t.end(),'>',' ');
		replace(t.begin(),t.end(),'"',' ');
		istringstream iss(t);
		string x,y;
		iss >> x >> y;
		trans.push_back(make_pair(x,y));
	}
	dfs(init);
	if (st.size() > 1000) cout << "Too many." << endl;
	else cout << st.size() << endl;
	
	return 0;
}
