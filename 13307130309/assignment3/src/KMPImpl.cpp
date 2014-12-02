/**
 * @author Hermes777
 * @date 2014.10.12
 */


#include<string>
#include<vector>
#include<iostream>
#include<cstdio>

#include "Matcher.h"

using namespace std;

class KMPImpl : public Matcher {
    private : 
        string pattern;
        std::vector<int>next;

    public :
        KMPImpl(string pattern) {
        	this->pattern=pattern;
        	int i,j;
			for(i=0;i<pattern.length();i++)
    	    	next.push_back(0);
			next[0]=-1;
			j=-1;
			for(i=1;i<pattern.length();i++)
			{
				while(j>=0&&pattern[j+1]!=pattern[i])
				{
					j=next[j];
				}
				if(pattern[j+1]==pattern[i])
					j++;
				next[i]=j;
			}
        }

        virtual int find(string text) {
        	int i,j=-1;
			for(i=0;i<text.length();i++)
        	{
        		///printf("**  %d %c\n",pattern[j+1],text[i]);
				while(j>=0&&pattern[j+1]!=text[i]) j=next[j];
        		if(pattern[j+1]==text[i])
        		{
					j++;
				} 
				if(j+1==pattern.length())
				{
					return i-pattern.length()+1;
				}
        	}
            return NOT_FOUND; 
        }

        virtual ~KMPImpl() {
        }
};
