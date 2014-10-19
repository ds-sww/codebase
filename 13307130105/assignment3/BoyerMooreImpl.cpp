/**
* @author 'DogeDogeDogeDoge' + 'A' * 128 + struct.pack('>I',address_of_your_cute_gadget) + CHAIN
* @date 2014.10.20
* 
* #> Too tired to implement Gaili's rule. 
*/

#include <string>
#include <algorithm>

#include "Matcher.h"

using namespace std;

const int ALPHABET_SIZE = 256;

class BoyerMooreImpl : public Matcher
{
private:
	string pattern;
	int badCharShifty[ALPHABET_SIZE];
	int* goodSuffixShifty;
	int zFunction(int* zF, int patLen)
	{
		zF[0] = patLen;
		memset(zF,0,sizeof(*zF)*patLen);
		int farfrom = 0;
		int far = 1;
		for(int i = 1;i < patLen;i++)
		{
			if(i+zF[i-farfrom] >= far)
			{
				int x = max(far,i);
				while(x < patLen && x-i < patLen && pattern[patLen-1-x] == pattern[patLen-1-x+i]) x++;
				zF[i] = x-i;
				if(i < x) { farfrom = i; far = x; }
			}
			else zF[i] = zF[i-farfrom];
		}
		return 0;
	}
public:
	BoyerMooreImpl(const string& pattern)
	{
		this->pattern = pattern;

		int patLen = pattern.length();
		fill(badCharShifty,badCharShifty+ALPHABET_SIZE,patLen);
		for(int i = 0;i < patLen-1;i++)
			badCharShifty[pattern[i]] = patLen-1-i;

		goodSuffixShifty = new int[patLen];
		fill(goodSuffixShifty,goodSuffixShifty+patLen,patLen);
		// do something similiar to KMP. (Z-Algorithm or what you like)
		int* zF = new int[patLen];
		zFunction(zF, patLen);

		int pos = 0;
		for(int i = patLen-2;i >= 0;i--)
			if(zF[patLen-1-i] == i+1) // whole prefix matches suffix
				for(;pos < patLen-1-i;pos++)
					goodSuffixShifty[pos] = patLen-1-i;

		for(int i = 0;i < patLen-1;i++)
			goodSuffixShifty[patLen-1-zF[patLen-1-i]] = patLen-1-i;
		delete[] zF;
	}

	virtual int find(const string& text) const
	{
		int textLen = text.length();
		int patLen = pattern.length();
		for(int i = 0;i < textLen-patLen+1;)
		{
			int tail = patLen-1;
			while(tail >= 0 && text[i+tail] == pattern[tail]) tail--;
			if(tail < 0) return i;
			i += max(goodSuffixShifty[tail], badCharShifty[text[i+tail]] - (patLen-1-tail));
		}
		return NOT_FOUND;
	}

	virtual ~BoyerMooreImpl()
	{
		if(goodSuffixShifty) delete[] goodSuffixShifty;
	}
};

