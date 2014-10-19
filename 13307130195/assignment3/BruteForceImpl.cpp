//  Created by forward on 10/12/14.

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

        virtual int find(const string &text) {
            bool match;
            for (int i = 0; i <= text.length() - pattern.length(); i++)
            {
                match = true;
                for (int j = 0; j < pattern.length(); j++)
                if (text[i+j] != pattern[j]) 
                {
                    match = false;
                    break;
                }
                if (match) return i;
            }
            return NOT_FOUND;
        }
        
        virtual ~BruteForceImpl() {
            
        }
};



