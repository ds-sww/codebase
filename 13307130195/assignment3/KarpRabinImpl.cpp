//  Created by forward on 10/12/14.

#include <iostream>
#include <string>

#include "Matcher.h"

using namespace std;

class KarpRabinImpl : public Matcher {
    
    private :
        const static int p = 1000000007;
        string pattern;
        int n, pattern_hash, *pow_n;

    public :

        explicit KarpRabinImpl(const string &pattern) {
            this->pattern = pattern;
            n = pattern.length();
            pow_n = new int[n];
        } 

        bool check(const string &text, int pos)
        {
            for (int i = 0; i < n; i++)
                if (text[pos+i] != pattern[i]) return false;
            return true;
        }
        
        virtual int find(const string &text) {
            int m = text.length();
            if (m < n) return NOT_FOUND;

            pow_n[0] = 1;
            for (int i = 1; i < n; i++) pow_n[i] = (long long)pow_n[i-1] * 256 % p;

            pattern_hash = 0;
            for (int i = 0; i < n; i++)
            {
                pattern_hash = (pattern_hash + (long long)pow_n[n-i-1] * pattern[i] % p) % p;
            }

            int text_hash = 0;
            for (int i = 0; i < n; i++)
            {
                text_hash = (long long)(text_hash + (long long)pow_n[n-i-1] * text[i] % p) % p;
            }

            if (text_hash == pattern_hash && check(text, 0)) return 0;
            int rehash = text_hash;
            for (int i = n; i < m; i++)
            {
                rehash = ((long long)(rehash - (long long)pow_n[n-1] * text[i - n] % p + p) * 256 % p + text[i]) % p;
                if (rehash == pattern_hash && check(text, i - n + 1)) return i - n + 1;
            }
            return NOT_FOUND;
        }

        virtual ~KarpRabinImpl() {
        }
};

