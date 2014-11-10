/**
 * @author qini7
 * @date   2014.10.18
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
		const static int CHARSIZE=26;
		int pattern_size;
    public :

        BoyerMooreImpl(string pattern) {
			this->pattern=pattern;
			pattern_size=pattern.length();
        }
		
		void preBmBc(string _string,int _size,int bmBc[]) {
			for (int i=0;i<CHARSIZE;i++)
				bmBc[i]=_size;
			for (int i=0;i<_size;i++)
				bmBc[_string[i]-'a']=_size-1-i;
		}
		
		void suffixes(string _string,int _size,int *suff) {
			int j;
			suff[_size-1]=_size;
			for (int i=_size-2;i>=0;i--) {
				j=i;
				while (j>=0 && _string[j]==_string[_size-1-(i-j)])
					j--;
				suff[i]=i-j;
			}
		}
		
		void preBmGs(string _string,int _size,int bmGs[]) {
			int j,suff[pattern_size+1];
			suffixes(_string,_size,suff);
			for (int i=0;i<_size;i++)
				bmGs[i]=_size;
			j=0;
			for (int i=_size-1;i>=0;i--)
			if (suff[i]==i+1)
				for (;j<_size-1-i;j++)
					if (bmGs[j]==_size)
						bmGs[j]=_size-1-i;
			for (int i=0;i<=_size-1;i++)
				bmGs[_size-1-suff[i]]=_size-1-i;
		}
		int max(int a,int b) {
			return (a>b ? a : b);
		}
        virtual int find(string text) {
			int i,j,bmGs[pattern_size],bmBc[CHARSIZE];
			int text_size=text.length();
			preBmGs(pattern,pattern_size,bmGs);
			preBmBc(pattern,pattern_size,bmBc);
			j=0;
			while (j<=text_size-pattern_size) {
				for (i=pattern_size-1;i>=0 && pattern[i]==text[i+j];i--);
					if (i<0) return j;
					else j+=max(bmGs[i],bmBc[text[i+j]-'a']-pattern_size+1+i);
			}
            return NOT_FOUND;
        }

        virtual ~BoyerMooreImpl() {
        }
};

