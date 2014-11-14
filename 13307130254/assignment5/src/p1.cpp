/*
*	Copyright (C)	Lyq root#lyq.me
*	File Name     : p1.cpp
*	Creation Time : 2014/10/27 20:20:59
*	Environment   : Ubuntu 14.04-64bit
*	Hompage       : http://www.lyq.me
*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

char text[3000], pattern[3000];

int main()
{
    //freopen("in", "r", stdin);

    while (scanf("%s%s", text, pattern) != EOF)
    {
        int len_text = strlen(text);
        int len_pattern = strlen(pattern);
        int is_find;
        bool is_none;

        is_none = true;
        for (int i = 0; i < len_text; i++)
        {
            if (i + len_pattern > len_text) break;

            is_find = i;
            for (int j = 0; j < len_pattern; j++)
            {
                if (pattern[j] != text[i+j])
                {
                    is_find = -1;
                    break;
                }
            }
            if (is_find != -1)
            {
                printf("%d ", is_find);
                is_none = false;
            }
        }
        if (is_none) printf("-1");
        printf("\n");
    }

    //system("pause");
    return 0;
}

