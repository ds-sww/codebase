//
//  main.cpp
//  window
//  
//  Created by irmo on 14/10/27.
//  Copyright (c) 2014年 apple. All rights reserved.
//

#include <iostream>
#include <deque>
#define Max_Size 100000
using namespace std;

struct elem {
    int value;
    int location;
};
int main(int argc, const char * argv[]) {
    
    int n,k;        //n:array_length, k:window_length, x:current element;
    int elements[Max_Size];
    elem x;
    cin >> n >> k;
    for (int i=0; i<n; i++) cin >> elements[i];         //read
    
    deque <elem> min;
    for (int i=0; i<k; i++) {
        x.value = elements[i];
        x.location = i;
        while ( !min.empty() && min.back().value >= x.value) min.pop_back();
        if ( min.empty() || min.back().value < x.value)
            min.push_back(x);
    }                                                   // handle the first k elements
    cout << min.front().value;
    for (int i=k;i<n;i++) {
        x.value = elements[i];
        x.location = i;
        if (min.front().location == i-k) min.pop_front();
        while ( !min.empty() && min.back().value >= x.value) min.pop_back();
        if (min.empty() || min.back().value < x.value)
            min.push_back(x);
        cout << " " << min.front().value;
    }
    cout << endl;
    
    deque <elem> max;
    for (int i=0; i<k; i++) {
        x.value = elements[i];
        x.location = i;
        while ( !max.empty() && max.back().value <= x.value) max.pop_back();
        if ( max.empty() || max.back().value > x.value)
            max.push_back(x);
    }                                                   // handle the first k elements
    cout << max.front().value;
    for (int i=k; i<n; i++) {
        x.value = elements[i];
        x.location = i;
        if (max.front().location == i-k) max.pop_front();
        while ( !max.empty() && max.back().value <= x.value) max.pop_back();
        if (max.empty() || max.back().value > x.value)
            max.push_back(x);
        cout << " " << max.front().value;
    }
    cout << endl;
    
    return 0;
}
