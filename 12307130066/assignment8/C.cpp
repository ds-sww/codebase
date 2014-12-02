#include<iostream>
#include<cstdio>
#include<stack>

using namespace std;

int N;

void printOut(int Num) {
	if(Num > N)
		return;
	cout << Num << " ";
	printOut(Num * 2);
	printOut(Num * 2 + 1);
	return;
}

int main() {
	cin >> N;
	while(N != 0) {
		printOut(1);
		cout << endl;
		cin >> N;
	}
	return 0;
}



