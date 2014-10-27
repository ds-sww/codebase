/*
*	Copyright (C)	Lyq root#lyq.me
*	File Name     : p2.cpp
*	Creation Time : 2014/10/27 20:21:07
*	Environment   : Ubuntu 14.04-64bit
*	Hompage       : http://www.lyq.me
*/

// very sad to finish it until 19:50.

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

// use two stacks, one stores number, the other stores operator

char text[3000];
char operator_stack[3000];
int num_stack[3000];

int getNumber(int idx) // GET number from text
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
bool readyCalc(char opera1, char opera2) // checkout priority
{
    switch (opera1)
    {
        case ')': // pop the stack until meeting '('
            if (opera2 == '(')
                return false;
            return true;
        case '+': // when '+-' will push into stack, '+-*/^' could be operate
        case '-':
            if (opera2 != '(')
                return true;
            return false;
        case '*': // prioer operator could be calculate
        case '/':
            if (opera2 == '^' || opera2 == '*' || opera2 == '/')
                return true;
            return false;
        case '^':
            return false;
        case '(': // push in stack wait for ')'
            return false;
    }
    return false;
}
int calcNumber(char opera, int a, int b) // get operator and two parameters to calculate answer and push it into num_stack
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

        int num;
        char opera;
		
		// easy coding, add a '(' in the begin and ')' in the end.
        text[len] = ')';
        operator_stack[++top_operator] = '(';

        for (int i = 0; i <= len; i++)
        {
            if (isdigit(text[i])) // whether it is a number
            {
                num = getNumber(i);
                num_stack[++top_num] = num;
                while (isdigit(text[i])) i++;
                i--;
                continue;
            }
			
			// not a number
            opera = text[i];
            while (readyCalc(opera, operator_stack[top_operator])) // pop the stack and calculate mid answer.
            {
                if (operator_stack[top_operator] != '(') // '(' not a operator
                {
                    num = calcNumber(operator_stack[top_operator], num_stack[top_num-1], num_stack[top_num]);
                    top_num --; 
                    num_stack[top_num] = num; // push mid answer back
                }
                top_operator--; // pop one operator
            }
			// operator ')' is a signal to pop stack and ')' never push into stack
            if (opera != ')') operator_stack[++top_operator] = opera;
                else top_operator--;
        }
        //cout << top_operator << ' ' << top_num << endl;
		// if program run correctly, top_operator == 0 & top_num == 1

        cout << num_stack[1] << endl; 
    }

    //system("pause");
    return 0;
}
