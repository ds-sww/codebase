#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

typedef struct{
	int ele;
	int maxi;
	int mini;
}tris;

void findmaxmin(stack<tris> & x, int &maxi, int &mini,int &orimax,int &orimin){
	if (orimax > x.top().maxi)maxi = orimax;
	else maxi = x.top().maxi;
	if (orimin < x.top().mini)mini = orimin;
	else mini = x.top().mini;
}

void InToOut(stack<tris> &in, stack<tris> &out){
	tris one;
	one = in.top();
	one.maxi = one.mini = one.ele;
	in.pop();
	out.push(one);
	while (in.size() != 0){
		one = in.top();
		findmaxmin(out, one.maxi, one.mini, one.ele, one.ele);
		in.pop();
		out.push(one);
	}
}

int main(){
	int N, k, i, maxi, mini, *Max, *Min;
	cin >> N >> k;
	int *all;
	all = new int[N];
	Max = new int[N - k + 1];
	Min = new int[N - k + 1];
	for (i = 0; i < N; i++){
		cin >> all[i];
	}
	stack<tris> in, out;
	in.push(tris{ all[0], all[0], all[0] });
	for (i = 1; i < k; i++){
		findmaxmin(in, maxi, mini, all[i], all[i]);
		in.push({ all[i], maxi, mini });
	}
	Max[i-k] = in.top().maxi;
	Min[i-k] = in.top().mini;
	while (i < N){
		if (out.size() == 0){
			InToOut(in, out);
			in.push(tris{ all[i], all[i], all[i] });
		}
		else{
			findmaxmin(in, maxi, mini, all[i], all[i]);
			in.push({ all[i], maxi, mini });
		}
		out.pop();
		if (out.size() == 0)Max[i - k + 1] = in.top().maxi;
		else Max[i - k + 1] = max(in.top().maxi, out.top().maxi);
		if (out.size() == 0)Min[i - k + 1] = in.top().mini;
		else Min[i - k + 1] = min(in.top().mini, out.top().mini);
		i++;
	}
	for (i = 0; i < N - k + 1; i++){
		cout << Min[i]<<" ";
	}
	cout << endl;
	for (i = 0; i < N - k + 1; i++){
		cout << Max[i] << " ";
	}
	cout << endl;
	return 0;
}

