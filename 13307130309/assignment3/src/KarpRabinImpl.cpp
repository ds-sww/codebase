/**
 * @author Hermes777
 * @date   2014.10.12
 */
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>

#include "Matcher.h"

using namespace std;

class KarpRabinImpl : public Matcher {
    
    private :

        string pattern;
        long unsigned mod; 
        long unsigned count,count_pos;

    public :

        explicit KarpRabinImpl(const string & pattern) {
        	this->pattern=pattern;
        	mod=9999991;
        	int i=0;
		count=0;
		count_pos=1;
        	for(i=0;i<pattern.length();i++)
			count=((count<<1)%mod+pattern[i])%mod;
		for(i=1;i<pattern.length();i++)
			count_pos=(count_pos<<1)%mod;
        }
        
        virtual int find(string text) {
        	int i;
			long unsigned count_text=0;
        	for(i=0;i<pattern.length();i++)
        	{
			count_text=((count_text<<1)%mod+text[i])%mod;
		}
       		if(count_text==count&&!(text.compare(0,pattern.length(),pattern)))
       			return 0;
        	for(i=pattern.length();i<text.length();i++)
        	{
        		count_text=(((count_text-text[i-pattern.length()]*count_pos%mod+mod)<<1)%mod+text[i])%mod;
        		if(count_text==count&&!(text.compare(i-pattern.length()+1,pattern.length(),pattern)))
        			return i-pattern.length()+1;
		}
            return NOT_FOUND;
        }

        virtual ~KarpRabinImpl() {
        }
};
/*
int main()
{
	string a,b;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	cin >>a;
	cin >>b;
	
	KarpRabinImpl A(b);
	printf("%d",A.find(a));
	return 0;
}
*/
