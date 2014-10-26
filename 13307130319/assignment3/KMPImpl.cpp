/**
 * @author SiuTo
 * @date 2014.10.13
 */


#include<string>
#include<vector>

#include "Matcher.h"

using namespace std;

class KMPImpl : public Matcher {
    private : 
        string pattern;
		int *p;

    public :
        KMPImpl(const string &pattern) {
			this->pattern=pattern;
			int m=pattern.size();
			int j=0;
			p=new int[m];
			p[0]=0;
			for (int i=1; i<m; ++i)
			{
				while (j && pattern[i]!=pattern[j]) j=p[j-1];
				if (pattern[i]==pattern[j]) ++j;
				p[i]=j;
			}
        }

        virtual int find(const string &text) const{
			int n=text.size(), m=pattern.size();
			int j=0;
			for (int i=0; i<n; ++i)
			{
				while (j && text[i]!=pattern[j]) j=p[j-1];
				if (text[i]==pattern[j]) ++j;
				if (j==m) return i-m+1;
			}
            return NOT_FOUND; 
        }

        virtual ~KMPImpl() {
			delete [] p;
        }
};

