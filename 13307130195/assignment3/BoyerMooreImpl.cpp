//  Created by forward on 10/12/14.
 

#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

#include "Matcher.h"

using namespace std;


class BoyerMooreImpl : public Matcher {
    
    private :
        string pattern;
        int n;
        int bad_char_shfit[256];
        int *good_suff_shift;
        int *suff;

    public :

        explicit BoyerMooreImpl(const string &pattern) {
            this->pattern = pattern;
            n = pattern.length();
            good_suff_shift = new int[n];
            suff = new int[n];
            computeBadCharShift();
            computeGoodSuffixShift();
        }

        void computeBadCharShift()
        {
            for (int i = 0; i < 256; i++) bad_char_shfit[i] = n;
            for (int i = 0; i < n - 1; i++)
                bad_char_shfit[pattern[i]] = n - i;
        }

        //suff[i] --> longest commmon suffix of pattern[0..i] and pattern[0..n-1]
        void computeSuff() 
        {
            int last_match_fail, last_match_index, j, k;
            suff[n - 1] = n;
            last_match_index = last_match_fail = n - 1;
            for (int i = n - 2; i >= 0; i--)
            {
                if (i > last_match_fail && suff[n - 1 - (last_match_index - i)] < i - last_match_fail)
                    suff[i] = suff[n - 1 - (last_match_index - i)];
                else {
                    j = last_match_fail;
                    if (i < j) j = i;
                    k = i;
                    while (j >= 0 && pattern[j] == pattern[n - 1 - (k - j)]) j--;
                    suff[i] = k - j;
                    last_match_fail = j;
                    last_match_index = k;
                }
            }
        }

        void computeGoodSuffixShift()
        {
            computeSuff();
            for (int i = 0; i < n; i++) good_suff_shift[i] = n;
            int j = 0;
            for (int i = n - 2; i >= 0; i--)
            {
                if (suff[i] == i + 1) //like kmp's lps
                {
                    for (; j < n - i - 1; j++)
                        if (good_suff_shift[j] == n) good_suff_shift[j] = n - i - 1;
                }
            }
            for (int i = 0; i < n - 1; i++)
                good_suff_shift[n - suff[i] - 1] = n - i - 1;
        }


        virtual int find(const string &text) {
            int i = 0, j, m = text.length();

            while(i <= m - n) {
                j = n - 1;
                while (j >= 0 && text[i + j] == pattern[j]) j--;
                if (j < 0) return i;
                else i += max(bad_char_shfit[text[i + j]] - (n - j), good_suff_shift[j]);
            }

            return NOT_FOUND;
        }

        virtual ~BoyerMooreImpl() {
            delete[] good_suff_shift;
            delete[] suff;
        }
};

