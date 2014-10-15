/**
 * @author Minjun-Li
 * @date   2014.10.11
 */


#include<string>
#include<vector>

#include "Matcher.h"

using namespace std;

class KMPImpl : public Matcher {
    private : 
        string pattern;
        int *next;

        void make_next()
        {
            int n = pattern.size();
            next[0] = -1;
            for(int i = 1; i < n; i++)
            {
                int j = next[i - 1];
                while(j >= 0 && pattern[j + 1] != pattern[i])
                {
                    j = next[j];
                }
                if(pattern[j + 1] == pattern[i])
                {
                    next[i] = j + 1;
                }
                else
                {
                    next[i] = -1;
                }
            }
        }

    public :
        KMPImpl(string pattern) {
            this->pattern = pattern;
            next = new int[pattern.size()];
            make_next();
        }

        virtual int find(string text) {
            int n = text.size();
            int m = pattern.size();
            int i = 0,j = 0;
            while(j < m && i < n)
            {
                if(text[i] == pattern[j])
                {
                    i++;
                    j++;
                }
                else if(j == 0)
                {
                    i++;
                }
                else
                {
                    j = next[j - 1] + 1;
                }
            }
            if(j == m)
            {
                return i - j;
            }
            return NOT_FOUND; 
        }

        virtual ~KMPImpl() {
            delete [] next;
        }
};
