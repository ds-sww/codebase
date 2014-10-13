/**
 * @author whimsycwd
 * @date   2014.10.1
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>

#include "Matcher.h"

using namespace std;

class BruteForceImpl : public Matcher {
    
    private :
        string pattern;


    public :
        explicit BruteForceImpl(const string& _pattern) {
        	pattern = _pattern;
        }

        virtual int find(string text) {
        	int len_pattern = pattern.length();
        	int len_text = text.length();

        	int find_end = len_text - len_pattern + 1;

			for(int i = 0; i < find_end; i++)
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

            return NOT_FOUND;
        }
        
        virtual ~BruteForceImpl() {
            
        }
};



