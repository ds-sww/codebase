//  Created by forward on 10/12/14.

#include <string>
#include <vector>
#include <cstring>

#include "Matcher.h"

using namespace std;

class KMPImpl : public Matcher {
    private : 
        string pattern;
        int *lps, n;

    public :
        explicit KMPImpl(const string &pattern) {
            this->pattern = pattern;
            n = pattern.length();
            lps = new int[n];
            computeLPS();
        }

        void computeLPS() //Longest Prefix and Suffix match
        {
            int k = -1;
            lps[0] = -1;
            for (int i = 1; i < n; i++)
            {
                while (k >=0 && pattern[k+1] != pattern[i]) k = lps[k];
                if (pattern[k+1] == pattern[i]) k++;
                lps[i] = k;
            }
        }

        virtual int find(const string &text) {
            int k = -1;
            int m = text.length();
            for (int i = 0; i < m; i++)
            {
                while(k >= 0 && pattern[k+1] != text[i]) k = lps[k];
                if (pattern[k+1] == text[i]) k++;
                if (k == n - 1)
                {
                    return i - n + 1;
                }
            }
            return NOT_FOUND; 
        }

        virtual ~KMPImpl() {
            delete[] lps;
        }
};
