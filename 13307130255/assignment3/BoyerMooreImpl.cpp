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
        int * suff,*bmGs;
        const static int ASIZE = 256;
        int bmBc[ASIZE];
        void preBmBc(string& pattern,int bmBc[])
        {
            int len = pattern.length();
            int i;
            for(i=0;i<ASIZE;i++) bmBc[i] = len;
            for(i=0;i<len - 1;i++) bmBc[pattern[i]] = len - i - 1;
        } 
        int * preSuff(string& pattern)
        {
            int len = pattern.length();
            int * suff = new int[len];
            int f,g,i;
            suff[len-1] = len;
            g = len -1;
            for(i=len-2;i>=0;i--)
            {
                if(i>g && suff[(len-1)-(f-i)]<i-g) suff[i] = suff[(len-1)-(f-i)];
                else
                {
                    if(i<g) g = i;
                    f = i;
                    while(g>=0 && pattern[g] == pattern[(len-1)-(f-g)]) g--;
                    suff[i] = f-g;
                }
            }
            return suff;
        }
        int * preBmGs(string& pattern)
        {
            suff = preSuff(pattern);
            int i,j=0,len=pattern.length();
            int * bmGs = new int[len];
            for(i=0;i<len;i++) bmGs[i] = len;
            for(i = len-1;i>=-1;i--)
            {
                if(i==-1||suff[i]==i+1)
                    for(;j<len-1-i;j++)
                        if(bmGs[j]==len) bmGs[j] = len - 1 - i;
            }
            for(i=0;i<len;i++) bmGs[len-1-suff[i]] = len-1-i;
            return bmGs;
        }
        int max(int a,int b)
        {
            return a>b?a:b;
        }
    public :

        explicit BoyerMooreImpl(const string& pattern) {
            this->pattern = pattern;
            preBmBc(this->pattern,bmBc);
            bmGs = preBmGs(this->pattern);
        }

        virtual int find(string& text) {
            int text_len,pattern_len;
            text_len = text.length();
            pattern_len = pattern.length();
            int i,j=0;
            while(j<=text_len - pattern_len)
            {
                for(i=pattern_len-1;i>=0 && pattern[i]==text[i+j];i--);
                if(i==-1) return j;
                else j+=max(bmGs[i],bmBc[text[i+j]] - pattern_len + 1 + i);
            }
            return NOT_FOUND;
        }

        virtual ~BoyerMooreImpl() {
            delete[] suff;
            delete[] bmGs;
        }
};

