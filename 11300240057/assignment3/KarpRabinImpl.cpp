/**
 * @author whimsycwd
 * @date   2014.10.1
 */
#include<iostream>
#include<string>

#include "Matcher.h"

using namespace std;

class KarpRabinImpl : public Matcher {
    
    private :

        string pattern;
        
        const static int MOD = 1046527;  // big prime number;
        
        int base;   // 2^(len(pattern) - 1 )
        int hashPattern;

        // the int overflow is same as mod.
        int rehash(int a, int b, int h) {
            int retValue = ((h - a * base)*2 + b) % MOD;
            return retValue < 0 ? retValue + MOD : retValue;
        }    

    public :

        explicit KarpRabinImpl(const string & pattern) {
            this->pattern = pattern;
            int value = 1;
            for (int i = 0; i < pattern.size() -1; ++i) {
                value = value * 2 % MOD;
            }
            base = value;
            
            hashPattern = 0;
            for (int i = 0; i < pattern.size(); ++i) {
                hashPattern = (hashPattern * 2 + pattern[i]) % MOD;
            }
        } 
        
        virtual int find(string text) {
            if (text.size() < pattern.size()) {
                return NOT_FOUND;
            }

            int hash = 0; 
            if (text.size() < pattern.size()) {
                return NOT_FOUND; 
            }

            for (int i = 0; i < pattern.size(); ++i) {
                hash = (hash * 2 + text[i]) % MOD;
            }

            //printf("text : %s\npattern : %s\n", text.c_str(), pattern.c_str());

            for (int i = 0; i < text.size() - pattern.size(); ++i) {
              //  printf("hash : %d, patternHash : %d\n", hash, hashPattern);
                if (hash == hashPattern && text.compare(i, pattern.size(), pattern) == 0) {
                    return i;
                } 
                           
                hash = rehash(text[i], text[i+pattern.size()], hash);
            }
            
            // split to two parts because the `hash = rehash(...)` i+pattern.size() is out of range.
            if (hash == hashPattern && text.compare(text.size() - pattern.size(), pattern.size(), pattern) == 0) {
                return text.size() - pattern.size();
            } 
                
            return NOT_FOUND;
        }

        virtual ~KarpRabinImpl() {
        }
};
