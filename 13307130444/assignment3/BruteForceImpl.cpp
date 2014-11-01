<<<<<<< HEAD
#include<cstdio>
#include<iostream>
#include<cstring>

#include"Matcher.h"

using namespace std;

class BruteForceImpl: public Matcher {
	string pattern;
public:
	explicit BruteForceImpl(const string&pattern){this->pattern=pattern;};//非隐式转换
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





=======
#include<cstdio>
#include<iostream>
#include<cstring>

#include"Matcher.h"

using namespace std;

class BruteForceImpl: public Matcher {
	string pattern;
public:
	explicit BruteForceImpl(const string&pattern){
		string tmp(pattern);
		this->pattern=tmp;};//非隐式转换
	virtual int find( const string text);
	virtual ~BruteForceImpl(){};
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





>>>>>>> ec407af6da0a41f7a45c22494e5f671192a1f89b
