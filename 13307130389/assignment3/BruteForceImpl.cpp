/**
 * @author whimsycwd
 * @date   2014.10.1
 *
 */
// filled by xiaoguai0992 at 2014-10-11
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
        	pattern = _pattern ;
        }

        virtual int find(string text) {
        	int i , j ;
        	for(int i = 0 ; i < text.length() ; i ++)
        	{
        		for(int j = 0 ; j < pattern.length() ; j ++)
        		{
        			if( pattern[j] != text[i+j] ) break;
        			if( pattern[j] == text[i+j] && j == pattern.length() - 1 )
        				return i ;
        		}
        	}
            return NOT_FOUND;
        }
        
        virtual ~BruteForceImpl() {
            
        }
};



