//
//  main.cpp
//  combinenuts
//
//  Created by billlai on 14-9-29.
//  Copyright (c) 2014年 billlai. All rights reserved.
//

#include <iostream>
using namespace std;
class cn
{
public:
    int kind;
    int* nuts;
    int ene;
    int light1;
    int light2;
    int flag;
    void input()
    {
        cin >> kind;
        nuts = new int[kind];
        for(int i = 0;i<kind;i++)
        {
            cin >> nuts[i];
        }
        flag = 0;
        ene = 0;
    }
    void combine()
    {
        light2 = 0;
        light1 = 0;
        for(int i = 0;i<kind;i++)
        {
            if(nuts[i] != -1)
            {
                light1 = i;
                break;
            }
        }
        for(int i = 1;i<kind;i++)
        {

            if(nuts[i] != -1 && nuts[light1]>nuts[i])
                light1 =i;
        }
        for(int i = 0;i<kind;i++)
        {
            if(nuts[i] != -1 && light1 != i)
            {
                light2 = i;
                break;
            }
        }
        for(int i =0;i<kind;i++)
        {
            if(i == light1)
                continue;
            if(nuts[i] != -1 && nuts[light2]>nuts[i])
                light2 = i;
        }
        if(light2 == 0 && nuts[light2]==-1 && light1 != 0)
            flag = 1;
        //if(light1 == 0 && light2 == 1 && nuts[light2] == -1)
        if(light2 == 0 && light1 == 0)
            flag = 1;
    }
    void startc()
    {
        while(flag == 0)
        {
            combine();
            if(flag == 0)
            {
                nuts[light1]+=nuts[light2];
                ene+=nuts[light1];
                nuts[light2] = -1;
            }
        }
        cout << ene;
    }
    
};

int main()
{
    cn doit;
    doit.input();
    doit.startc();
    
    return 0;
}
