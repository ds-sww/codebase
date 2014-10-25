/**
 * @author tenstep
 * @date   2014.10.16
 */
#include<iostream>
#include<string>

#include "Matcher.h"

using namespace std;

class KarpRabinImpl : public Matcher {
    
    private :

        string pattern;
        

    public :

        explicit KarpRabinImpl(const string & pattern) {
        	this->pattern=pattern;
        } 
        
        virtual int find(string text) 
        {
        	int n=text.size();
        	int m=pattern.size();
        	if (n<m) return NOT_FOUND;
        	int total_char=128;
        	int mo=1000000007;
        	int left_bit=1;
        	for (int i=0;i<m-1;i++) left_bit=1LL*left_bit*total_char%mo;
        	
        	int hash_pattern=0,hash_text=0;
        	for (int i=0;i<m;i++) 
        		hash_pattern=(1LL*hash_pattern*total_char%mo+pattern[i])%mo;
        	
        	for (int i=0;i<m;i++)
        		hash_text=(1LL*hash_text*total_char+text[i])%mo;
        	
        	for (int i=0;i+m-1<n;i++)
        	{
        		if (hash_text==hash_pattern) 
        		{
        			int j;
        			for (j=0;j<m;j++) if (text[i+j]!=pattern[j]) break;
        			if (j==m) return i;
        		}
        		if (i+m<n)
        			hash_text=((hash_text-1LL*left_bit*text[i]%mo+mo)%mo*1LL*total_char%mo+text[i+m])%mo;
        	}
        	
            return NOT_FOUND;
        }

        virtual ~KarpRabinImpl() {
        }
};
