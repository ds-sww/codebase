#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int main() {
	int N, S;
	scanf("%d%d", &N, &S);
	int array[N];
	for(int i = 0; i < N; i++)
		scanf("%d", &array[i]);
	sort(array, array + N);
	int i = 0, j = N - 1, count = 0;
	while(i < j) {
		for(; i < j; j--) {
			if(array[i] + array[j] <= S)
				break;
		}
		count += j - i;
		i++;
	}
	cout << count << endl;
	return 0;
}

