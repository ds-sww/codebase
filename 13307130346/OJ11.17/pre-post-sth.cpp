//
//  main.cpp
//  POJ1240s
//
//  Created by billlai on 14-11-19.
//  Copyright (c) 2014年 billlai. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
char pre[22], post[22];
int m;
stack<int> branchnum;

long long fac(int n) //计算阶乘
{
    long long temp = 1;
    for(int i = 2; i<=n; i++)
    {
        temp*=i;
    }
    return temp;
}
long long cal(int m, int n) //计算组合数
{
    return (fac(m)/fac(n))/fac(m-n);
}
void getbranch(int preleft, int preright, int postleft, int postright)
{
    if(preleft == preright && postleft == postright) return;
    int prepoint = preleft+1, postpoint = postleft, len = 0;
    int branch = 0;
    while(postpoint < postright){
        while(pre[prepoint]!=post[postpoint+len] && postpoint+len<postright) len++;
        branch++;
        getbranch(prepoint,prepoint+len,postpoint,postpoint+len);
        prepoint = prepoint+len+1;
        postpoint = postpoint+len+1;
        len = 0;
    }
    branchnum.push(branch);
}
int main(int argc, const char * argv[]) {
    int res = 1;
    while(cin >> m)
    {
        if(m==0) break;
        cin >> pre >> post;
        int length = (int)strlen(pre);
        res = 1;
        getbranch(0, length-1, 0, length-1);
        while(branchnum.empty() == 0)
        {
            res *= cal(m,branchnum.top());
            branchnum.pop();
        }
        cout << res << endl;
    }
        return 0;
}
