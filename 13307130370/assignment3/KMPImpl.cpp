#include<string>
#include<vector>
#include<iostream>

#include "Matcher.h"

using namespace std;
void preprocessing(string p, int m,int Next[])
{
	for (int i=0,j=Next[0]=-1;i<m-1;)
	{
		for (;j>-1&&p[i]!=p[j];)
			j=Next[j];
		i++; j++;
		if (p[i] == p[j])
			Next[i]= Next[j];
		else
			Next[i]=j;
	}
}

class KMPImpl : public Matcher {
    private : 
        string pattern;

    public :
        KMPImpl(string p)
		{
			pattern=p;
        }

        virtual int find(string text)
		{
			int m=pattern.length(),n=text.length(),i,j,Next[1025];
			preprocessing(pattern,m, Next);
			for (i=j=0;j<n;)
			{
				if (i==-1 || pattern[i]==text[j])
				{ 
					i++; j++;
				}
				else
					i = Next[i];
				if (i>=m)
					return j-i;
			}
			return NOT_FOUND; 
        }

        virtual ~KMPImpl()
		{
        }
};

