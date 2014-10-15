/**
 * @author whimsycwd
 * @date   2014.10.1
 */
#include<iostream>
#include<string>

#include "Matcher.h"

using namespace std;

class KarpRabinImpl : public Matcher {
    
    private :

        string pattern;
        unsigned int hash;
        static const int prime = 9999991;

        unsigned int get_hash(const string &s)
        {
            unsigned int ret = 0;
            for(int i = 0; i < s.size(); i++)
            {
                ret = ((ret << 1) + s[i]) % prime;
            }
            return ret;
        }

    public :

        explicit KarpRabinImpl(const string & pattern) {
            this->pattern = pattern;
            hash = get_hash(pattern);
        } 
        
        virtual int find(string text) {
            int hash = get_hash(text.substr(0, pattern.size()));
            int n = text.size() - pattern.size() + 1;
            int m = pattern.size();
            int pow2 = 1;
            for(int i = 1; i < m; i++)
            {
                pow2 = (pow2 << 1) % prime;
            }
            for(int i = 0; i < n; i++)
            {
                if(this->hash == hash)
                {
                    int j;
                    for(j = 0; j < m; j++)
                    {
                        if(text[i+j] != pattern[j])
                            break;
                    }
                    if(j == m)
                    {
                        return i;
                    }
                }
                hash = ((hash - (text[i] * pow2) % prime + prime) << 1) + text[i + m];
                hash %= prime;
            }
            return NOT_FOUND;
        }

        virtual ~KarpRabinImpl() {
        }
};
