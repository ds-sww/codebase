/**
 * @author Xuan Yuan
 * @date   2014.10.1
 */
#include<iostream>
#include<string>

#include "Matcher.h"

using namespace std;

class KarpRabinImpl : public Matcher {
    
private :

    string pattern;
    
    int hash(const string & S, int begin, int length) {
        int result = 0;
        for (int i = 0; i < length; i++) {
            result = result * 4 + S[begin + i];
        }
        return result;
    }

public :

    explicit KarpRabinImpl(const string & p) {
        this->pattern = p;
    }
    
    virtual int find(string text) {
        int i, j;
        for (i = 0; i <= text.length()-pattern.length(); i++) {
            if (hash(text, i, pattern.length()) != hash(pattern, 0, pattern.length())) {
                continue;
            }
            for (j = 0; j < pattern.length(); j++) {
                if (text[i+j] != pattern[j]) {
                    break;
                }
            }
            if (j == pattern.length()) {
                return i;
            }
        }
        return NOT_FOUND;
    }
    
    virtual ~KarpRabinImpl() {
        //do nothing...
    }
};
