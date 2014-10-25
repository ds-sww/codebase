/**
 * @author aixile
 * @date   2014.10.13
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
        explicit BruteForceImpl(const string& pattern):pattern(pattern) {
        }

        virtual int find(string text) {
			for(int i=0;i<text.length()-pattern.length()+1;i++){
				int j=0;
				for(;j<pattern.length()&&text[i+j]==pattern[j];j++);
				if(j==pattern.length())	return i;
			}
            return NOT_FOUND;
        }
        
        virtual ~BruteForceImpl() {
            
        }
};
