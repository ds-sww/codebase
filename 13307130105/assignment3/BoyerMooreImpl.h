/**
* @author 'DogeDogeDogeDoge' + 'A' * 128 + struct.pack('>I',address_of_your_cute_gadget) + CHAIN
* @date 2014.10.20
* 
* #> I'm too tired to implement Gaili's rule. 
*  > The code below still has O(nm) worst-case time complexity, but it's really hard to ooxx it if we just need to find the first match.
*/

#include <string>
#include <algorithm>
#include <cstring>

#include "Matcher.h"

using namespace std;

class BoyerMooreImpl : public Matcher
{
private:
	const static int ALPHABET_SIZE = 256;
	string pattern;
	int badCharShifty[ALPHABET_SIZE];
	int* goodSuffixShifty;
	int zFunction(int* zF, int patLen);
public:
	BoyerMooreImpl(const string& pattern);

	virtual int find(const string& text) const;

	virtual ~BoyerMooreImpl();
};

