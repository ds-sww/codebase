/**
 * @author Xuan Yuan
 * @date 2014.10.1
 */


#include<string>

#include "Matcher.h"

using namespace std;

class KMPImpl : public Matcher {
private :
    string pattern;
    
    int* getNext(const string & instr) {
        int length = instr.length();
        int* next;
        next = new int[length];
        next[0] = -1;
        for(int i = 1; i < length; i++) {
            int max = 0;
            for(int j = 1; j < i-1; j++) {
                if(instr.compare(0, j, instr, i-j, j) == 0) {
                    max = j;
                }
            }
            next[i] = max;
        }
        return next;
    }

public :
    KMPImpl(const string & p) {
        this->pattern = p;
    }

    virtual int find(string text) {
        int* next;
        int ne = 0;
        next = getNext(pattern);
        for(int i = 0; i <= text.length() - pattern.length(); ) {
            int j;
            for(j = ne; j < pattern.length(); j++) {
                if(text[i+j] != pattern[j]) {
                    break;
                }
            }
            if(j == pattern.length()) {
                return i;
            }
            i = i + j - next[j];
            if(next[j] == -1) {
                ne = 0;
            } else {
                ne = next[j];
            }
        }
        return NOT_FOUND;
    }

    virtual ~KMPImpl() {
        //do nothing...
    }
};
