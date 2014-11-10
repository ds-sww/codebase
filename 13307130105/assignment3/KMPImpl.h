/**
* @author 'DogeDogeDogeDoge' + 'A' * 128 + struct.pack('>I',address_of_your_cute_gadget) + CHAIN
* @date 2014.10.20
*/

#include <string>
#include "Matcher.h"

using namespace std;

class KMPImpl : public Matcher
{
private:
	string pattern;
	int* knext;

public:
	KMPImpl(const string& pattern);

	virtual int find(const string& text) const;

	virtual ~KMPImpl();
};
