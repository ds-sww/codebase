
#include<iostream>
#include<string>

#include "Matcher.h"
#define LL long long
using namespace std;

class KarpRabinImpl : public Matcher {
    
    private :

        string pattern;
        const static long long mo=1000000007; //10^9+7 big prime;
        const static long long base=999983; //big prime too;      
        int *hash;
        LL MAXMO;
    public :

        explicit KarpRabinImpl(const string & pattern) {
            this->pattern=pattern;
            hash=new int[pattern.size()];
            hash[0]=pattern[0];
            MAXMO=1;
            for (int i=1;i<pattern.size();i++)
            {
                hash[i]=(hash[i-1]*base+(LL)pattern[i]) % mo;
                MAXMO=MAXMO*base % mo;
            }
        } 
        
        virtual int find(string text) {
            if (text.size()<pattern.size()) return NOT_FOUND;
            int nowhash=0;
            for (int i=0;i<pattern.size();i++) nowhash=(nowhash*base+(LL)text[i]) % mo;
            if (nowhash==hash[pattern.size()-1]) return 0;;
            for (int i=1;i<text.size()-pattern.size()+1;i++)
            {
                nowhash=(nowhash-MAXMO*(LL)text[i-1]) % mo;
                if (nowhash<0) nowhash+=mo;
                nowhash=(nowhash*base % mo) % mo;
                nowhash=(nowhash+(LL)text[i+pattern.size()-1]) % mo;
                if (nowhash==hash[pattern.size()-1]) return i;
            }
            return NOT_FOUND;
        }

        virtual ~KarpRabinImpl() {
            delete[]hash;
        }
};
