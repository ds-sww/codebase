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
        const int ASIZE = 200;
        const int XSIZE = 100;

    public :

        BoyerMooreImpl(string pattern) {
            this->pattern = pattern;
        }

        void prebmBc(string x, int m, int bmBc[]) {
            int i;
            for (i = 0; i < ASIZE; ++i)
                bmBc[i] = m;
            for (i = 0; i < (m-1); ++i)
                bmBc[x[i]] = m - i - 1;
        }

        void suffixes(string x, int m, int *suff) {
            int f,g,i;
            suff[m - 1] = m;
            g = m - 1;
            for (i = m - 2; i >= 0; --i) {
                if(i > g && suff[i + m - 1 - f] < (i - g))
                    suff[i] = suff[i + m - 1 - f];
                else{
                    if (i < g)
                        g = i;
                    f = i;
                    while (g >= 0 && x[g] == x[g + m - 1 - f])
                        --g;
                    suff[i] = f - g;
                }
            }
        }

        void prebmGs(string x, int m, int bmGs[]) {
            int i,j = 0, suff[XSIZE];
            suffixes(x, m, suff);
            for (i = 0; i < m; ++i)
                bmGs[i] = m;
            for (i = m - 1; i >= -1; --i)
                if (i == -1 || suff[i] == i + 1)
                    for (; j < (m - 1 - i); ++j)
                        if (bmGs[j] == m) bmGs[j] = m - 1 - i;
            for (i = 0; i <= (m - 1); ++i)
                bmGs[m - 1 - suff[i]] = m - 1 - i;
        }

        int max (int a, int b) {
            if (a > b) return a;
            else return b;
        }

        virtual int find(string text) {
            if (text.size() < pattern.size())
                return NOT_FOUND;

            int i,j,bmGs[XSIZE],bmBc[ASIZE];
            prebmGs(pattern, pattern.size(), bmGs);
            prebmBc(pattern, pattern.size(), bmBc);

            j = 0;
            while(j <= (text.size() - pattern.size())) {
                for (i = pattern.size() - 1; i >= 0 && pattern[i] == text[i + j]; --i) ;
                if (i < 0) return j;
                else j += max(bmGs[i], bmBc[text[i + j]] - pattern.size() + 1 + i);
            }
            return NOT_FOUND;
        }

        virtual ~BoyerMooreImpl() {
        }
};
