#include<iostream>
#include<string>

using namespace std;

int* BF(string text, string pattern) {
	int *result;
	int count = 0;
	result = new int[10000];
	for(int i = 0; i < text.length()-pattern.length()+1; i++) {
		int j;
		for(j = 0; j < pattern.length(); j++) {
			if(text[i+j] != pattern[j])
				break;
		}
		if(j == pattern.length()) {
			result[count] = i;
			count++;
		}
	}
	if(count == 0)
		cout << -1;
	else {
		for(int i = 0; i < count-1; i++)
			cout << result[i] << " ";
		cout << result[count-1];
	}
	cout << endl;
	return result;
}

int main() {
	string text, pattern;
	while(cin >> text) {
		cin >> pattern;
		BF(text, pattern);
	}
	return 0;
}