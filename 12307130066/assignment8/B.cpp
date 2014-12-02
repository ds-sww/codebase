#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

string A, B;

struct node {
	char value;
	node* left;
	node* right;
	node() { left = NULL; right = NULL; }
};

void createTree(node* & root, int A1, int A2, int B1, int B2) {
	if(A1 > A2 || B1 > B2)
		return;
	root = new node;
	root->value = A[A1];
	int i;
	for(i = B1; ;i++) {
		if(B[i] == A[A1])
			break;
	}
	createTree(root->left, A1+1, A1+i-B1, B1, i-1);
	createTree(root->right, A1+i-B1+1, A2, i+1, B2);
	return;
}

void printTree(node* root) {
	if(root == NULL)
		return;
	printTree(root->left);
	printTree(root->right);
	printf("%c", root->value);
	return;
}

int main() {
	while(cin >> A) {
		cin >> B;
		node* root = NULL;
		createTree(root, 0, A.length()-1, 0, B.length()-1);
		printTree(root);
		printf("\n");
	}
	return 0;
}


