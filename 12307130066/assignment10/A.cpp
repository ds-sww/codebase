#include<iostream>
#include<cstdio>
#include<set>
#include<string>

using namespace std;

int main() {
	int cases;
	cin >> cases;
	for(int c = 0; c < cases; c++) {
		set<long long> mats;
		int N, M;
		cin >> N >> M;
		string lines[N];
		long long aline[M];
		long long cache;
		for(int i = 0; i < N; i++)
			cin >> lines[i];
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				for(int a = j; a < M; a++)
					aline[a] = 0;
				for(int k = i; k < N; k++) {
					cache = 0;
					for(int x = j; x < M; x++) {
						aline[x] = (aline[x] << 2) + lines[k][x];
						cache = (cache << 4) + aline[x] * aline[x];
						mats.insert(cache);
					}
				}
			}
		}
		cout << "Case #" << c+1 << ": " << mats.size() << endl;
	}
	return 0;
}

