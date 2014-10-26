/**
 * @author whimsycwd
 * @date   2014.10.1
 */
#include<iostream>
#include<string>

#include "Matcher.h"
#define rehash(a,b,h) ((((h)-(a)*d)<<1)+(b))
using namespace std;

class KarpRabinImpl : public Matcher {
    
    private :

        string pattern;
        

    public :

        explicit KarpRabinImpl(const string & pattern) {
            this->pattern=pattern;
        } 
        
        int memcmp(string text,string pattern,int p,int m)
        {
            for (int i=0;i<m;i++)
                if (text[i+p]!=pattern[i])
                    return 1;
            return 0;
        }
        virtual int find(string text) {
            int len1=text.size();
            int len2=pattern.size();
            if (len1<len2) return NOT_FOUND;

            long long d,i,j,ht,hp;
            for (d=i=1; i<len2; i++)
                d=d << 1;
            for (hp=ht=i=0;i<len2;i++)
            {
                hp=((hp<<1)+pattern[i]);
                ht=((ht<<1)+text[i]);
            }

            for (j=0; j<=len1-len2; j++)
            {
                if (hp==ht && memcmp(text,pattern,j,len2)==0)
                    return j;
                ht=rehash(text[j],text[j+len2],ht);
            }
            return NOT_FOUND;
        }

        virtual ~KarpRabinImpl() {
        }
};
