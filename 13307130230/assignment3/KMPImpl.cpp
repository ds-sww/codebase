/**
 * @author tenstep
 * @date 2014.10.16
 */


#include<string>
#include<vector>

#include "Matcher.h"

using namespace std;

class KMPImpl : public Matcher {
    private : 
        string pattern;

    public :
        KMPImpl(string pattern) {
        	this->pattern=pattern;
        }

        virtual int find(string text) 
        {
        	int n=text.size();
        	int m=pattern.size();
        	vector<int> fail(m);
        	
        	for (int i=0;i<m;i++)
        	{
        		fail[i]=i-1;
        		while (fail[i]!=-1&&pattern[fail[i]+1]!=pattern[i]) 
        			fail[i]=fail[fail[i]];
        	}
        	
        	int now=-1;
        	for (int i=0;i<n;i++)
        	{
        		if (now!=-1&&pattern[now+1]!=text[i]) now=fail[now];
        		if (pattern[now+1]==text[i]) now++;
        		if (now==m-1) return i-m+1;
        	}
            return NOT_FOUND; 
        }

        virtual ~KMPImpl() {
        }
};
