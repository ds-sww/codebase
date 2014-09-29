#include<vector>
#include<iostream>
#include<string>
using namespace std;

int main() {

	string b = "233333";
	string *a = &b;
	cout << *a << endl;
	return 0;
}