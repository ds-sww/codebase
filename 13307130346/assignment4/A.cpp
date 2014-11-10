//
//  main.cpp
//  Rails
//
//  Created by billlai on 14-10-20.
//  Copyright (c) 2014年 billlai. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
#include <deque>
using namespace std;
class rails
{
public:
    stack<int> content;
    int* series;
    int length;
    int temp;
    int judge()
    {
        int j = 1;
        int i = 0;
        while(1)
        {
            while (j<=series[i])
            {
                content.push(j++);
            }
            while(series[i] == content.top())
            {
                content.pop();
                i++;
                if(i == length-1)
                {
                    cout << "Yes" << endl;
                    return 0;
                }
                if(content.empty())
                    break;
            }
            if(content.empty())
                continue;
            if(series[i]<content.top())
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    void getcontent()
    {
        series = new int[length];
        for(int j = 0;j<length;j++)
            cin >> series[j];
        judge();
        
    }
    void getcontentagain()
    {
        series = new int[length];
        series[0] = temp;
        for(int j = 1;j<length;j++)
            cin >> series[j];
        judge();
    }
    void work()
    {
        cin >> temp;
        while (temp)
        {
            int flag = 0;
            length = temp;
            while(temp)
            {
                if (!flag)
                        getcontent();
                else getcontentagain();
                cin >> temp;
                flag = 1;
            }
            cin >> temp;
            if(temp)
                cout << endl;
        }
    }
};

int main(int argc, const char * argv[]) {
    rails test;
    test.work();
    return 0;
}
