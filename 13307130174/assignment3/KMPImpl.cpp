/**
 * @author irmo
 * @date 2014.10.28
 */


#include<string>
#include<vector>

#include "Matcher.h"

using namespace std;

class KMPImpl : public Matcher {
    private : 
        string pattern;
        vector <int> next;

    public :
        KMPImpl(string pattern) {
            (*this).pattern = pattern;
            int now = 0;
            next.push_back(0);
            for (int i = 1; i < pattern.size(); i++) {          //i begins from 1, not 0
                while (now && (pattern[i] != pattern[now])) now = next[now - 1];
                if (pattern[now] == pattern[i]) now++;
                next.push_back(now);
            }
        }

        virtual int find(string text) {
            int now = 0;
            for (int i = 0; i < text.size(); i++) {
                while (now && (pattern[now] != text[i])) now = next[now - 1];
                if (pattern[now] == text[i]) {
                    now++;
                    if (now == pattern.size()) return i - pattern.size() + 1;
                }
            }
            return NOT_FOUND;
        }

        virtual ~KMPImpl() {
        }
};
