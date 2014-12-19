#include <iostream>
#include <cstring>
#include <set>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstdio>
using namespace std;

set <string> s;
vector <pair <string, string> > rules;
struct too_many {};

void dfs (const string &str) {
    for (vector <pair <string, string> >::const_iterator it = rules.begin(); it != rules.end(); it++) {
        const string &x = it->first;
        const string &y = it->second;
        for (int j = 0; j + x.size() <= str.size(); j++ ) {
            if (strncmp(str.c_str() + j, x.c_str(), x.size()) == 0) {
                const string u = str.substr(0,j) + y + str.substr(j + x.size());
                if (s.insert(u).second) {
                    if (s.size() >= 1000) throw too_many();
                    dfs(u);
                }
            }
        }
    }
}

int main() {
    string str;
    cin >> str;
    str = str.substr(1, str.size()-2);
    s.insert(str);

    getchar();
    string t;
    while (getline(cin, t)) {
        if (t[0] == '\0') break;
        replace(t.begin(), t.end(), '"', ' ');
        replace(t.begin(), t.end(), '-', ' ');
        replace(t.begin(), t.end(), '>', ' ');
        istringstream temp(t);
        string a,b;
        temp >> a >> b;
        rules.push_back(make_pair(a,b));
    }

    try {
        dfs(str);
    } catch (const too_many&) {}

    if (s.size() >= 1000)
        cout << "Too many." << endl;
    else
        cout << s.size() << endl;
    return 0;
}
