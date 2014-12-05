//
//  main.cpp
//  poj2371
//
//  Created by billlai on 14-11-8.
//  Copyright (c) 2014年 billlai. All rights reserved.
//

#include <iostream>
using namespace std;

int partition(int a[], int l, int r)
{
    int t = a[r];
    int i = l-1;
    int j = r;
    int swap;
    while(1)
    {
        while(a[++i]<t) ;
        while(a[--j]>=t) if(j==l) break;
        if(i>=j) break;
        swap = a[i];
        a[i] = a[j];
        a[j] = swap;
    }
    swap = a[i];
    a[i] = a[r];
    a[r] = swap;
    return i;
}

void sort(int a[], int l, int r)
{
    if(l>=r) return;
    int i;
    i = partition(a,l,r);
    sort(a, l, i-1);
    sort(a, i+1, r);
}

class poj2371
{
public:
    int* data;
    int size;
    int time;
    int num;
    ~poj2371()
    {
        delete []data;
    }
    void input()
    {
        cin >> size;
        data = new int[size];
        for(int i = 0; i<size; i++)
        {
            cin >> data[i];
        }
        char waste[4];
        cin >> waste[0] >> waste[1] >> waste[2];
        cin >> time;
        sort(data, 0, size-1);
        for(int i = 0; i<time; i++)
        {
            cin >> num;
            cout << data[num-1] << endl;
        }
    }
};
int main(int argc, const char * argv[]) {
    poj2371 test;
    test.input();
}
