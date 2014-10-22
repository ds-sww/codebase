/**
 * @author whimsycwd
 * @date   2014.10.8
 *
 * help to understand KMP
 */

#include<string>
#include<vector>
#include<iostream>
#include<cstring>

#include "Matcher.h"

using namespace std;

class AutomataImpl : public Matcher {
    private : 
        string pattern;
        const static int CHAR_NUMBER = 26;
       int  (*state)[CHAR_NUMBER];

        // self match
        void preprocess() {
            for (int i = 0; i < pattern.size(); ++i) {
                state[i][pattern[i] - 'a'] = i + 1;
            }
            int cur = 0;
            for (int i = 1; i< pattern.size(); ++i) {
                for (char ch = 'a'; ch<='z'; ++ch) { 
                    if (ch != pattern[i]) {
                        state[i][ch - 'a'] = state[cur][ch - 'a'];
                    }
                }
                cur = state[cur][pattern[i] - 'a'];
            }

            
        }
    public :
        AutomataImpl(string pattern) {
            this->pattern = pattern;
            state = new int[pattern.size()][CHAR_NUMBER];
            
            // !!! WTF?  must initialize 0. or Segment Fault.. Dirty Data.
            memset(state, 0, pattern.size() * CHAR_NUMBER * sizeof(int));

            preprocess();
        }

        virtual int find(string text) {
            if (text.size() < pattern.size()) {
                return NOT_FOUND;
            }
            int cur = 0;
            for (int i = 0; i < text.size(); ++i) {
                cur = state[cur][text[i] - 'a'];
            //    cout << cur << endl;
                if (cur == pattern.size()) {
                    return i - pattern.size() + 1;
                }
            } 
            
            return NOT_FOUND; 
        }

        virtual ~AutomataImpl() {
            delete [] state;
        }
};

