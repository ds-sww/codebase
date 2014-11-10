#include<cstdio>
#include<iostream>
#include<cstring>

#include"Matcher.h"

using namespace std;

class BruteForceImpl: public Matcher {
	string pattern;
public:
	explicit BruteForceImpl(const string&pattern){this->pattern=pattern;};//·ÇÒþÊ½×ª»»
	virtual int find( string text);
	virtual ~BruteForceImpl(){pattern.~string();};
};

int BruteForceImpl::find (const string text)
{
	int lt,lp,i,j,k;
	lt=text.length();lp=pattern.length();
	for(k=0;k<lt-lp+1;k++){
		for(j=0,i=k;j<lp&&text[i]==pattern[j];){
			i++;j++;}
			if(j==lp)return i-j;
		}
		return NOT_FOUND;
}


