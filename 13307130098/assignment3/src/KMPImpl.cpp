/**
 * @author sunqinzheng
 * @date 2014.10.15
 */


#include "KMPImpl.h"

KMPImpl::KMPImpl(string p)
{
    pattern = p;
    prev.resize(pattern.length());
    prev[0] = -1;
    for(int i = 1, j = -1; i < p.length(); i++)
    {
        while(p[i] != p[j + 1] && j != -1)
        {
            j = prev[j];
        }
        if(p[i] == p[j + 1])
        {
            j++;
        }
        prev[i] = j;
    }
}

int KMPImpl::find(string text)
{
    for(int i = 0, j = -1; i < text.length(); i++)
    {
        while(text[i] != pattern[j + 1] && j != -1)
        {
            j = prev[j];
        }
        if(text[i] == pattern[j + 1])
        {
            j++;
        }
        if(j == pattern.length() - 1)
        {
            return i - j;
        }
    }
    return NOT_FOUND; 
}

KMPImpl::~KMPImpl() {}

