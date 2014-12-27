//
//  main.cpp
//  binary_search_oth
//
//  Created by billlai on 14-12-7.
//  Copyright (c) 2014年 billlai. All rights reserved.
//

#include <iostream>

using namespace std;

int num[10] = {0};

int bs_noright(int begin, int end, int tofind)
{
    int mid, left = begin, right = end;
    while(left <= right)
    {
        mid = (left+right)>>1;
        if(num[mid]>=tofind) right = mid-1;
        else left = mid+1;
    }
    return left;
}

int bs_yesleft(int begin, int end, int tofind)
{
    int mid, left = begin, right = end;
    while(left <= right)
    {
        mid = (left+right)>>1;
        if(num[mid]>=tofind) right = mid-1;
        else left = mid+1;
    }
    if(num[left] == tofind) return left;
    else return -1;
}

int bs_noleft(int begin, int end, int tofind)
{
    int mid, left = begin, right = end;
    while(left <= right)
    {
        mid = (left + right)>>1;
        if(num[mid] > tofind) right = mid - 1;
        else left = mid + 1;
    }
    return right;
}

int bs_yesright(int begin, int end, int tofind)
{
    int mid, left = begin, right = end;
    while(left <= right)
    {
        mid = (left + right)>>1;
        if(num[mid] > tofind) right = mid - 1;
        else left = mid + 1;
    }
    if(num[right] == tofind) return right;
    return -1;
}

int main(int argc, const char * argv[]) {
    return 0;
}
