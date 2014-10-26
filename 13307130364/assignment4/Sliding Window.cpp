#include<iostream>
using namespace std;
int a[1000005],q[1000005];
void minq(int n,int m){
	int tail = 0, head = 1;
	for (int i = 1; i <= n; i++){
		while (head <= tail&&a[q[tail]] >= a[i]) tail--;
		q[++tail] = i;
		if (i >= m){
			while (q[head]<i - m + 1) head++;
			cout<<a[q[head]]<<" ";
		}
	}
	cout << endl;
}
void maxq(int n,int m){
	int tail = 0, head = 1;
	for (int i = 1; i <= n; i++){
		while (head <= tail&&a[q[tail]] <= a[i]) tail--;
		q[++tail] = i;
		if (i >= m){
			while (q[head]<i - m + 1) head++;
			cout<<a[q[head]]<<" ";
		}
	}
}
int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	minq(n, k);
	maxq(n, k);
	return 0;
}