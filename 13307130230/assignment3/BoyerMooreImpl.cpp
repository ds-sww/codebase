/**
 * @author tenstep
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
        const int total_char=128;
		vector<int> bad,good,suff;
		
		void get_bad()
		{
			int m=pattern.size();
			bad=vector<int> (total_char);
			for (int i=0;i<total_char;i++) bad[i]=m;
			for (int i=0;i<m;i++) 
				bad[pattern[i]]=m-i-1;
		}
		
		void get_good()
		{
			int l,r;
			int m=pattern.size();
			suff=vector<int> (m);
			suff[m-1]=m;
			l=m-1;
			for (int i=m-2;i>=0;i--)
			{
				if (i>l&&suff[i+m-1-r]<i-l) suff[i]=suff[i+m-1-r];	
				else 
				{
					if (i<l) l=i;
					r=i;
					while (l>=0&&pattern[l]==pattern[l+m-1-r]) l--;
					suff[i]=r-l;
				}
			}
			
			good=vector<int> (m);
			for (int i=0;i<m;i++) good[i]=m;
			for (int i=m-1;i>=-1;i--)			
				if (i==-1||suff[i]==i+1)
				{
					for (int j=0;j<m-1-i;j++)
						if (good[j]==m) good[j]=m-1-i;
				}
			for (int i=0;i<m;i++) good[m-1-suff[i]]=m-1-i;
		}

    public :

        BoyerMooreImpl(string pattern) {
			this->pattern=pattern;
        }

        virtual int find(string text) 
        {
			get_bad();	
			get_good();
			int n=text.size();
			int m=pattern.size();
			int i=0;
			while (i+m-1<n)
			{
				int j;
				for (j=m-1;j>=0;j--)
					if (text[i+j]!=pattern[j]) break;
				if (j<0) return i;
				i+=max(bad[text[i+j]]-(m-j-1),good[j]);
			}
            return NOT_FOUND;
        }

        virtual ~BoyerMooreImpl() {
        }
};

