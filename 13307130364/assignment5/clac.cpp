#include <iostream>
#include <stack>
#include <string>
#include<vector>
#include<math.h>
#include <stdlib.h>
using namespace std;

bool cmp(char a, char b){
	int ia, ib;
	switch (a)
	{
	case'^':ia = 3; break;
	case'*':case'/':ia = 2; break;
	case'+':case'-':ia = 1; break;
	case'(':ia = 0; break;
	default:
		break;
	}
	switch (b)
	{
	case'^':ib = 4; break;
	case'*':case'/':ib = 2; break;
	case'+':case'-':ib = 1; break;
	case'(':ib = 0; break;
	default:
		break;
	}
	if (ib <= ia)
		return 1;
	else
		return 0;
}
int calc(const string &s){
	stack<char> z;
	vector<string> c;
	stack<int> result;
	for (int i = 0; i < s.length(); i++){
		if (isdigit(s[i])){
			int o; string t = "";
			for (o = i; o < s.length() && isdigit(s[o]); o++){
				t += s[o];
			}
			i = o-1;
			c.push_back(t);
		}
		else if (s[i] == '(')
			z.push(s[i]);
		else if (s[i] == ')'){
			while (!z.empty()&&z.top() != '('){
				
				c.push_back(string("")+z.top());
				z.pop();
			}
			z.pop();
		}
		else{
			while (!z.empty()&&cmp(z.top(), s[i])){
				c.push_back(string("")+z.top());
				z.pop();
			}
			z.push(s[i]);
		}
	}
	while (!z.empty()){
		c.push_back(string("")+z.top());
		z.pop();
	}
	for (int i = 0; i < c.size(); i++){
		if (isdigit(c[i][0]))
			result.push(atoi(c[i].c_str()));
		else{
			int tempb=result.top();
			result.pop();
			int tempa = result.top();
			result.pop();
			switch (c[i][0])
			{
			case'+':result.push(tempa + tempb); break;
			case'-':result.push(tempa - tempb); break;
			case'*':result.push(tempa * tempb); break;
			case'/':result.push(tempa / tempb); break;
			case'^':result.push(pow(tempa , tempb)); break;
			default:
				break;
			}
		}

	}
	cout << result.top() << endl;
	return 0;
}
int main(){
	string s;
	while (cin >> s)
		calc(s);
	return 0;
}