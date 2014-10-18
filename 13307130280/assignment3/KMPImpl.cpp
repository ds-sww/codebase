/**
 * @author qini7
 * @date 2014.10.11
 */


#include<string>
#include<vector>

#include "Matcher.h"

using namespace std;

class KMPImpl : public Matcher {
    private : 
        string pattern;
		int *next;
    public :
        KMPImpl(string pattern) {
        	this->pattern=pattern;
        }

        virtual int find(string text) {
        	int i,j,k;
        	int text_size,pattern_size;
        	text_size=text.length();
        	pattern_size=pattern.length();
        	next=new int [pattern_size+1];
        	next[0]=-1;
        	j=0;k=-1;
        	while (j<pattern_size)
        	{
        		if (k==-1||(pattern[j]==pattern[k]&&pattern[j+1]!=pattern[k+1]))
        		{
        			j++;k++;
        			next[j]=k;
        		}
        		else k=next[k];
        	}
        	i=0;j=0;
        	while (i<text_size)
        	{
        		if (j==-1||text[i]==pattern[j])
        		{
        			i++;j++;
        		}
        		else j=next[j];
        		if (j==pattern_size) return i-pattern_size;
        	}
            return NOT_FOUND; 
        }

        virtual ~KMPImpl() {
        	delete next;
        }
};
