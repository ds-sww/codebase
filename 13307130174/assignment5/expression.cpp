//
//  main.cpp
//  expression
//
//  Created by irmo on 14/10/29.
//  Copyright (c) 2014年 apple. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
#define MAXN 100

using namespace std;

int priority_out_stack(char c) {
    switch (c)
    {
        case '^':   return 4;
        case '*':case'/':   return 2;
        case '+':case'-':   return 1;
    }
    return -1;
}
int priority_in_stack (char c) {
    switch (c)
    {
        case '^':   return 3;
        case '*':case'/':   return 2;
        case '+':case'-':   return 1;
        case '(':   return 0;
    }
    return -1;
}

int calc(int a, int b, char c) {
    switch (c) {
        case '+':return a + b;
        case '-':return a - b;
        case '*':return a * b;
        case '/':
            if (b) return a / b ;
            else {
                cerr << "divide zero!" << endl;
                return 0;
            }
        case '^':
            if (a == 0 & b == 0) {
                cerr << "zero power zero" << endl;
                return 0;
            }
            if (a == 0) return 0;
            if (b == 0) return 1;
            int ans = 1;
            for (int i = 0; i < b; i++) ans = ans * a;
            return ans;
            break;
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    string expression;
    while (cin >> expression) {
        stack <char> operators;
        stack <int> ans;
        int num = 0;            //  num is a number consist of continuous characters.
        int flag = 0;           // flag means if here is a number, maybe it is zero.
        
        for (int i = 0; i < expression.size(); i++) {
            char c = expression[i];
            if (c >= '0' && c <= '9') {
                flag = 1;
                num = num * 10 + c - '0';
                continue;
            }
            if (flag) {
                ans.push(num);
                num = 0;
                flag = 0;
            }                   //push the number ahead in answer stack.
            
            switch (c) {
                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                    while (!operators.empty() && priority_out_stack(c) <= priority_in_stack(operators.top())) {
                        int b = ans.top();
                        ans.pop();
                        int a = ans.top();
                        ans.pop();
                        ans.push(calc(a,b,operators.top()));
                        operators.pop();
                    }
                    operators.push(c);
                    break;
                case '(':
                    operators.push(c);
                    break;
                case ')':
                    while (!operators.empty() && operators.top() != '(') {
                        int b = ans.top();
                        ans.pop();
                        int a = ans.top();
                        ans.pop();
                        ans.push(calc(a,b,operators.top()));
                        operators.pop();
                    }
                    operators.pop();            //pop the operator '('
                    break;
                default:
                    break;
            }
            
        }
        if (flag) ans.push(num);                //push the last num
        while (!operators.empty()) {
            int b = ans.top();
            ans.pop();
            int a = ans.top();
            ans.pop();
            ans.push(calc(a,b,operators.top()));
            operators.pop();
        }
        cout << ans.top() << endl;
        
    };
    return 0;
}
