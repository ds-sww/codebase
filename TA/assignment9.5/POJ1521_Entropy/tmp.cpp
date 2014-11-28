#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

struct node {
	long count;
	node* parent;
	node() { count = 0; parent = NULL; }
};

void sort(node* array[], long first, long last) {
	if(first >= last)
		return;
	node* ctrl = array[first];
	long i = first, j = last;
	while(i < j) {
		while(array[j]->count >= ctrl->count && i != j)
			j--;
		array[i] = array[j];
		while(array[i]->count < ctrl->count && i != j)
			i++;
		array[j] = array[i];
	}
	array[i] = ctrl;
	sort(array, first, i - 1);
	sort(array, i + 1, last);
}

int main() {
	string input;
	cin >> input;
	while(input != "END") {
		node* chars[27];
		node* copy[27];
		node* tmp;
		for(long i = 0; i < 27; i++) {
			tmp = new node;
			chars[i] = tmp;
			copy[i] = tmp;
		}
		for(long i = 0; i < input.length(); i++) {
			if(input[i] == '_')
				chars[26]->count++;
			else
				chars[input[i] - 'A']->count++;
		}
		sort(chars, 0, 26);
		for(long i = 0; i < 26; i++) {
			if(chars[i]->count == 0)
				continue;
			tmp = new node;
			tmp->count = chars[i]->count + chars[i+1]->count;
			chars[i]->parent = tmp;
			chars[i+1]->parent = tmp;
			chars[i+1] = tmp;
			chars[i] = NULL;
			sort(chars, i+1, 26);
		}
		long result[27];
		for(long i = 0; i < 27; i++) {
			result[i] = 0;
			tmp = copy[i];
			while(tmp->parent != NULL) {
				tmp = tmp->parent;
				result[i]++;
			}
		}
		long r1, r2;
		double r3;
		r1 = input.length() * 8;
		r2 = 0;
		for(long i = 0; i < input.length(); i++) {
			if(input[i] == '_')
				r2 = r2 + result[26];
			else
				r2 = r2 + result[input[i] - 'A'];
		}
		r3 = (double)r1 / r2;
		printf("%ld %ld %.1f\n", r1, r2, r3);
		cin >> input;
	}
	return 0;
}
