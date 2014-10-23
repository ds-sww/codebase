/**
 * @author Minjun-Li
 * @date   2014.10.11
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
        int *delta1;
        int *delta2;
        static const int alphabet_len = 256;

        int is_prefix(int pos)
        {
            int suffix_len = pattern.size() - pos;
            for(int i = 0; i < suffix_len; i++)
            {
                if(pattern[i] != pattern[i + pos])
                {
                    return 0;
                }
            }
            return 1;
        }

        int suffix_length(int pos)
        {
            int m = pattern.size();
            int i = 0;
            while((pattern[pos - i] == pattern[m - 1 - i]) && (i < pos))
            {
                i++;
            }
            return i;
        }

        void make_delta()
        {
            int m = pattern.size();
            delta1 = new int[alphabet_len];
            for(int i = 0; i < alphabet_len ; i++)
            {
                delta1[i] = m;
            }
            for(int i = 0; i < m; i++)
            {
                delta1[pattern[i]] = m - i - 1;
            }

            delta2 = new int[m];
            int last_prefix_index = m - 1;
            for(int j = m - 1; j >= 0; j--)
            {
                if(is_prefix(j))
                {
                    last_prefix_index = j + 1;
                }
                delta2[j] = last_prefix_index + (m - j -1);
            }
            for(int j = 0; j < m - 1; j++)
            {
                int slen = suffix_length(j);
                if(pattern[j - slen] != pattern[m - 1 - slen])
                {
                    delta2[m - 1 - slen] = m - 1 - j + slen;
                }
            }
        }

    public :

        BoyerMooreImpl(string pattern) {
            this->pattern = pattern;
            make_delta();
        }

        virtual int find(string text) {
            int n = text.size();
            int m = pattern.size();

            if(m == 0)
            {
                return -1;
            }

            int i = m - 1;
            while(i < n)
            {
                int j = m - 1;
                while(j >= 0 && (text[i] == pattern[j]))
                {
                    i--;
                    j--;
                }
                if(j < 0)
                {
                    return i + 1;
                }
                i += max(delta1[text[i]], delta2[j]);
            }
            return NOT_FOUND;
        }

        virtual ~BoyerMooreImpl() {
            delete [] delta1;
            delete [] delta2;
        }
};

