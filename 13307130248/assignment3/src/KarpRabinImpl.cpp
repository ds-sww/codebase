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

        int patternHash;

		const static int HASHMOD = 3214567;

    public :

        explicit KarpRabinImpl(const string & pattern) {
        	this -> pattern = pattern;

        	int len = pattern.length();
        	
        	//calculate hash of pattern
        	patternHash = 0;
        	for(int i = 0; i < len; i++)
			{
				//cerr << patternHash << endl;
				patternHash <<= 8;
				patternHash += pattern[i];
				if(patternHash >= HASHMOD)
				{
					patternHash %= HASHMOD;
				}
			}
        } 
        
        virtual int find(string text) {
			int len_text = text.length();
			int len_pattern = pattern.length();
			int find_end = len_text - len_pattern + 1;

			if(len_text < len_pattern) return NOT_FOUND;

			int hash = 0;
			//initialize hash of text
			for(int i = 0; i < len_pattern; i++)
			{
				hash <<= 8;
				hash += text[i];
				if(hash >= HASHMOD)
				{
					hash %= HASHMOD;
				}
			}
			int pwr = 1;
			for(int i = 0; i < len_pattern - 1; i++)
			{
				pwr <<= 8;
				pwr %= HASHMOD;
			}


			for(int i = 0; i < find_end; i++)
			{
				//cerr << patternHash << " " << hash << endl;
				if(hash == patternHash)
				{
					bool equal = true;
					for(int j = 0; j < len_pattern; j++)
					{
						if(pattern[j] != text[i + j])
						{
							equal = false;
							break;
						}
					}
					if(equal)
					{
						return i;
					}
				}

				hash -= text[i] * pwr % HASHMOD;
				if(hash < 0)
				{
					hash += HASHMOD;
				}
				hash <<= 8;
				hash += text[i + len_pattern];
				if(hash >= HASHMOD)
				{
					hash %= HASHMOD;
				}
			}

            return NOT_FOUND;
        }

        virtual ~KarpRabinImpl() {
        }
};
