//
//  main.cpp
//  A
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

int N, M, DR, DC, KR, KC, SR, SC, TR, TC;
char map[25][25];
queue<pair<pair<int, int>, int> > Q;
int fr[4] = {0, 0, 1, -1};
int fc[4] = {1, -1, 0, 0};

void init()
{
    DR = DC = KR = KC = -1;
    scanf("%d%d", &N, &M);
    for(int r = 1; r <= N; r++)
    {
        getchar();
        for(int c = 1; c <= M; c++)
        {
            char ch;
            scanf("%c", &ch);
            if(ch == '*')
            {
                map[r][c] = 1;
            }
            else if(ch == 'D')
            {
                DR = r;
                DC = c;
                map[r][c] = 2;
            }
            else if(ch == 'K')
            {
                KR = r;
                KC = c;
                map[r][c] = 1;
            }
            else if(ch == 'S')
            {
                SR = r;
                SC = c;
                map[r][c] = 1;
            }
            else if(ch == 'T')
            {
                TR = r;
                TC = c;
                map[r][c] = 1;
            }
        }
    }
}

int search(int sr, int sc, int tr, int tc)
{
	while(!Q.empty()) Q.pop();

    Q.push(make_pair(make_pair(sr, sc), 0));
    map[sr][sc] = -1;
    
    while(!Q.empty())
    {
        int t = Q.front().second;
        int r = Q.front().first.first;
        int c = Q.front().first.second;
        Q.pop();
        
        if(r == tr && c == tc)
        {
            //while(!Q.empty()) Q.pop();
            return t;
        }
        
        for(int d = 0; d < 4; d++)
        {
            int nr = r + fr[d], nc = c + fc[d];
            if(map[nr][nc] == 1)
            {
                map[nr][nc] = -1;
                Q.push(make_pair(make_pair(nr, nc), t + 1));
            }
        }
    }
    
    return -1;
}

void mapResume()
{
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            if(map[i][j] == -1) map[i][j] = 1;
        }
    }
}

int work()
{
    int ret = search(SR, SC, TR, TC);
    int ret2 = -1, tmp;
    mapResume();
    map[KR][KC] = 1;
    
    if(!((KR != -1 && KC != -1) && (DR != -1 && DC != -1))) return ret;
    
    if((tmp = search(SR, SC, KR, KC)) != -1)
    {
        ret2 = tmp;
        mapResume();
        map[DR][DC] = 1;
        if((tmp = search(KR, KC, DR, DC)) != -1)
        {
            ret2 += tmp;
            mapResume();
            if((tmp = search(DR, DC, TR, TC)) != -1)
            {
                ret2 += tmp;
            }
            else
            {
                ret2 = -1;
            }
        }
        else
        {
            ret2 = -1;
        }
    }
	//cout << "ret: " << ret << " ret2: " << ret2 << endl; 
    if(ret == -1 && ret2 == -1)
        return -1;
    if(ret == -1) return ret2;
    if(ret2 == -1) return ret;
    return min(ret, ret2);
}

int main()
{
    init();
    cout << work() << endl;
    return 0;
}
