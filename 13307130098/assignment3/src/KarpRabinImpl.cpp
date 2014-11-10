/**
 * @author sunqinzheng
 * @date   2014.10.13
 */
#include "KarpRabinImpl.h"

long long KarpRabinImpl::quickPow(long long b, int exp)
{
	if(exp == 0)
	{
		return 1;
	}
	long long tmp = quickPow(b, exp/2);
	long long res = tmp * tmp;
	res %= MOD;
	if(exp & 1)
	{
		res *= b;
	}
	res %= MOD;
	res += MOD;
	res %= MOD;
	return res;
}

KarpRabinImpl::KarpRabinImpl(const string & p)
{
	pattern = p;
	phash = 0;
	for(int i = 0; i < p.length(); i++)
	{
		phash *= BASE;
		phash += p[i];
		phash %= MOD;
	}
	step = quickPow(BASE, p.length() - 1);
}

int KarpRabinImpl::find(string text)
{
	long long hash = 0;
	for(int i = 0 ; i < pattern.length() - 1; i++)
	{
		hash *= BASE;
		hash += text[i];
		hash %= MOD;
	}
	for(int i = pattern.length() - 1; i < text.length(); i++)
	{
		int pos = i - pattern.length() + 1;
		hash *= BASE;
		hash += text[i];
		hash %= MOD;
		if(hash == phash)
		{
			return pos;
		}
		hash -= text[pos] * step;
		hash %= MOD;
		hash += MOD;
		hash %= MOD;
	}
    return NOT_FOUND;
}

KarpRabinImpl::~KarpRabinImpl() {}
