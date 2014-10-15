/**
 * @author liliang
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
		int len;

    public :
        explicit BruteForceImpl(const string& pattern) {
			this->pattern = pattern;
			len = pattern.size();
        }

        virtual int find(string text) {
			int n = text.size();
			int find = 0;
			for (int i = 0; i < n; i++)
			{
				find = 1;
				for (int j = 0; j < len;j++)
				if (pattern[j] != text[i+j])
				{
					find = 0; break;
				}
				if (find) return i;
			}
            return NOT_FOUND;
        }
        
        virtual ~BruteForceImpl() {
            
        }
};



