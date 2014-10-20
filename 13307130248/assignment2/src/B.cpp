//
//  main.cpp
//  B
//
//  Created by 陈裕昕 on 9/29/14.
//  Copyright (c) 2014 陈裕昕. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;

struct myInt
{
    int num;
    
    myInt()
    {
        num = 0;
    }
    
    myInt(int _num)
    {
        num = _num;
    }
};

bool operator< (myInt a, myInt b)
{
    return a.num > b.num;
}

int N;
priority_queue<myInt> Q;

void init()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        myInt weight;
        scanf("%d", &weight.num);
        Q.push(weight.num);
    }
}

void work()
{
    int sum = 0;
    for(int i = 1; i < N; i++)
    {
        int tmp = Q.top().num;
        Q.pop();
        tmp += Q.top().num;
        Q.pop();
        Q.push(myInt(tmp));
        sum += tmp;
    }
    printf("%d\n", sum);
}

int main()
{
    init();
    work();
    return 0;
}
