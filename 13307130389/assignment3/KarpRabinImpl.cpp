/**
 * @author whimsycwd
 * @date   2014.10.1
 */
//filled by xiaoguai0992 at 2014-10-11
#include<iostream>
#include<string>

#include "Matcher.h"

#ifdef WINDOS
	#define LL __int64
#else
	#define LL long long
#endif

using namespace std;

class KarpRabinImpl : public Matcher {
    
    private :

        string pattern;
        unsigned pattern_hash , text_hash ;
        
        unsigned LL hash(const string & str , int len )
        {
			unsigned LL hash_res = 0 ;
			for( int i = 0 ; i < len ;  i ++)
				hash_res += str[i] << (str[i]-96) ;
			return hash_res ;
		}
		
    public :

        explicit KarpRabinImpl(const string & _pattern) {
        	pattern = _pattern ;
        	pattern_hash = hash( pattern , pattern.length() ) ;
        	
        } 
        
        virtual int find(string text) {
        	int i , j ;
        	for( i = 0 ; i < text.length() - pattern.length() + 1; i ++)
        	{
        		if( i == 0 ) text_hash = hash( text , pattern.length() ) ;
        		else
        		{ 
        			text_hash -= text[i-1] << (text[i-1]-96) ;
        			text_hash += text[i+pattern.length()-1]<<(text[i+pattern.length()-1]-96); ;
        		}
        		if( text_hash == pattern_hash)
        		{
        			for( j = 0 ; j < pattern.length() ; j ++ )
        				if( pattern[j] != text[i+j] ) break ;
        			if( j == pattern.length() ) return i ;
        		}
        	}
        	
            return NOT_FOUND;
        }

        virtual ~KarpRabinImpl() {
        }
};
