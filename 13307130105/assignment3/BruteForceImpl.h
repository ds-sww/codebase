/**
* @author 'DogeDogeDogeDoge' + 'A' * 128 + struct.pack('>I',address_of_your_cute_gadget) + CHAIN
* @date   2014.10.20
*/

#include <string>
#include "Matcher.h"

using namespace std;

class BruteForceImpl : public Matcher
{
private:
	string pattern;

public:
	explicit BruteForceImpl(const string& pattern)
	{
		this->pattern = pattern;
	}

	virtual int find(const string& text) const
	{
		int patternLen = pattern.length();
		int textLen = text.length();
		for(int i = 0;i < textLen-patternLen+1;i++)
		{
			int matched = 0;
			for(;matched < patternLen && pattern[matched] == text[i + matched];matched++);
			if(matched == patternLen) return i;
		}
		return NOT_FOUND;
	}

	virtual ~BruteForceImpl() {}
};
