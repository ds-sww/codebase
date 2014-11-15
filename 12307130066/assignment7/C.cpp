#include<iostream>
#include<stack>

using namespace std;

int main() {
	long long Count = 0;
	stack<long long> SS;
	stack<long long> SS2;
	long long N;
	long long tmp, tmp2;
	cin >> N;
	for(long long i = 0; i < N; i++) {
		cin >> tmp;
		if(SS.empty()) {
			SS.push(tmp);
			SS2.push(0);
		} else {
			if(SS.top() > tmp) {
				tmp2 = SS2.top();
				SS2.pop();
				SS2.push(++tmp2);

				SS.push(tmp);
				SS2.push(0);
			} else {
				while(!SS.empty() && SS.top() <= tmp) {
					Count += SS2.top();
					tmp2 = SS2.top();
					SS.pop(); SS2.pop();
					if(!SS.empty()) {
						tmp2 += SS2.top();
						SS2.pop();
						SS2.push(tmp2);
					}
				}
				if(!SS.empty()) {
					tmp2 = SS2.top();
					SS2.pop();
					SS2.push(++tmp2);
				}
				SS.push(tmp);
				SS2.push(0);
			}
		}
	}
	while(!SS.empty()) {
		Count += SS2.top();
		tmp2 = SS2.top();
		SS.pop(); SS2.pop();
		if(!SS.empty()) {
			tmp2 += SS2.top();
			SS2.pop();
			SS2.push(tmp2);
		}
	}
	cout << Count;
	return 0;
}
