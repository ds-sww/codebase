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

class KarpRabinImpl : public Matcher
{
private:
	const static int MODULO[2];
	const static int MODULO_COUNT = 2;

	string pattern;
	int SEED;
	int hashes[MODULO_COUNT];
	int reverty[MODULO_COUNT];

public:
	explicit KarpRabinImpl(const string& pattern); 

	virtual int find(const string& text) const;

	virtual ~KarpRabinImpl();
};
