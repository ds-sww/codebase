//
//  main.cpp
//  cal
//
//  Created by billlai on 14-10-27.
//  Copyright (c) 2014年 billlai. All rights reserved.
//  好开心没有调试就通过了！
//  先转换为后缀表达式，再计算

#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

#define MAXN 1000//暂且假设最长的表达式长度小于999
class cal
{
public:
    char* ex;//用于储存中缀表达式
    char* out;//用于储存后缀表达式
    char* temp;//用于输入
    stack<int> tocal;//用于储存数字
    
    cal()
    {
        temp = new char[MAXN];
        ex = new char[MAXN];
        out = new char[MAXN];
    }
    
    int getouts(char c)//得到在栈外的优先级
    {
        switch (c)
        {
            case '^': return 4;
            case '/':
            case '*': return 2;
            case '+':
            case '-': return 1;
        }
        cerr << c << "getout" << "ERROR" <<endl;
        return -10;
    }
    
    int getins(char c)//得到在栈内的优先级
    {
        switch (c)
        {
            case '^': return 3;
            case '*':
            case '/': return 2;
            case '+':
            case '-': return 1;
            case '(': return 0;
            case '$': return -1;
        }
        cerr << c << "ERROR" <<endl;
        return -10;
    }
    
    int islower(char c, stack<char> s)//优先级比较
    {
        return getouts(c)<=getins(s.top()) ?  1 : 0;
    }
    
    int isnumber(char c)
    {
        if (c>='0' && c<='9') return 1;
        return 0;
    }
    
    int midtopos()//中缀转后缀
    {
        stack<char> s;
        s.push('$');
        char c;
        int excounter,outcounter;//计数用
        excounter = outcounter = 0;
        c = ex[0];
        while(c!='\0')
        {
            if(isnumber(c))
            {
                out[outcounter++] = c;
                if(!isnumber(ex[excounter+1]))//以空格区分不同数字
                {
                    out[outcounter++] = ' ';
                }
            }
            else
            {
                if(c=='(')
                {
                    s.push(c);
                }
                else if(c==')')
                {
                    while(s.top()!='(')
                    {
                        out[outcounter++] = s.top();
                        s.pop();
                    }
                    if(s.top()=='(')
                    {
                        s.pop();
                    }
                }
                else
                {
                    while(islower(c,s))
                    {
                        out[outcounter++] = s.top();
                        s.pop();
                    }
                    s.push(c);
                }
 
            }            c = ex[++excounter];
        }
        while(getins(s.top())>=0)
        {
            out[outcounter++] = s.top();
            s.pop();
        }
        out[outcounter] = '\0';
        return 0;
    }
    
    void calculate()
    {
        int i = 0;
        int temp = 0;
        int first = 0;
        int second = 0;
        while(out[i]!='\0')
        {
            if(out[i] == ' ')
            {
                i++;
                continue;
            }
            if(isnumber(out[i]))
            {
                temp = 10 * temp + (out[i]-'0');
                if(out[i+1] == ' ')
                {
                    tocal.push(temp);
                    temp = 0;
                }
            }
            else
            {
                second = tocal.top();
                tocal.pop();
                first = tocal.top();
                tocal.pop();
                switch(out[i])
                {
                    case '+': tocal.push(first + second);break;
                    case '-': tocal.push(first - second);break;
                    case '*': tocal.push(first * second);break;
                    case '/': tocal.push(first / second);break;
                    case '^':
                        int pow;
                        for(pow = 1;second > 0;second--)
                        {
                            pow*=first;
                        }
                        tocal.push(pow);break;
                }
            }
            i++;
        }
        cout << tocal.top() << endl;
        tocal.pop();
    }
    void work()
    {
        while (cin >> temp)//？？？无法结束输入！！！但是结果是正确的。。
        {
            for(int i = 0; i<1000; i++)
            {
                ex[i] = out[i] = '\0';
            }
            strcpy(ex, temp);
            midtopos();
            calculate();
        }
    }
    
};
int main(int argc, const char * argv[]) {
    cal test;
    test.work();
    return 0;
}
