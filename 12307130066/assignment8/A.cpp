#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

string A, B;
long CC;
long long result;

struct node {
	char value;
	vector<node*> child;
};

long C(long a, long b) {
	long a_ = 1, b_ = 1, a_b = 1;
	for(long i = 2; i <= a; i++)
		a_ = a_ * i;
	for(long i = 2; i <= b; i++)
		b_ = b_ * i;
	for(long i = 2; i <= a-b; i++)
		a_b = a_b * i;
	return a_ / b_ / a_b;
}

void createTree(node& root, long a, long b, long l) {
	if(l <= 0)
		return;
	long currA = a, currB = b;
	while(currB < b + l) {
		node* tmp = new node;
		tmp->value = A[currA];
		long i;
		for(i = currB; ; i++) {
			if(B[i] == tmp->value)
				break;
		}
		root.child.push_back(tmp);
		createTree(*tmp, currA+1, currB, i-currB);
		currA = currA + i - currB + 1;
		currB = i + 1;
	}
	return;
}

void calculate(node* root) {
	if(root == NULL)
		return;
	long Children = root->child.size();
	result = result * C(CC, Children);
	for(long i = 0; i < Children; i++)
		calculate(root->child[i]);
	return;
}

int main() {
	cin >> CC;
	while(CC > 0) {
		cin >> A >> B;
		node* root = new node;
		root->value = A[0];
		createTree(*root, 1, 0, A.length()-1);
		result = 1;
		calculate(root);
		cout << result << endl;
		cin >> CC;
	}
	return 0;
}


