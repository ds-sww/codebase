#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

void sort(int* array, int first, int last) {
	if(first >= last)
		return;
	int i = first, j = last;
	int ctrl = array[first];
	while(i < j) {
		while(array[j] >= ctrl && i != j)
			j--;
		array[i] = array[j];

		while(array[i] < ctrl && i != j)
			i++;
		array[j] = array[i];
	}
	array[i] = ctrl;
	sort(array, first, i-1);
	sort(array, i+1, last);
}

int main() {
	START:
	while(1) {
		int N, M;
		scanf("%d", &N);
		scanf("%d", &M);
		if(N == 0 && M == 0)
			return 0;
		int heads[N], knights[M];
		for(int i = 0; i < N; i++)
			scanf("%d", &heads[i]);
		for(int i = 0; i < M; i++)
			scanf("%d", &knights[i]);
		sort(heads, 0, N-1);
		sort(knights, 0, M-1);
		int i, j = 0, sum = 0;
		for(i = 0; i < N; i++) {
			while(knights[j] < heads[i] && j < M)
				j++;
			if(j == M) {
				printf("Loowater is doomed!\n");
				goto START;
			}
			sum = sum + knights[j];
			j++;
		}
		printf("%d\n", sum);
	}
	return 0;
}
