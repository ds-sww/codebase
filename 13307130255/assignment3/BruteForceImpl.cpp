/**
 * @author whimsycwd
 * @date   2014.10.1
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
            this->pattern = pattern;
        }

        virtual int find(string &text) {
            int pattern_len = pattern.length();
            int text_len = text.length();
            int cur = 0;
            while (cur < text_len - pattern_len + 1)
            {
                int s=cur,t=0;
                while(text[s]==pattern[t] && t<pattern_len ) { s++; t++;}
                if (t == pattern_len) return cur;  
                cur++;              
            }
            return NOT_FOUND;
        }
        
        virtual ~BruteForceImpl() {
            
        }
};



