/**
 * @author irmo
 * @date   2014.10.20
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>

#include "Matcher.h"

using namespace std;

class BruteForceImpl : public Matcher {
    
    private :
    string pattern;
    
    
    public :
    explicit BruteForceImpl(const string& pattern) {
        (*this).pattern = pattern;
    }
    
    virtual int find(string text) {
        bool find = false;
        for (int pos=0; pos < text.size(); pos++) {
            if (text.size() - pos < pattern.size())
                return NOT_FOUND;
            for (int now=0; now < pattern.size(); now++)
                if(text[now+pos] != pattern[now])
                    break;
                else if(now == pattern.size()-1){
                    find = true;
                    break;
                }
            if(find)
                return pos;
        }
        
        return NOT_FOUND;
    }
    
    virtual ~BruteForceImpl() {
        
    }
};