/**
* @author 'DogeDogeDogeDoge' + 'A' * 128 + struct.pack('>I',address_of_your_cute_gadget) + CHAIN
* @date   2014.10.20
* 
* #> I've implemented many (useless) things to guaranteee its' worst-case RUN TIME (but not complexity).
*  > And that add a BIG constant factor.
**/

#include "KarpRabinImpl.h"

// Seriously, why do you think "#include <blahblah.cpp>" is a good idea?!
const int KarpRabinImpl::MODULO[2] = {(int)1e9 + 7, (int)1e9 + 9};

KarpRabinImpl::~KarpRabinImpl()
{

}

int KarpRabinImpl::find( const string& text ) const
{
	int patternLen = pattern.length();
	int textLen = text.length();
	if(textLen < patternLen) return NOT_FOUND;
	if(patternLen == 0) return 0;

	int curHashes[MODULO_COUNT];
	fill(curHashes,curHashes+MODULO_COUNT,0); // abusing multi-byte char constant
	for(int i = 0;i < textLen;i++)
	{
		for(int j = 0;j < MODULO_COUNT;j++)
		{
			curHashes[j] = ((long long)curHashes[j] * SEED + text[i]) % MODULO[j];
			if(i >= patternLen)
				curHashes[j] = ((curHashes[j] - (long long)reverty[j] * text[i-patternLen]) % MODULO[j] + MODULO[j]) % MODULO[j];
		}
		if(i < patternLen-1) continue;

		if(equal(curHashes,curHashes+MODULO_COUNT,hashes))
		{
			if(equal(pattern.begin(),pattern.end(),text.begin()+i-patternLen+1)) // much slower than strcmp
			{
				return i - patternLen + 1;
			}
		}
	}
	return NOT_FOUND;
}

KarpRabinImpl::KarpRabinImpl( const string& pattern )
{
	this->pattern = pattern;
	srand(time(NULL));
	SEED = rand() % 1201 + 137; // it's still weak, indeed
	fill(hashes,hashes+MODULO_COUNT,0); // abusing multi-byte char constant
	for(int i = 0;i < pattern.length();i++)
	{
		for(int j = 0;j < MODULO_COUNT;j++)
		{
			hashes[j] = ((long long)hashes[j] * SEED + pattern[i]) % MODULO[j];
		}
	}

	for(int j = 0;j < MODULO_COUNT;j++)
	{
		reverty[j] = 1;
		for(int i = 0;i < pattern.length();i++)
			reverty[j] = (long long)reverty[j] * SEED % MODULO[j];
	}
}
