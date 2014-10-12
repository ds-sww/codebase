/**
 * @author Minjun-Li
 * @date   2014.10.11
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
            int n = text.size() - pattern.size() + 1;
            int m = pattern.size();
            for(int i = 0; i < n ; i++)
            {
                int j;
                for(j = 0; j < m; j++)
                {
                    if(text[i+j] != pattern[j])
                        break;
                }
                if(j == m)
                {
                    return i;
                }
            }
            return NOT_FOUND;
        }
        
        virtual ~BruteForceImpl() {
        }
};



