/*
*	Copyright (C)	Lyq root#lyq.me
*	File Name     : KMPImpl.cpp
*	Creation Time : 2014/10/20 10:39:47
*	Environment   : Ubuntu 14.04-64bit
*	Hompage       : http://www.lyq.me
*/

#include<string>
#include<vector>

#include "Matcher.h"

using namespace std;

class KMPImpl : public Matcher 
{
private:
	string pattern;
	int len_pattern;
	int next[100000];
public:
	void preKMP()
	{
		next[0] = -1;
		int k = -1, j = 0;
		while (j < len_pattern)
		{
			if (k != -1 && pattern[k] != pattern[j])
			{
				k = next[k];
			}
			j++; k++;
			if (pattern[k] == pattern[j])
			{
				next[j] = next[k];
			}else next[j] = k;
		}
		/*
		for (j = 0; j < len_pattern; j++)
		{
			cout << next[j] << endl;
		}
		*/
	}
	KMPImpl(string pattern) 
	{
		this->pattern = pattern;
		len_pattern = pattern.length();
		preKMP();
    }

    virtual int find(string text) 
	{
		int len_text = text.length();
		int i = 0, j = 0;	
		
		while (i < len_pattern && j < len_text)
		{
			if (i == -1 || pattern[i] == text[j])
			{
				i++; j++;
			}else i = next[i];
		}
		if (i >= len_pattern)
		{
			return j-len_pattern;
		}
		else return NOT_FOUND; 
    }

    virtual ~KMPImpl() 
	{
    }
};
