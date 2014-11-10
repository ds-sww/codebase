//BruteForceImpl
#include <iostream>
#include <cstdio>
#include <cstring>

#include "Matcher.h"

using namespace std;

class BruteForceImpl : public Matcher {
    
private :
        string pattern;


public :
        explicit BruteForceImpl(const string& p);
        virtual int find(string text);
        virtual ~BruteForceImpl();
};
BruteForceImpl::BruteForceImpl(const string& p)
{
	pattern=p;
}
int BruteForceImpl::find(string text)
{
	int j,i;
	int a=text.length(),b=pattern.length();
	for(i=0;i<a-b;i++)
	{
		for(j=0;j<b;)
		{
			if(pattern[j]!=text[i+j])
				break;
			j++;
		}
		if(j==b)
			break;
	}
	if(j==b)
		return i;
	else return NOT_FOUND;
}
BruteForceImpl::~BruteForceImpl()
{
}

