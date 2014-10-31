#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct exp
{
    int num;
    bool sign;
};

queue<exp> expression;
stack<char> sign;
stack<int> number;

int yx(char c)
{
    switch (c)
    {
        case '(': return 0;
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '/': return 2;
        case '^': return 3;
        default: return -1;
    }
}

bool isNumber(char& c)
{
    return c>='0' && c<='9';
}

int GetNumber(string& str,int& pos)
{
    int sum = 0;
    do
    {
        sum = sum * 10 + str[pos] - '0';
    }while(isNumber(str[++pos]));
    return sum;
}

int power(int a,int b)
{
    int x = a;
    if(b==0) return 1;
    for(int i = 1;i < b; i++) x = x * a;
    return x;

}
void Calculate(string& str)
{
    int i = 0;
    int num1,num2,sum;
    exp n;
    //create expression
    while(i < str.length())
    {
        if(isNumber(str[i]))
        {
            n.num = GetNumber(str,i);
            n.sign = false;
            expression.push(n);
        }else if(str[i] == '^')
        {
            sign.push('^');
            i++;
        }else if(str[i] == ')')
        {
            while(sign.top()!='(')
            {
                n.num = sign.top();
                n.sign = true;
                expression.push(n);
                sign.pop();
                i++;
            }
            sign.pop();
        }else if(str[i] == '(')
        {
            sign.push('(');
            i++;
        }else{
            while(!sign.empty() && yx(str[i])<=yx(sign.top()))
            {
                n.num = sign.top();
                n.sign = true;
                expression.push(n);
                sign.pop();
            }
            sign.push(str[i++]);

        }
    }
    while(!sign.empty())
    {
        n.num = sign.top();
        n.sign = true;
        expression.push(n);
        sign.pop();
    }
    //end
    //solve expression
    while(!expression.empty())
    {
        n = expression.front();
        if(!n.sign)
        {
            number.push(n.num);
        }else{
            num2 =  number.top(); number.pop();
            num1 = number.top(); number.pop();
            switch (n.num)
            {
                case '+':
                    sum = num1 + num2;
                    break;
                case '-':
                    sum = num1 - num2;
                    break;
                case '*':
                    sum = num1 * num2;
                    break;
                case '/':
                    sum = num1 / num2;
                    break;
                case '^':
                    sum = power(num1,num2);
                    break;
                default: break;
            }
             number.push(sum);
        }
        expression.pop();
    }
    cout<<number.top()<<endl;
    number.pop();

}
int main()
{
    string str;
    while(1)
    {
        getline(cin,str);
        if(str.length() == 0) break;
        Calculate(str);

    }
}
