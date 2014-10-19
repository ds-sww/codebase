#include<iostream>
#include<cstdio>
#include<cstring>

#include "Matcher.h"

using namespace std;

class BruteForceImpl : public Matcher {

	private :
		string pattern;


	public :
		explicit BruteForceImpl(string pattern) {
            this->pattern=pattern;		
		}

		virtual int find(string text) {
            if (text.size()<pattern.size()) return NOT_FOUND;
			for (int i=0;i<text.size()-pattern.size()+1; ++i)
            {
				int cnt=0;
                for (int j=0;j<pattern.size();j++) if (text[i+j]!=pattern[j]) break; else cnt++;
                if (cnt==pattern.size()) return i;
			}
			return NOT_FOUND;
		}

		virtual ~BruteForceImpl() {

		}
};

