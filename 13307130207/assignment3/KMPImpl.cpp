/**
 * @author chiyahoho
 * @date 2014.10.15
 */

#include<string>
#include<vector>
#include "Matcher.h"
using namespace std;

class KMPImpl : public Matcher {
    private : 
        string pattern;
        vector<int> next;

    public :
        KMPImpl(string pattern) {
            this->pattern=pattern;
        }

        virtual int find(string text) {
            int n=text.length(),m=pattern.length(),j=-1;
            next.push_back(-1);
            for (int i=1;i<m;i++){
                while(j>=0 && pattern[j+1]!=pattern[i]) j=next[j];
                if (pattern[j+1]==pattern[i]) j++;
                next.push_back(j);
            }

            j=-1;
            for (int i=0;i<n;i++){
                while (j>=0 && text[i]!=pattern[j+1]) j=next[j];
                if (text[i]==pattern[j+1]) j++;
                if (j==m-1) return i-j;
            }
            return NOT_FOUND;
        }

        virtual ~KMPImpl() {
        }
};
