/**
 * @author sunqinzheng
 * @date   2014.10.13
 *
 */
#include "BruteForceImpl.h"

BruteForceImpl::BruteForceImpl(const string& p) 
{
    pattern = p;
}

int BruteForceImpl::find(string text) {
    for(int i = 0; i <= text.length() - pattern.length(); i++)
    {
        if(pattern == text.substr(i, pattern.length()))
        {
            return i;
        }
    }
    return NOT_FOUND;
}
        
BruteForceImpl::~BruteForceImpl(){}



