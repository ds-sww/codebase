/**
 * @author aixile
 * @date   2014.10.13
 */
#include<iostream>
#include<cstdio>
#include<string>

#include "Matcher.h"

using namespace std;
typedef unsigned long long uint64;
const uint64 M=23456789;

class KarpRabinImpl : public Matcher {
    
    private :

        string pattern;
		uint64 hashp,bias;
        

    public :

        explicit KarpRabinImpl(const string & pattern):pattern(pattern){
			hashp=0,bias=1;
			for(int i=0;i<pattern.length();i++){
				hashp*=M;hashp+=pattern[i];
				if(i+1!=pattern.length())	bias*=M;
			}
        } 
        
        virtual int find(string text) {
			if(text.length()>=pattern.length()){
				uint64 hasht=0;
				for(int i=0;i<pattern.length();i++){
					hasht*=M;hasht+=text[i];
				}
				if(hasht==hashp)	return 0;
				for(int i=pattern.length();i<text.length();i++){
					hasht-=bias*text[i-pattern.length()];
					hasht*=M;hasht+=text[i];
					if(hasht==hashp)	return i-pattern.length()+1;
				}
			}
            return NOT_FOUND;
        }

        virtual ~KarpRabinImpl() {
        }
};
