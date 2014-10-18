/**
 * @author whimsycwd
 * @date 2014.10.1
 */


#include<string>
#include<vector>
#include<memory.h>

#include "Matcher.h"

using namespace std;

class KMPImpl : public Matcher {
    private : 
        string pattern;
        int * next;
        int * GetKmpNext(string & p)
        {
            int len = p.length();
            int i,temp = -1;
            int * next =  new int[len];
            next[0] = -1;
            for(i=1;i<len;i++) next[i] = 0;
            i = 0;
            while(i < len - 1)
            {
                if(temp==-1||p[temp] == p[i])
                {
                    temp++;
                    i++;
                    next[i] = temp;
                }else
                    temp = next[temp];
            }
            return next;
        }

    public :
        explicit KMPImpl(const string &pattern) {
            this->pattern = pattern;
            next  = GetKmpNext(this->pattern);
        }

        virtual int find(string &text) {
            int pattern_len = pattern.length();
            int text_len = text.length();
            int i,j;
            i=j=0;
            while(i<text_len)
            {
                if(j==-1||text[i]==pattern[j])
                {
                    i++;
                    j++;
                }else
                    j = next[j];
                if(j == pattern_len) return i - pattern_len;
            }
            return NOT_FOUND; 
        }

        virtual ~KMPImpl() {
            delete[] next;
        }
};
