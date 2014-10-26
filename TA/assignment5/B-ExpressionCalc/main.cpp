/*
 * @author whimsycwd
 * @date   2014.10.26
 *
 */

#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

class Calculator {
    private :
        string exprStr;
        int cur;
    public :
        Calculator(const string & str) : exprStr(str), cur(0)  { }
        void calc() {
            cur = 0;
            cout << exprPri0() << endl;
        }

    private :    
        
        bool end() {
            return cur == exprStr.size();
        }

        int pow(int base, int exp) {
            int ret = 1;
            for (int i = 1; i<= exp; ++i) ret *= base;
            return ret;
        }

        int exprPri0() {
            int retValue = exprPri1();
            while (!end() && (exprStr[cur] == '+' || exprStr[cur] == '-')) {
                char op = exprStr[cur++];
                if (op == '+') {
                    int t = exprPri1();
                    retValue += t;
                } else {
                    int t = exprPri1();
                    retValue -= t;
                }

            }
            return retValue;
        }

        int exprPri1() {
            int retValue = exprPri2();
            while (!end() && (exprStr[cur] == '*' || exprStr[cur] == '/')) {
                char op = exprStr[cur++];
                if (op == '*') {
                    int t  = exprPri2();
                    retValue *= t;
                } else {
                    int t = exprPri2();
                    retValue /= t;
                }
            } 
            return retValue;
        }

        int exprPri2() {
            int retValue = exprPri3();
            if (!end() && exprStr[cur] == '^') {
                ++cur;
                int t = exprPri2();
                retValue = pow(retValue, t);
            }
            return retValue;
        }

        int exprPri3() { 
            int retValue = 0;
            if (!end() && exprStr[cur] == '(') {
                ++cur;
                retValue = exprPri0();
                ++cur;    
            } else {
                while (!end() && exprStr[cur] >= '0' && exprStr[cur] <= '9') {
                    retValue = retValue * 10 + exprStr[cur] - '0';
                    ++cur;
                }
            }
            return retValue; 
        }
};


int main() {
    string exprStr;
    while (cin >> exprStr) {
        Calculator toy(exprStr);
        toy.calc();
        
    }
    return 0;
}
