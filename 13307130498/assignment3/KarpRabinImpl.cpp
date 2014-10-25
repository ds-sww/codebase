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
        int pahash,hash;

    public :

        explicit KarpRabinImpl(const string & pattern) {
        	this->pattern = pattern;
        	int i;
        	for(pahash = i = 0; i < pattern.size(); i++){
        		pahash = (pahash << 1) + pattern[i];
        	}
        } 
        
        virtual int find(string text) {
        	int len = pattern.length();
        	int i,j;
        	for(hash = i = 0; i + len - 1] < text.size(); i++){
        		if(i == 0)
        			for(j = 0; j < len; j++)
        				hash = (hash << 1) + pattern[j];
        		else hash = ((hash - (text[i - 1] << len)) << 1) + text[i + len - 1];
        		j = 0;
        		if(hash == pahash)
        			for(;i < pattern.size();j++){
        				if(text[i+j] != pattern[j])break;
        			}
        		if(pattern[j] == '\0')break;
        	}
        	if(pattern[j] == '\0')return i;
            return NOT_FOUND;
        }

        virtual ~KarpRabinImpl() {
        }
};
