#include<iostream>

using namespace std;

int sort(int arr[], int l, int r){
	if (l >= r)return l;
	int x = arr[l];
	int i = l, j = r;
	while (i < j){
		while (arr[j] >= x && j >= l)j--;
		if (i >= j){
			arr[i] = x;
			return i;
		}
		arr[i] = arr[j];
		while (arr[i] <= x && i <= r)i++;
		if (i >= j){
			arr[j] = x;
			return j;
		}
		arr[j] = arr[i];
	}
}

void quicksort(int arr[], int l, int r){
	if (l >= r) return;
	int i;
	i = sort(arr, l, r);
	quicksort(arr, l, i - 1);
	quicksort(arr, i + 1, r);
}

int main(){
	int N, T;
	cin >> T >> N;
	int *pos, *nag;
	pos = new int[N];
	nag = new int[N];
	int i, j, x, pnow = 0, nnow = 0;
	int count = 0;
	for (i = 0; i < N; i++){
		cin >> x;
		if (x >= 0){
			pos[pnow] = x;
			pnow++;
		}
		else{
			nag[nnow] = -x;
			nnow++;
		}
	}
	pnow--;
	nnow--;
	quicksort(pos, 0, pnow);
	quicksort(nag, 0, nnow);
	x = i = j = 0;
	while (T >= 0){
		if (i > pnow && j > nnow)break;
		else if (i > pnow){
			if (x >= 0 && nag[j] > x || x < 0 && nag[j] > -x || x >= 0 && nag[j] < x)
				T = T - (nag[j] + x);
			else if (x < 0 && nag[j] < -x)
				T = T + (x + nag[j]);
			x = nag[j];
			j++;
		}
		else if (j > nnow){
			if (pos[i] > x)
				T = T - (pos[i] - x);
			else T = T + (pos[i] - x);
			x = pos[i];
			i++;
		}
		else if (pos[i] < nag[j]){
			if (pos[i] > x)
				T = T - (pos[i] - x);
			else T = T + (pos[i] - x);
			x = pos[i];
			i++;
		}
		else{
			if (x >= 0 && nag[j] > x || x < 0 && nag[j] > -x || x >= 0 && nag[j] < x)
				T = T - (nag[j] + x);
			else if (x < 0 && nag[j] < -x)
				T = T + (x + nag[j]);
			x = -nag[j];
			j++;
		}
	}
	count = i + j - 1;
	cout << count << endl;
	return 0;
}

