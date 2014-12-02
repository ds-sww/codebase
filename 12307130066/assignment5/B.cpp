#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main() {
	string text;
	while(cin >> text) {
		stack<int> numbers;
		stack<char> chars;
		int i;
		for(i = 0; i < text.length();) {
			int curr = 0;
			while(text[i] >= '0' && text[i] <= '9') {
				curr = curr*10 + (text[i] - '0');
				i++;
			}
			if(curr > 0) {
				numbers.push(curr);
				continue;
			}
			if(text[i] == '(') {
				chars.push(text[i]);
				i++;
				continue;
			}
			if(text[i] == ')') {
				while((!chars.empty()) && (chars.top() == '*' || chars.top() == '/' || chars.top() == '+' || chars.top() == '-' || chars.top() == '^')) {
					int b = numbers.top();
					numbers.pop();
					int a = numbers.top();
					numbers.pop();
					if(chars.top() == '*') {
						chars.pop();
						int R = a * b;
						numbers.push(R);
					}
					else if(chars.top() == '/') {
						chars.pop();
						int R = a / b;
						numbers.push(R);
					}
					else if(chars.top() == '+') {
						chars.pop();
						int R = a + b;
						numbers.push(R);
					}
					else if(chars.top() == '-') {
						chars.pop();
						int R = a - b;
						numbers.push(R);
					}
					else {
						chars.pop();
						int R = a;
						for(int t = 1; t < b; t++)
							R = R * a;
						numbers.push(R);
					}
				}
				chars.pop();
				i++;
				continue;
			}
			if(text[i] == '+' || text[i] == '-') {
				while((!chars.empty()) && (chars.top() == '*' || chars.top() == '/' || chars.top() == '+' || chars.top() == '-' || chars.top() == '^')) {
					int b = numbers.top();
					numbers.pop();
					int a = numbers.top();
					numbers.pop();
					if(chars.top() == '*') {
						chars.pop();
						int R = a * b;
						numbers.push(R);
					}
					else if(chars.top() == '/') {
						chars.pop();
						int R = a / b;
						numbers.push(R);
					}
					else if(chars.top() == '+') {
						chars.pop();
						int R = a + b;
						numbers.push(R);
					}
					else if(chars.top() == '-') {
						chars.pop();
						int R = a - b;
						numbers.push(R);
					}
					else {
						chars.pop();
						int R = a;
						for(int t = 1; t < b; t++)
							R = R * a;
						numbers.push(R);
					}
				}
				chars.push(text[i]);
				i++;
				continue;
			}
			if(text[i] == '*' || text[i] == '/') {
				while((!chars.empty()) && (chars.top() == '*' || chars.top() == '/' || chars.top() == '^')) {
					int b = numbers.top();
					numbers.pop();
					int a = numbers.top();
					numbers.pop();
					if(chars.top() == '*') {
						chars.pop();
						int R = a * b;
						numbers.push(R);
					}
					else if(chars.top() == '/') {
						chars.pop();
						int R = a / b;
						numbers.push(R);
					}
					else {
						chars.pop();
						int R = a;
						for(int t = 1; t < b; t++)
							R = R * a;
						numbers.push(R);
					}
				}
				chars.push(text[i]);
				i++;
				continue;
			}
			if(text[i] == '^') {
				//前提：
				//乘方符号不会连续出现
				chars.push(text[i]);
				i++;
				continue;
			}
		}
		while(!chars.empty()) {
			int a, b;
			b = numbers.top();
			numbers.pop();
			a = numbers.top();
			numbers.pop();
			char action = chars.top();
			chars.pop();
			if(action == '+') {
				int R = a + b;
				numbers.push(R);
				continue;
			}
			if(action == '-') {
				int R = a - b;
				numbers.push(R);
				continue;
			}
			if(action == '*') {
				int R = a * b;
				numbers.push(R);
				continue;
			}
			if(action == '/') {
				int R = a / b;
				numbers.push(R);
				continue;
			}
			else {
				int R = a;
				for(int t = 1; t < b; t++)
					R = R * a;
				numbers.push(R);
				continue;
			}
		}
		cout << numbers.top() << endl;
	}
	return 0;
}