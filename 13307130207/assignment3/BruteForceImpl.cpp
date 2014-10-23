/**
 * @author chiyahoho
 * @date   2014.10.13
 */

#include <iostream>
#include <string>
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
            int n=text.length(),m=pattern.length();
            for (int i=0;i<=n-m;i++){
                int flag=1;
                for(int j=0;j<m;j++)
                    if (pattern[j]!=text[i+j]){
                        flag=0;
                        break;
                    }
                if (flag) return i;
            }
            return NOT_FOUND;
        }

        virtual ~BruteForceImpl() {
        }
};



