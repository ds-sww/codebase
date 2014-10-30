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

// GET number from text
int getNumber(int idx)
{
    int d = text[idx] - 48;
    idx++;
    while (isdigit(text[idx]))
    {
        d = d * 10 + text[idx] - 48;
        idx++;
    }
	idx--;
    return d;
}

// checkout priority
bool readyCalc(char opera1, char opera2)
{
    switch (opera1)
    {
		// pop the stack until meeting '('
        case ')':
		if (opera2 == '(')
                return false;
            return true;
		
		// when '+-' will push into stack, '+-*/^' could be operate
        case '+':
		case '-':
            if (opera2 != '(')
                return true;
            return false;
		
		// prioer operator could be calculate
        case '*': 
        case '/':
            if (opera2 == '^' || opera2 == '*' || opera2 == '/')
                return true;
            return false;
		
		// most priority
        case '^':
            return false;
		
		// push in stack wait for ')'
        case '(': 
            return false;
    }
    return false;
}

// Get operator and two parameters 
// To calculate answer and push it into num_stack
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

        int num;
        char opera;
		
		// easy coding, add a '(' in the begin and ')' in the end.
        text[len] = ')';
        operator_stack[++top_operator] = '(';

        for (int i = 0; i <= len; i++)
        {
            if (isdigit(text[i])) // whether it is a number
            {
                num = getNumber(&i);
                num_stack[++top_num] = num;
                continue;
            }
	
			// not a number
            opera = text[i];
			
			// pop the stack and calculate mid answer.
            while (readyCalc(opera, operator_stack[top_operator])) 
            {
				// '(' not a operator
                if (operator_stack[top_operator] != '(') 
                {
                    num = calcNumber(operator_stack[top_operator], num_stack[top_num-1], num_stack[top_num]);
                    top_num --; 
					
					// push mid answer back
                    num_stack[top_num] = num;                 
				}
				// pop one operator
                top_operator--; 
            }

			// operator ')' is a signal to pop stack 
			// operator')' never push into stack
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
