/**
 * @author qini7
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
			this->pattern=pattern;
        }

        virtual int find(string text) {
			int text_size=text.length();
			int pattern_size=pattern.length();
			for (int i=0;i<text_size;i++)
			{
				int j=0;
				while ((text[i+j]==pattern[j])&&(j<pattern_size))
				{
					j++;
				}
				if (j==pattern_size) return i;
			}
        	return NOT_FOUND;
        }
        
        virtual ~BruteForceImpl() {
        
        }
};



