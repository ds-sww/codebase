#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string engraved, origin;

void init()
{
	cin >> engraved >> origin;
}

bool judge()
{
	if(engraved.length() != origin.length()) return false;

	vector<int> corigin(26), cengraved(26);

	for(int i = 0; i < engraved.length(); i++) cengraved[engraved[i] - 'A']++;
	for(int i = 0; i < origin.length(); i++) corigin[origin[i] - 'A']++;

	sort(cengraved.begin(), cengraved.end());
	sort(corigin.begin(), corigin.end());

	for(int i = 0; i < 26; i++) if(corigin[i] != cengraved[i]) return false;

	return true;
}

int main()
{
	init();
	if(judge())
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
