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
            this->pattern=pattern;
        }

        virtual int find(string text) {
            int len1=text.size();
            int len2=pattern.size();
            int j;
            if (len1<len2) return NOT_FOUND;
            for (int i=0;i<=len1-len2;i++)
            {
                for (j=0; j<len2; j++)
                    if (text[j+i]!=pattern[j]) break;
                    
                if (j==len2) return i;
            }
            return NOT_FOUND;
        }
        
        virtual ~BruteForceImpl() {
            
        }
};



