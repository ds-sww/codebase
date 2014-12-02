/**
* @author 'DogeDogeDogeDoge' + 'A' * 128 + struct.pack('>I',address_of_your_cute_gadget) + CHAIN
* @date 2014.10.20
*/

#include "KMPImpl.h"

KMPImpl::~KMPImpl()
{
	if(knext) delete[] knext;
}

int KMPImpl::find( const string& text ) const
{
	if(pattern.length() == 0) return 0;
	int matched = 0;
	for(int i = 0;i < text.length();i++)
	{
		while(matched && text[i] != pattern[matched]) matched = knext[matched-1];
		if(text[i] == pattern[matched]) matched++;
		if(matched == pattern.length()) return i-pattern.length()+1;
	}
	return NOT_FOUND;
}

KMPImpl::KMPImpl( const string& pattern )
{
	this->pattern = pattern;

	knext = new int[pattern.length()];

	int cur = 0;
	knext[0] = 0;
	for(int i = 1;i < pattern.length();i++)
	{
		while(cur && pattern[i] != pattern[cur]) cur = knext[cur-1];
		if(pattern[i] == pattern[cur]) cur++;
		knext[i] = cur;
	}
}
