#include <iostream>
#include <cstdio>
#include <cstring>

#include "Matcher.h"

using namespace std;
int wasss(int q)
{
	int w=1;
	for(int i=0;i<q;i++)
	{
		w*=2;
	}
	return w;
}

class KarpRabinImpl : public Matcher {
    
    private :

        string pattern;
        

    public :

        explicit KarpRabinImpl(const string & p) {
			pattern=p;
        } 
        
        virtual int find(string text) {
			int a=text.length(),b=pattern.length(),i,m1,m2;
			for(i=0;i<a-b;i++)
			{
				m1=0;
				m2=0;
				for(int j=0;j<b;j++)
				{
					m1+=(wasss(j)*text[j+i]);
					m2+=(wasss(j)*pattern[j]);
				}
				if(m1==m2)
					break;
			}
			if(m1==m2)
				return i;
					
				else return NOT_FOUND;
        }

        virtual ~KarpRabinImpl() {
        }
};

