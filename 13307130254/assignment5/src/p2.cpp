/*
*	Copyright (C)	Lyq root#lyq.me
*	File Name     : p2.cpp
*	Creation Time : 2014/10/27 20:21:07
*	Environment   : Ubuntu 14.04-64bit
*	Hompage       : http://www.lyq.me
*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

char text[3000];
char operator_stack[3000];
int num_stack[3000];
int bracket;

int getNumber(int idx)
{
    int d = text[idx] - 48;
    idx++;
    while (isdigit(text[idx]))
    {
        d = d * 10 + text[idx] - 48;
        idx++;
    }
    return d;
}
bool readyCalc(char opera1, char opera2)
{
    switch (opera1)
    {
        case ')':
            if (opera2 == '(')
                return false;
            return true;
        case '+':
        case '-':
            if (opera2 != '(')
                return true;
            return false;
        case '*':
        case '/':
            if (opera2 == '^' || opera2 == '*' || opera2 == '/')
                return true;
            return false;
        case '^':
            return false;
        case '(':
            return false;
    }
    return false;
}
int calcNumber(char opera, int a, int b)
{
    switch (opera)
    {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        case '^':
            int ans = 1;
            for (int i = 0 ; i < b; i++) ans = ans * a;
            return ans;
    }
    return 0;
}
int main()
{
    //freopen("in", "r", stdin);

    while (scanf("%s", text) != EOF)
    {
        int len = strlen(text);
        int top_operator = 0;
        int top_num = 0;
        bracket = 0;

        int num;
        char opera;

        text[len] = ')';
        operator_stack[++top_operator] = '(';

        for (int i = 0; i <= len; i++)
        {
            if (isdigit(text[i]))
            {
                num = getNumber(i);
                num_stack[++top_num] = num;
                while (isdigit(text[i])) i++;
                i--;
                continue;
            }

            opera = text[i];
            while (readyCalc(opera, operator_stack[top_operator]))
            {
                if (operator_stack[top_operator] != '(')
                {
                    num = calcNumber(operator_stack[top_operator], num_stack[top_num-1], num_stack[top_num]);
                    top_num --;
                    num_stack[top_num] = num;
                }
                top_operator--;
            }
            if (opera != ')') operator_stack[++top_operator] = opera;
                else top_operator--;
        }
        //cout << top_operator << ' ' << top_num << endl;
        cout << num_stack[1] << endl;
    }

    //system("pause");
    return 0;
}
