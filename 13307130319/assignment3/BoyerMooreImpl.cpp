/**
 * @author SiuTo
 * @date   2014.10.24
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
		static const int Maxc=127;

        string pattern;
		int m;
		int *bmBc, *suff, *bmGs;

		void preBmBc()
		{
			bmBc=new int[Maxc];
			for (int i=0; i<Maxc; ++i) bmBc[i]=-1;
			for (int i=0; i<m; ++i) bmBc[(int)pattern[i]]=i;
		}

		void suffixes()
		{
			suff=new int[10000];
			int l=m-1, r=m-2, k;
			suff[m-1]=m;
			for (int i=m-2; i>=0; --i)
				if (suff[m-1-r+i]<i-l+1) suff[i]=suff[m-1-r+i]; else
				{
					for (k=max(i-l+1, 0); i-k>=0 && pattern[m-1-k]==pattern[i-k]; ++k);
					l=i-k+1; r=i;
					suff[i]=k;
				}
		}

		void preBmGs()
		{
			bmGs=new int[10000];
			suffixes();
			int last=-1, j=0;
			for (int i=m-1; i>=0; --i)
			{
				for (; j<m-1-i; ++j)
					if (suff[j]==j+1) last=j;
				bmGs[i]=last;
			}
			for (int i=0; i<m-1; ++i) bmGs[m-1-suff[i]]=i;
		}

    public :

        BoyerMooreImpl(const string &pattern) {
			this->pattern=pattern;
			m=pattern.size();
			preBmBc();
			preBmGs();
        }

        virtual int find(const string &text) const {
			int n=text.size();
			if (n<m) return NOT_FOUND;
			int i, j=0;
			while (j<=n-m)
			{
				for (i=m-1; i>=0 && pattern[i]==text[j+i]; --i);
				if (i<0) return j;
				j+=max(m-1-bmGs[i], i-bmBc[(int)text[j+i]]);
			}
            return NOT_FOUND;
        }

        virtual ~BoyerMooreImpl() {
			delete [] bmBc;
			delete [] suff;
			delete [] bmGs;
        }
};

