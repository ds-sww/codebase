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
        int Hcompare(const string &a,const string &b,int Length){
			int k;
			for(k=0;k<Length;k++)
					return 0;
			if(k==Length)return 1;
		}

    public :

        explicit KarpRabinImpl(const string & pattern) {
			this->pattern=pattern;
        } 
        
        virtual int find(string text) {
			int Lpattern=pattern.length();
			int Ltext=text.length();
			int Thash,Phash,i,d=1;
			for(i=1;i<Lpattern;i++)
				d=d<<1;
			for(Thash=Phash=i=0;i<Lpattern;i++){
				Thash=(Thash<<1)+text[i];
				Phash=(Phash<<1)+pattern[i];
			}
			for(i=0;i<=Ltext-Lpattern;i++){
				if((Thash==Phash)&&(Hcompare(text[i],pattern,Lpattern)==1))
					return i;
				Thash=(Thash-text[i]*d)<<1+text[i+Lpattern];
			}
            return NOT_FOUND;
        }

        virtual ~KarpRabinImpl() {
        }
};
