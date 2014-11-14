/**
 * @author Xuan Yuan
 * @date   2014.10.1
 *
 */

#include <iostream>
#include <cstdio>
#include <string>

#include "Matcher.h"

using namespace std;

class BruteForceImpl : public Matcher {
    
    private :
        string pattern;


    public :
        explicit BruteForceImpl(const string& p) {
            this->pattern = p;
        }

        virtual int find(string text) {
            int i, j;
            for (i = 0; i <= text.length()-pattern.length(); i++) {
                for (j = 0; j < pattern.length(); j++) {
                    if (text[i+j] != pattern[j]) {
                        break;
                    }
                }
                if (j == pattern.length()) {
                    return i;
                }
            }
            return NOT_FOUND;
        }
        
        virtual ~BruteForceImpl() {
            //do nothing...
        }
};



