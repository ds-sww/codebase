/**
 * @author sunqinzheng
 * @date   2014.10.15
 */

#include "BoyerMooreImpl.h"

BoyerMooreImpl::BoyerMooreImpl(string p)
{
    pattern = p;
    bc.assign(256, p.length());
    gs.assign(p.length(), p.length());
    suffix.resize(p.length());
    //bad character
    for(int i = 0; i < p.length(); i++)
    {
        bc[p[i]] = i;
    }
    //suffix
    for(int i = 0; i < p.length(); i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(p[i - j] == p[p.length() - 1 - j])
            {
                suffix[i]++;
            }
            else break;
        }
    }
    //good suffix
    for(int i = p.length() - 1, j = 0; i >= 0; i--)
    {
        if(suffix[i] == i + 1)
        {
            for(; j < p.length() - 1 - i; j++)
            {
                gs[j] = p.length() - 1 - i;
            }
        }
    }
    for(int i = 0; i < p.length() - 1; i++)
    {
        gs[p.length() - 1 - suffix[i]] = p.length() - 1 - i;
    }
}
       
int BoyerMooreImpl::find(string text)
{
    int j = 0;
    while(j <= text.length() - pattern.length())
    {
        int i = pattern.length() - 1;
        while(pattern[i] == text[j + i] && j >= 0)
        {
            i--;
        }
        if(i < 0)
        {
            return j;
        }
        else 
        {
            j += max(gs[i], i - bc[text[i + j]]);
        }
    }
    return NOT_FOUND;
}

BoyerMooreImpl::~BoyerMooreImpl() {}


