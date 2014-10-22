/**
 * @author Hermes777
 * @date   2014.10.11
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
        	int i,j;
        	for(i=0;i<text.length()-pattern.length()+1;i++)
        	{
        		for(j=0;j<pattern.length();j++)
        		if(pattern[j]!=text[i+j])
        			break;
        		if(j==pattern.length())
        			return i;
        	}
            return NOT_FOUND;
        }
        
        virtual ~BruteForceImpl() {
            
        }
};

