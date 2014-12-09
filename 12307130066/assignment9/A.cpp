#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool isNumber(string tmp) {
	if(tmp[0] != '-' && (tmp[0] < '0' || tmp[0] > '9'))
		return false;
	for(int i = 1; i < tmp.length(); i++) {
		if(tmp[i] < '0' || tmp[i] > '9')
			return false;
	}
	return true;
}

int parseNumber(string tmp) {
	int init = 0, sign = 1;
	if(tmp[0] == '-') {
		init = 1;
		sign = -1;
	}
	int result = 0;
	for(int i = init; i < tmp.length(); i++)
		result = 10 * result + (tmp[i] - '0');
	return sign * result;
}

bool strComp(string a, string b) {
	for(int i = 0; i < a.length(); i++) {
		if(a[i] >= 'A' && a[i] <= 'Z')
			a[i] = a[i] + 32;
	}
	for(int i = 0; i < b.length(); i++) {
		if(b[i] >= 'A' && b[i] <= 'Z')
			b[i] = b[i] + 32;
	}
	return a < b;
}

int main() {
	string tmp, tmp2;
	cin >> tmp;
	while(tmp != ".") {
		vector<string> strs;
		vector<int> nums;
		vector<char> flags;
AGAIN:
		tmp2 = tmp.substr(0, tmp.length() - 1);
		if(isNumber(tmp2)) {
			flags.push_back('N');
			nums.push_back(parseNumber(tmp2));
		}
		else {
			flags.push_back('S');
			strs.push_back(tmp2);
		}
		if(tmp[tmp.length() - 1] != '.') {
			cin >> tmp;
			goto AGAIN;
		}
		sort(nums.begin(), nums.end());
		sort(strs.begin(), strs.end(), strComp);
		int currNum = 0, currStr = 0;
		for(int i = 0; i < flags.size() - 1; i++) {
			if(flags[i] == 'N')
				cout << nums[currNum++] << ", ";
			else
				cout << strs[currStr++] << ", ";
		}
		if(flags[flags.size() - 1] == 'N')
			cout << nums[currNum] << "." << endl;
		else
			cout << strs[currStr] << "." << endl;
		cin >> tmp;
	}
	return 0;
}

