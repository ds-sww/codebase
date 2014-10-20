/**
 * @author qini7
 * @date   2014.10.11
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
        int hash(string _string,int size) {
        	int temp=0;
        	for (int i=0;i<size;i++)
        		temp+=1<<(_string[i]-'a');
        	return temp;
        }
        virtual int find(string text) {
        	int text_size=text.length();
			int pattern_size=pattern.length();
			int has=hash(text,pattern_size),hs=hash(pattern,pattern_size);
			for (int i=0;i<text_size;i++)
			{
				if (has!=hs) {
					if (i+pattern_size<text_size) has=has+(1<<(text[i+pattern_size]-'a'))-(1<<(text[i]-'a'));
					continue;
				}
				int j=0;
				while ((text[i+j]==pattern[j])&&(j<pattern_size))
				{
					j++;
				}
				if (j==pattern_size) return i;
				if (i+pattern_size<text_size) has=has+(1<<(text[i+pattern_size]-'a'))-(1<<(text[i]-'a'));
			}
            return NOT_FOUND;
        }

        virtual ~KarpRabinImpl() {
        }
};
