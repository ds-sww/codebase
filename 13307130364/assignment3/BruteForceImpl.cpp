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
		int length;

    public :
        explicit BruteForceImpl(const string& pattern) {
			this->pattern = pattern;
			length = pattern.length();
        }

        virtual int find(string text) {
			int count=0;
			for (string::iterator it = text.begin(); text.end() - it >= length; it++, count++){
				string::iterator t = it;
				string::iterator m = pattern.begin();
				for (;t < it + length&&*t == *m; t++, m++)
					if (t == it + length - 1)
						return count;
			}
            return NOT_FOUND;
        }
        
        virtual ~BruteForceImpl() {
            
        }
};



