/**
 * @author whimsycwd
 * @date 2014.10.1
 */
// filled by xiaoguai0992 at 2014-10-11

#include<string>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<cstdio>

#include "Matcher.h"

using namespace std;

class KMPImpl : public Matcher {
    private : 
        string pattern;
        vector<int> next ;
        
        void findNext()
        {
        	int i , j ;
        	j = 0 ;
        	for( i = 1 ; i < pattern.length() ; i ++)
        	{
        		while( j != 0 && pattern[i] != pattern[j] ) j = next[j] ;
				if( pattern[i] == pattern[j] )
				{
					next[i] = next[j] ;
					next[i+1] = ++ j ;
				}
			}
			
		}
    public :
        KMPImpl(string pattern) {
        	this->pattern = pattern ;
        	for( int i = 0 ; i <= pattern.length() + 1; i ++ ) next.push_back(0);
        	findNext() ;
        }

        virtual int find(string text) {
        	int i , j ;
        	j = 0 ;
        	for( i = 0 ; i < text.length() ; i ++ )
        	{
        		while( j != 0 && pattern[j] != text[i] ) j = next[j] ;
        		if( pattern[j] == text[i] ) j ++ ;
        		if( j == pattern.length() ) return i - j + 1 ;
        	}
            return NOT_FOUND;
        }

        virtual ~KMPImpl() {
        }
};
