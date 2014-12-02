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
        	int i,j;
        	i = j = 0;
        	for(i=0;i < text.size();i++){
        		for(j=0;j < pattern.size();j++){
        			if(text[i+j] != pattern[j])break;
        		}
        		if(pattern[j] == '\0')break;
        	}
        	if(pattern[j] == '\0')return i;
            return NOT_FOUND;
        }
        
        virtual ~BruteForceImpl() {
            
        }
};



