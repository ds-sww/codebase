#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

bool Big(long long test, long long N, long long M) {
	long long count = 0, i;
	for(long long j = 1; j <= N; j++) {
		i = (sqrt(-3*j*j + 600000*j + 10000000000 + 4*test) - j - 100000) / 2;
		if(i < 0) continue;
		if(i > N) i = N;
		count += i;
	}
	if(count >= M)
		return true;
	return false;
}

int main() {
	long long cases;
	scanf("%lld", &cases);
	for(long long c = 0; c < cases; c++) {
		long long N, M;
		scanf("%lld%lld", &N, &M);
		long long left = -100000 * N, right = 3 * N * N + 100000 * N, middle, answer;
		while(left <= right) {
			middle = (left + right) / 2;
			if(Big(middle, N, M)) {
				answer = middle;
				right = middle - 1;
			}
			else {
				left = middle + 1;
			}
		}
		printf("%lld\n", answer);
	}
	return 0;
}
