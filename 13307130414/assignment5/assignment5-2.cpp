#include <iostream>
#include <stack>
#include <queue>
#include <cstring>
#include <stdio.h>
#include <cmath>
using namespace std;

string mid;
queue <char> pos;
stack <int> ans;

int priority(char c) {
    switch (c) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        case '(': return 0;
        case ')': return -1;
        case '$': return -2;
        default : return 4;
    }
}

int mid_to_pos(string &mid, queue <char> &pos) {
    stack <char> s;
    s.push('$');
    int i;
    for (i = 0; ; i++) {
        if (isdigit(mid[i])) {
            pos.push('(');
            for(; isdigit(mid[i]); i++)
                pos.push(mid[i]);
            pos.push(')');
        }
        if (mid[i] == '\0') {
            while (s.top() != '$') {
                pos.push(s.top());
                s.pop();
            }
            break;
        }
        else if (priority(mid[i]) == 0 || priority(mid[i]) > priority(s.top()))
            s.push(mid[i]);
        else if (priority(mid[i]) == 3 && priority(s.top()) == 3)
            s.push(mid[i]);
        else if (priority(mid[i]) == -1) {
            while (s.top() != '(') {
                pos.push(s.top());
                s.pop();
            }
            s.pop();
        }
        else if (priority(mid[i]) <= priority(s.top())) {
            while (priority(mid[i]) <= priority(s.top())) {
                pos.push(s.top());
                s.pop();
            }
            s.push(mid[i]);
        }
    }
    return 0;
}

int evaluate(queue <char> pos) {
    int a,e;
    while (!pos.empty()) {
        if (pos.front() == '(') {
            a = 0;
            pos.pop();
            while (pos.front() != ')') {
                a = a * 10 + pos.front() - '0';
                pos.pop();
            }
            pos.pop();
            ans.push(a);
        }
        else if (pos.front() == '+') {
            pos.pop();
            e = ans.top();
            ans.pop();
            e += ans.top();
            ans.pop();
            ans.push(e);
        }
        else if (pos.front() == '-') {
            pos.pop();
            e = ans.top();
            ans.pop();
            e = ans.top() - e;
            ans.pop();
            ans.push(e);
        }
        else if (pos.front() == '*') {
            pos.pop();
            e = ans.top();
            ans.pop();
            e *= ans.top();
            ans.pop();
            ans.push(e);
        }
        else if (pos.front() == '/') {
            pos.pop();
            e = ans.top();
            ans.pop();
            e = ans.top() / e;
            ans.pop();
            ans.push(e);
        }
        else if (pos.front() == '^') {
            pos.pop();
            e = ans.top();
            ans.pop();
            e = pow(ans.top(),e);
            ans.pop();
            ans.push(e);
        }
    }
    return ans.top();
}

int main() {
    while (1) {
        getline(cin,mid);
        if (mid.length() == 0) break;
        mid_to_pos(mid,pos);
        cout << evaluate(pos) << endl;
    }
    return 0;
}
