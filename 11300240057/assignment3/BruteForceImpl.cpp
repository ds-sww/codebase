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

        virtual int find(string text) {
            if (text.size() < pattern.size()) {
                return NOT_FOUND;
            }
            // must `<=` instead of `<`
            for (int i = 0; i <= text.size() - pattern.size(); ++i) {
                
                bool isMatch = true;
                int j = 0;
                while (isMatch && j < pattern.size()) {
                    isMatch &= text[i+j] == pattern[j];
                    ++j;
                }
                
                if (isMatch) {
                    return i;
                }
            }
            return NOT_FOUND;
        }
        
        virtual ~BruteForceImpl() {
            
        }
};



