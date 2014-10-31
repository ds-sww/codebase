/**
 * @author irmo
 * @date   2014.10.1
 */
#include<iostream>
#include<string>

#include "Matcher.h"

using namespace std;

class KarpRabinImpl : public Matcher {
    
    private :

        string pattern;
        long long hash (string s) {
            long long ans = 0;
            for (int i = 0; i < pattern.size(); i++) ans = ans + s[i]; //<< i);
            return ans;
        }
    
    public :

        explicit KarpRabinImpl(const string & pattern) {
            (*this).pattern = pattern;
        } 
        
        virtual int find(string text) {
            long long pattern_hash, window_hash;
            pattern_hash = hash(pattern);
            window_hash = hash(text);
            for (int i = 0; i <= text.size() - pattern.size(); i++) {
                if (pattern_hash == window_hash) {
                    for (int j = 0; j < pattern.size(); j++)
                        if (pattern[j] != text[i + j])
                            break;
                        else if  (j == pattern.size() -1) return i;
                }
                if (i == text.size() - pattern.size()) break;
                window_hash = window_hash - text[i] + text[i+pattern.size()];
                /*window_hash = window_hash - text[i];
                window_hash = window_hash >> 2;
                window_hash = window_hash + (text[i + pattern.size()] << (pattern.size() - 1));
                 */
            }
            return NOT_FOUND;
        }
    

        virtual ~KarpRabinImpl() {
        }
};
