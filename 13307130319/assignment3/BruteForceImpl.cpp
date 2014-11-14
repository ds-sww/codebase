/**
 * @author SiuTo
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
        explicit BruteForceImpl(const string& pattern) {
			this->pattern=pattern;
        }

        virtual int find(const string &text) const{
			//return text.find(pattern);
			int n=text.size(), m=pattern.size();
			for (int i=0; i<=n-m; ++i)
			{
				bool match=true;
				for (int j=0; j<m; ++j)
					if (text[i+j]!=pattern[j])
					{
						match=false; break;
					}
				if (match) return i;
			}
            return NOT_FOUND;
        }
        
        virtual ~BruteForceImpl() {
            
        }
};



