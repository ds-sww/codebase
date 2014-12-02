
//
//  main.cpp
//  C
//
//  Created by 陈裕昕 on 9/29/14.
//  Copyright (c) 2014 陈裕昕. All rights reserved.
//

#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

struct Stu
{
	int id, sum, chn, eng, math;
    
public:
    
	void setid(int _id)
	{
		id = _id;
	}
	
	void read()
	{
		scanf("%d%d%d", &chn, &math, &eng);
		sum = chn + math + eng;
	}
}stu[305];

int N;

bool operator< (Stu stu1, Stu stu2)
{
	if(stu1.sum == stu2.sum)
	{
		if(stu1.chn == stu2.chn)
		{
			return stu1.id > stu2.id;
		}
		else
		{
			return stu1.chn < stu2.chn;
		}
	}
	else
	{
		return stu1.sum < stu2.sum;
	}
}

void init()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
        stu[i].setid(i + 1);
		stu[i].read();
	}
}

void work()
{
	sort(stu, stu + N);
	for(int i = N - 1; i >= N - 5; i--)
	{
		printf("%d %d\n", stu[i].id, stu[i].sum);
	}
}

int main()
{
	init();
	work();
	return 0;
}
