#include<iostream>
#include<cstdio>
#include<set>
#include<map>
#include<string>

using namespace std;
multimap<string, string> rules;
set<string> dict;

void dfs(string str) {
	for(multimap<string, string>::iterator iter = rules.begin(); iter != rules.end(); ++iter) {
		int pos = 0;
		while((pos = str.find(iter->first, pos)) != string::npos) {
			string newstr = str;
			newstr.replace(pos, iter->first.length(), iter->second);
			if(dict.count(newstr) == 0) {
				dict.insert(newstr);
				if(dict.size() > 1000)
					throw "Bye";
				dfs(newstr);
			}
			pos += iter->first.length();
		}
	}
}

int main() {
	string init;
	cin >> init;
	init = init.substr(1, init.length()-2);
	string line;
	int j;
	while(cin >> line) {
		j = line.find("->");
		rules.insert(pair<string, string>(line.substr(1, j-2), line.substr(j+3, line.length()-j-4)));
	}
	dict.insert(init);
	try {
		dfs(init);
	}
	catch(const char* CC) {
		cout << "Too many." << endl;
		return 0;
	}
	cout << dict.size() << endl;
	return 0;
}


