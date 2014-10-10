#include<string>
#include<vector>

#include "Matcher.h"

using namespace std;

class KMPImpl : public Matcher {
    private : 
        string pattern;
        vector<int> fail;

        // self match
        void preprocess() {
            fail[0] = -1;
            
            int p1 = 0;
            int p2 = -1;
            
            while (p1 < pattern.size() - 1) {
                while (p2 != -1 && pattern[p1] != pattern[p2]) {
                    p2 = fail[p2];
                }
                ++p1; 
                ++p2;
                if (pattern[p1] == pattern[p2]) {
                    fail[p1] = fail[p2];
                } else {
                    fail[p1] = p2;
                }
            }    
        }
    public :
        KMPImpl(string pattern) {
            this->pattern = pattern;
            fail = vector<int>(pattern.size(), 0);
            preprocess();
        }

        virtual int find(string text) {
            if (text.size() < pattern.size()) {
                return NOT_FOUND;
            }

            int pText = 0;
            int pPattern = 0;

            while (pText < text.size()) {
                while (pPattern !=-1 && text[pText] != pattern[pPattern]) {
                    pPattern = fail[pPattern];
                }
                ++pText;
                ++pPattern;
                
                if (pPattern == pattern.size()) {
                    return pText - pattern.size();
                }
            }
            return NOT_FOUND; 
        }

        virtual ~KMPImpl() {
        }
};
