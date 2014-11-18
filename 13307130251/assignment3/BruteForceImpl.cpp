
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
			for(int i=0;text[i]!=0;i++)
				for(int j=0;pattern[j]!=0;j++){
					if(text[i+j]!=pattern[j])
						break;
					if(pattern[j+1]==0)
						return i;
				}
            return NOT_FOUND;
        }
        
        virtual ~BruteForceImpl() {
        }
};



