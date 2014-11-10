#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;

stack<int> number_stack,operator_stack;

int operator_cal()
{
    char op = operator_stack.top();
    operator_stack.pop();
    int num1 = number_stack.top();
    number_stack.pop();
    int num2 = number_stack.top();
    number_stack.pop ();
    switch(op)
    {
        case '+':return num2+num1;
        case '-':return num2-num1;
        case '*':return num2*num1;
        case '/':return num2/num1;
        case '^':return pow((double) num2, num1);
    }
    return -1;
}

int priority(char op,bool in_stack)
{
    switch(op)
    {
        case '(':return 0;
        case '+':
        case '-':return 1;
        case '*':
        case '/':return 2;
        case '^':if(in_stack)
                    return 3;
                 else
                    return 4;
    }
    return -1;
}

bool isnum(char c)
{
    if(c <= '9' && c >= '0')
        return true;
    else
        return false;
}

int strtoint(string str)
{
    int ret = 0;
    for(int i = 0; i < str.size(); i++)
        ret = ret*10 + (str[i]-'0');
    return ret;
}

int cal(string exp)
{
    while(!number_stack.empty())
        number_stack.pop();
    while(!operator_stack.empty())
        operator_stack.pop();

    int i, j;
    for(i=0; exp[i]!='\0'; i++)
    {
        if(isnum(exp[i]))
        {
            for(j=i; isnum(exp[j]); j++)
                ;
            number_stack.push(strtoint(exp.substr(i, j-i)));
            i=j-1;
        }
        else if(exp[i] == '(')
            operator_stack.push(exp[i]);
        else if(exp[i] != ')')
        {
            while(!operator_stack.empty() && priority(operator_stack.top(), 1) >= priority(exp[i], 0))
                number_stack.push(operator_cal());
            operator_stack.push(exp[i]);
        }
        else
        {
            while(operator_stack.top() != '(')
                number_stack.push(operator_cal());
            operator_stack.pop();
        }
    }
    while(!operator_stack.empty())
        number_stack.push(operator_cal());
    return number_stack.top();
}

int main()
{
    string text;
    while(cin >> text)
        cout << cal(text) << endl;
    return 0;
}