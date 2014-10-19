/**
* @author 'DogeDogeDogeDoge' + 'A' * 128 + struct.pack('>I',address_of_your_cute_gadget) + CHAIN
* @date   2014.10.20
* 
* #> I've implemented many (useless) things to guaranteee its' worst-case RUN TIME (but not complexity).
*  > And that add a BIG constant factor.
**/

#include <ctime>
#include <cstdlib>
#include <string>
#include "Matcher.h"

using namespace std;

const int MODULO[] = {(int)1e9 + 7, (int)1e9 + 9};
const int MODULO_COUNT = sizeof(MODULO) / sizeof(MODULO[0]);

class KarpRabinImpl : public Matcher
{
private:
	string pattern;
	int SEED;
	int hashes[MODULO_COUNT];
	int reverty[MODULO_COUNT];

public:
	explicit KarpRabinImpl(const string& pattern)
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

	virtual int find(const string& text) const
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

	virtual ~KarpRabinImpl()
	{

	}
};
