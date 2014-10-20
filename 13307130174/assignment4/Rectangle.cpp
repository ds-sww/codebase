//
//  main.cpp
//  OJ1020-2
//
//  Created by irmo on 14/10/20.
//  Copyright (c) 2014年 apple. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

struct element{
    int height;
    int count;
};
int main(int argc, const char * argv[]) {
    
    int n;
    while((cin >> n) && n){
        long long max = 0;
        stack <element> s;
        int h = 0;
        for (int i=1; i<=n; i++) {
            scanf("%d", &h);
            element one;
            one.height=h;
            one.count=1;
            int c=0;
            while (!s.empty() && s.top().height>=h) {
                long long area=s.top().height*s.top().count;
                if (area > max) max = area;
                c=s.top().count;
                s.pop();
                if (!s.empty()) s.top().count+=c;
            }
            one.count+=c;
            s.push(one);
        };
        while (!s.empty()) {
            long long area=s.top().height*s.top().count;
            if (area > max) max =area;
            int c=s.top().count;
            s.pop();
            if (!s.empty()) s.top().count+=c;
        }
        cout << max<<endl;
    }

    return 0;
}
