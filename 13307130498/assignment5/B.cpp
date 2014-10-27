#include<iostream>
#include<stack>
using namespace std;

int current(char c){
	switch (c){
	case '^': return 4;
	case '*':
	case '/': return 2;
	case '+':
	case '-': return 1;
	}
}
int instack(char c){
	switch (c){
	case '^': return 3;
	case '*':
	case '/': return 2;
	case '+':
	case '-': return 1;
	case '(': return 0;
	case '$': return -1;
	}
}
int mid_to_pos(char mid[], char pos[], int num[]){
	stack<char>s;
	int size = 0;
	s.push('$');
	char c;
	int i, j;
	i = j = 0;
	c = mid[0];
	while (c != '\0'){
		if (c >= '0' && c <= '9'){
			pos[j++] = c;
			while (c >= '0'&&c <= '9'){
				num[size] = num[size] * 10 + int(c - '0');
				c = mid[++i];
			}
			c = mid[--i];
			size++;
		}
		else switch (c){
			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
				while (current(c) <= instack(s.top())){
					pos[j++] = s.top();
					s.pop();
				}
				s.push(c);
				break;
			case '(':
				s.push(c);
				break;
			case ')':
				while (s.top() != '('){
					pos[j++] = s.top();
					s.pop();
				}
				s.pop();
				break;
			default:
				return 0;
		}
		c = mid[++i];
	}
	while (instack(s.top()) > 0){
		pos[j++] = s.top();
		s.pop();
	}
	pos[j] = '\0';
	return size;
}


int eva(int *p, char pos[],int num[]){
	int i, j, k, x, y, z, size = 0;
	stack<int>s;
	char c;
	i = 0;
	c = pos[0];
	while (c != '\0'){
		if (c >= '0' && c <= '9'){
			s.push(num[size++]);
		}
		else switch (c){
		case '+':
			x = s.top();
			s.pop();
			y = s.top();
			s.pop();
			s.push(x + y);
			break;
		case '-':
			x = s.top();
			s.pop();
			y = s.top();
			s.pop();
			s.push(y - x);
			break;
		case '*':
			x = s.top();
			s.pop();
			y = s.top();
			s.pop();
			s.push(x * y);
			break;
		case '/':
			x = s.top();
			s.pop();
			y = s.top();
			s.pop();
			if (x < 0 && y>0)s.push(-(y / (-x)));
			else if (x > 0 && y < 0)s.push(-((-y) / x));
			else if (x < 0 && y < 0)s.push((-y) / (-x));
			else if (x>0 && y > 0)s.push(y / x);
			else if (x == 0)return 1;
			else if (y == 0)s.push(0);
			break;
		case '^':
			x = s.top();
			s.pop();
			y = s.top();
			s.pop();
			if (y == 0)return 1;
			if (x == 0)s.push(1);
			else{
				if (x > 0)j = x;
				if (x < 0)j = -x;
				for (z = 1, k = 1; k <= j; k++)
					z *= y;
				if (x < 0)z = 1 / z;
				s.push(z);
			}
			break;
		default:return 1;
		}
		c = pos[++i];
	}
	*p = s.top();
	s.pop();
	if (s.empty())return 0;
	else return 1;
}


int main(){
	int *result, i, j;
	result = new int;
	char mid[100];
	while (cin >> mid){
		int num[100], size = 0;
		for (i = 0; i < 100; i++)
			num[i] = 0;
		char pos[100];
		size = mid_to_pos(mid, pos, num);
		j = eva(result, pos, num);
		cout << *result << endl;
	}
	return 0;
}
