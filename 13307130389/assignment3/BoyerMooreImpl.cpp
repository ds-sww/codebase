/**
 * @author whimsycwd
 * @date   2014.10.2
 * bad character shift 和 good suffix shift 都是偏移的必要条件
 */

#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

#include "Matcher.h"

using namespace std;

class BoyerMooreImpl : public Matcher {
    
    private :
        string pattern;
        vector<int> good_suffix , pre ;
        vector<int> last ;
        int bad_char[26] ;
		
		void calBadChar()
		{
			int len = pattern.length() ;
			for( int i = 0 ; i < 26 ; i ++ ) bad_char[i] = len ;
			for( int i = 0 ; i < len ; i ++)
				bad_char[ pattern[i] - 'a' ] = len - i - 1 ;
		}
		void calGoodSuffix()
		{
			int len = pattern.length() ;
			int i , j ;
			i = j = len - 1 ;
			i = j - 1 ;
			for( int k = 0 ; k <= len ; k ++) { last.push_back(len-1) ; pre.push_back(len) ; }
			for( ; i >= 0 ; i -- )
			{
				while( j != len - 1 && pattern[i] != pattern[j] ) j = last[j] ;
				if( pattern[i] == pattern[j] )
				{
					last[i] = last[j] ;
					if( i > 0 ) last[i-1] = -- j ;
				}
			}
			for( i = 0 ; i < len ; i ++ )
				if( last[i] < len - 1 ) pre[ last[i] ] = i ;
			
			for( i = 0 ; i < len ; i ++ )
			{
				if( pre[i] < len ) good_suffix.push_back( len - i - 1 ) ;
				else
				{
					good_suffix.push_back( (len<<1)-i-1 );
					if( len - last[0] - 1 > 0 && len - i - 1 > len - last[0] )
						good_suffix[i] -= len - last[0] ;
				}
			}
			good_suffix[len-1] = 1 ;
		}
		int max( int a , int b ) { return a>b?a:b; }
		
    public :

        BoyerMooreImpl(string pattern) {
			this->pattern = pattern ;
			calBadChar() ;
			calGoodSuffix() ;
        }

        virtual int find(string text)
        {
			int i , j ;
			j = pattern.length() - 1;
			i = 0 ;
			while( i < text.length() )
			{
				while( j >= 0 && text[i+j] == pattern[j] ) j -- ;
				if( j < 0 ) return i ;
				if( text[i + j] != pattern[j] )
				{
					i += max( good_suffix[j] , bad_char[ text[i+j] - 'a' ] ) ;
					j = pattern.length() - 1 ;
				}
			}
            return NOT_FOUND;
        }

        virtual ~BoyerMooreImpl() {
        }
};

