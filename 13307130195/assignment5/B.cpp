#include <cmath>
#include <cstdio>
#include <iostream>
#include <climits>
#include <cstring>
#include <string>
#include <stack>
using namespace std;


char ope[] = {'-', '+', '*', '/', '^', '(', ')', '#' };
char pri[] = { 1,   1,   2,   2,   3,   0,   0,   -1 }; // priority


string s;

bool is_num(char c)
{
    return  ('0' <= c && c <= '9');
}

int p(char c) // priority of operator c
{
    for (int i = 0; i < 8; i++)
        if (c == ope[i]) return pri[i];
}

char op[1000]; int to; // operator
int res[1000]; int tr; // result expression
bool isop[1000];

int main()
{
    // freopen("b.in","r", stdin);

    while (cin >>s)
    {
        s = s + "#";
        memset(op,0,sizeof(op)); to = 0;
        memset(res,0,sizeof(res)); tr = 0;
        memset(isop, 0, sizeof(isop));

        op[++to] = '#';

        bool isnum = 0;
        char c;
        int num;

        for (int i = 0; i < s.length(); i++)
        {
            c = s[i];
            if (is_num(c))
            {
                if (!isnum)
                {
                    isnum = 1;
                    num = c - '0';
                }
                else {
                    num = num * 10 + c - '0';
                }
                continue;
            }

            if (isnum)
            {
                res[++tr] = num;
                isop[tr] = 0;
                isnum = 0;
            }

            switch (c) {

            case '-':
            case '+':
            case '*':
            case '/':
                while ((p(op[to])) >= p(c)) {
                    res[++tr] = op[to--];
                    isop[tr] = 1;
                }
                op[++to] = c;
                break;

            case '^':
                while ((p(op[to])) > p(c)) {
                    res[++tr] = op[to--];
                    isop[tr] = 1;
                }
                op[++to] = c;
                break;

            case '(':
                op[++to] = c;
                break;

            case ')':
                while (op[to] != '(') {
                    res[++tr] = op[to--];
                    isop[tr] = 1;
                }
                to --;
                break;

            case '#':
                while (op[to] != '#') {
                    res[++tr] = op[to--];
                    isop[tr] = 1;
                }
                break;
            }
        }

        stack<int> stk;
        int num_a, num_b;
        for (int i = 1; i <= tr; i++)
        {
            if (isop[i])
            {
                num_b = stk.top(); stk.pop();
                num_a = stk.top(); stk.pop();
                switch (res[i]) {
                    case '-':
                        num_a = num_a - num_b;
                        break;
                    case '+':
                        num_a = num_a + num_b;
                        break;
                    case '*':
                        num_a = num_a * num_b;
                        break;
                    case '/':
                        num_a = num_a / num_b;
                        break;
                    case '^':
                        num_a = (int)pow(num_a, num_b);
                        break;
                }
                stk.push(num_a);
            }
            else {
                stk.push(res[i]);
            }
        }

        cout<<stk.top()<<endl;

    }
    return 0;
}
