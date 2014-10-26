/**
 * @author SiuTo
 * @date   2014.10.13
 */
#include<iostream>
#include<string>

#include "Matcher.h"

using namespace std;

class KarpRabinImpl : public Matcher {
    
    private :

        string pattern;
		static const int P=101, Q=10007;
		int pow_len, hash_patt;

    public :

        explicit KarpRabinImpl(const string & pattern)
		{
			this->pattern=pattern;
			pow_len=1;
			int m=pattern.size();
			for (int i=1; i<m; ++i) pow_len=pow_len*P%Q;
			hash_patt=0;
			for (int i=0; i<m; ++i) hash_patt=(hash_patt*P+pattern[i])%Q;
        } 
        
        virtual int find(const string & text) const
		{
			int n=text.size(), m=pattern.size();
			if (n<m) return NOT_FOUND;
			int hash_text=0;
			for (int i=0; i<m; ++i)	hash_text=(hash_text*P+text[i])%Q;
			for (int i=0; i<=n-m; ++i)
			{
				if (hash_patt==hash_text && text.substr(i, m)==pattern) return i;
				hash_text=(((hash_text-text[i]*pow_len)*P+text[i+m])%Q+Q)%Q;
			}
            return NOT_FOUND;
        }

        virtual ~KarpRabinImpl() {
        }
};
