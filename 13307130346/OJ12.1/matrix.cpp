//
//  main.cpp
//  poj3685
//
//  Created by billlai on 14-12-1.
//  Copyright (c) 2014年 billlai. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll n, m;

long long cal(ll i, ll j)
{
    return i*i + 100000*i + j*j - 100000*j + i*j;
}
int main(int argc, const char * argv[]) {
    ll time;
    cin >> time;
    for(ll timecnt = 0; timecnt < time; timecnt++)
    {
        cin >> n >> m;
        ll min = -100000*n;
        ll max = 7500000001;
        ll mid = 0;
        while(min<=max)
        {
            ll res = 0;
            mid = (min+max)>>1;
            for(ll j = 1; j<=n; j++)
            {
                ll top = 1, bottom = n;
                ll middle = 0;
                ll calres = 0;
                while(top<=bottom)
                {
                    middle = (top + bottom)>>1;
                    calres = cal(middle,j);
                    //cout << "calres when middle, j = " << middle << ' '<< j<<" is "<< calres << endl;
                    if(calres > mid)
                    {
                        bottom = middle - 1;
                    }
                    else
                    {
                        top = middle + 1;
                    }
                }
                //if(calres == mid) res += bottom - 1;
                res += bottom;
                //cout << "res is " << res << endl;
            }
            if(res >= m)
            {
                max = mid - 1;
            }
            else
            {
                min = mid + 1;
            }
            //cout << "max : " << max << ' '<< "min : " << min << endl;
        }
            cout << min << endl;
    }
    return 0;
}
