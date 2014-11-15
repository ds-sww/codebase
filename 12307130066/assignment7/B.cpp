#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

int main() {
	int M, N;
	cin >> M >> N;
	while(M != 0 && N != 0) {
		string tmp;
		vector<string> avec;
		map<string, int> amap;
		for(int i = 0; i < M; i++) {
			cin >> tmp;
			if(amap.find(tmp) == amap.end()) {
				avec.push_back(tmp);
				amap[tmp] = 1;
			} else {
				amap[tmp] = amap[tmp] + 1;
			}
		}
		int count[M+1];
		for(int i = 0; i <= M; i++)
			count[i] = 0;
		for(int i = 0; i < avec.size(); i++)
			count[amap[avec[i]]]++;
		for(int i = 1; i <= M; i++)
			cout << count[i] << endl;
		cin >> M >> N;
	}
	return 0;
}
