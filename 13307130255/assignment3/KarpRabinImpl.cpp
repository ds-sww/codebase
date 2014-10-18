/**
 * @author whimsycwd
 * @date   2014.10.1
 */
#include<iostream>
#include<string>
#include <memory.h>
#include "Matcher.h"

using namespace std;

class KarpRabinImpl : public Matcher {
    
    private :

        string pattern;
        
        const static int _q = 100000007;
        int rehash(int hash,int old_y,int new_y,int d)
        {
            return ((((hash-(long long)old_y*d % _q) + _q)  << 1) + new_y) % _q;
        }
        bool string_cmp(const string& t,int s,const string& p)
        {
            int n = p.length();
            int i;
            for(i=0;i<n;i++)
            {
                if(p[i] == t[i+s]) i++; else return false;
            }
            return true;
        }
    public :

        explicit KarpRabinImpl(const string & pattern) {
            this->pattern = pattern;
        } 
        
        virtual int find(string &text) {
            int i,d=1,hash_text,hash_pattern;
            int pattern_len = pattern.length();
            int text_len = text.length();
            if(pattern_len>text_len) return NOT_FOUND;
            for(i = 1;i<pattern_len;i++) d=(d<<1) %  _q;
            for(hash_text=hash_pattern=i=0;i<pattern_len;i++)
            {
                hash_text = ((hash_text<<1) + text[i]) % _q;
                hash_pattern = ((hash_pattern << 1) + pattern[i]) % _q;
            }
            for(i=0;i<text_len - pattern_len + 1;i++)
            {
                if(hash_text == hash_pattern && string_cmp(text,i,pattern)) return i;
                hash_text = rehash(hash_text,text[i],text[i+pattern_len],d);
            }
            return NOT_FOUND;
        }

        virtual ~KarpRabinImpl() {
        }
};
